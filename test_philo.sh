#!/usr/bin/env bash
# test_philo.sh — philosophers integration test runner
# Run from the project root (parent of philo/).
#
# usage:
#   ./test_philo.sh            # run all sections
#   ./test_philo.sh invalid    # only invalid-input tests
#   ./test_philo.sh die        # only "should die" tests
#   ./test_philo.sh must_eat   # only "must eat N meals" tests
#   ./test_philo.sh survive    # only "no death within N seconds" tests

set -u

PHILO_BIN="./philo/philo"

RED=$'\033[0;31m'
GREEN=$'\033[0;32m'
YELLOW=$'\033[1;33m'
BLUE=$'\033[0;34m'
NC=$'\033[0m'

PASS=0
FAIL=0
FAILED_NAMES=()

# ----- prerequisites --------------------------------------------------------

if command -v gtimeout >/dev/null 2>&1; then
    TIMEOUT_CMD="gtimeout"
elif command -v timeout >/dev/null 2>&1; then
    TIMEOUT_CMD="timeout"
else
    echo "ERROR: neither 'timeout' nor 'gtimeout' was found in PATH."
    echo "On macOS:  brew install coreutils"
    exit 1
fi

if [ ! -x "$PHILO_BIN" ]; then
    echo "ERROR: $PHILO_BIN not found or not executable."
    echo "Run 'make -C philo' first."
    exit 1
fi

# ----- helpers --------------------------------------------------------------

pass() {
    PASS=$((PASS + 1))
    printf "  %sPASS%s  %s\n" "$GREEN" "$NC" "$1"
}

fail() {
    FAIL=$((FAIL + 1))
    FAILED_NAMES+=("$1")
    printf "  %sFAIL%s  %s\n" "$RED" "$NC" "$1"
    if [ -n "${2:-}" ]; then
        printf "        %s%s%s\n" "$YELLOW" "$2" "$NC"
    fi
}

section() {
    printf "\n%s== %s ==%s\n" "$BLUE" "$1" "$NC"
}

# ----- section 1: invalid input --------------------------------------------
# Spec: argc must be 5 or 6, all positive integers.
# Note: the subject says must_eat_count = 0 is *valid* (simulation should stop
# immediately), so it lives in the must_eat section, not here.

test_invalid() {
    section "invalid input  (program must reject — non-zero exit OR error message)"

    invalid_case() {
        local name="$1"; shift
        local out rc
        out=$("$PHILO_BIN" "$@" 2>&1)
        rc=$?
        if [ "$rc" -ne 0 ] || echo "$out" | grep -qiE "invalid|error|fatal|usage"; then
            pass "$name"
        else
            fail "$name" "exit=$rc, out='$out'"
        fi
    }

    invalid_case "no args"
    invalid_case "1 arg"               5
    invalid_case "2 args"              5 800
    invalid_case "3 args"              5 800 200
    invalid_case "7 args"              5 800 200 200 5 5
    invalid_case "0 philosophers"      0 800 200 200
    invalid_case "negative philo"      -5 800 200 200
    invalid_case "negative die"        5 -800 200 200
    invalid_case "negative eat"        5 800 -200 200
    invalid_case "negative sleep"      5 800 200 -200
    invalid_case "negative meals"      5 800 200 200 -3
    invalid_case "non-numeric philo"   abc 800 200 200
    invalid_case "trailing letters"    5a 800 200 200
    invalid_case "float arg"           5.5 800 200 200
    invalid_case "empty string arg"    "" 800 200 200
    invalid_case "spaces only"         "   " 800 200 200
    invalid_case "INT_MAX overflow"    99999999999 800 200 200
}

# ----- section 2: should die -----------------------------------------------
# Each case must print "died" within the timeout.

test_die() {
    section "should die  (must print 'died' before timeout)"

    die_case() {
        local name="$1" tmo="$2"; shift 2
        local out rc
        out=$($TIMEOUT_CMD "${tmo}s" "$PHILO_BIN" "$@" 2>&1)
        rc=$?
        if echo "$out" | grep -qE "died"; then
            pass "$name"
        elif [ "$rc" -eq 124 ]; then
            fail "$name" "timed out (${tmo}s) without 'died'"
        else
            fail "$name" "no 'died' in output (exit=$rc)"
        fi
    }

    # 1 philosopher only has 1 fork → can never eat → must die.
    die_case "1 philo (single fork)"        3   1 800 200 200

    # time_to_eat > time_to_die — dies during the very first meal.
    die_case "eat > die  (4 200 205 200)"   3   4 200 205 200

    # Tight cycle: pair scheduling can't keep everyone alive.
    die_case "tight     (4 310 200 100)"    3   4 310 200 100

    # Two philosophers, very small die window.
    die_case "2 philos cramped (2 100 60 60)" 3   2 100 60 60

    # Five philosophers, die window smaller than one full cycle.
    die_case "die smaller than cycle (5 150 100 100)" 3   5 150 100 100
}

# ----- section 3: must eat N meals -----------------------------------------
# No philosopher dies AND program exits cleanly within the timeout.

test_must_eat() {
    section "must eat N meals  (no death, clean exit before timeout)"

    must_eat_case() {
        local name="$1" tmo="$2"; shift 2
        local out rc
        out=$($TIMEOUT_CMD "${tmo}s" "$PHILO_BIN" "$@" 2>&1)
        rc=$?
        if echo "$out" | grep -qE "died"; then
            fail "$name" "philosopher died: $(echo "$out" | grep died | head -1)"
        elif [ "$rc" -eq 124 ]; then
            fail "$name" "timed out after ${tmo}s — likely deadlock or scheduling stall"
        elif [ "$rc" -ne 0 ]; then
            fail "$name" "non-zero exit ($rc), out tail: $(echo "$out" | tail -1)"
        else
            pass "$name"
        fi
    }

    # Per spec: must_eat_count = 0 → simulation stops immediately.
    must_eat_case "5 philos × 0 meals (instant exit)"  3   5 800 200 200 0

    must_eat_case "4 philos × 10 meals (loose)"        15  4 800 200 200 10
    must_eat_case "5 philos × 7 meals"                 15  5 800 200 200 7
    must_eat_case "4 philos × 5 meals  (tight 410)"    10  4 410 200 200 5
    must_eat_case "5 philos × 5 meals  (tight 610)"    15  5 610 200 200 5
    must_eat_case "200 philos × 3 meals"               30  200 800 200 200 3
}

# ----- section 4: survive (bonus) ------------------------------------------
# No must_eat: must run for N seconds without anyone dying.

test_survive() {
    section "survive  (no death within window, no must_eat)"

    survive_case() {
        local name="$1" secs="$2"; shift 2
        local out rc
        out=$($TIMEOUT_CMD "${secs}s" "$PHILO_BIN" "$@" 2>&1)
        rc=$?
        if echo "$out" | grep -qE "died"; then
            fail "$name" "philosopher died within ${secs}s"
        elif [ "$rc" -ne 124 ]; then
            fail "$name" "program exited (rc=$rc) before timeout — should run forever"
        else
            pass "$name (no death in ${secs}s)"
        fi
    }

    survive_case "5/800/200/200"    5   5 800 200 200
    survive_case "4/410/200/200"    5   4 410 200 200
    survive_case "200/800/200/200"  8   200 800 200 200
}

# ----- main ----------------------------------------------------------------

SECTION="${1:-all}"
case "$SECTION" in
    invalid)  test_invalid ;;
    die)      test_die ;;
    must_eat) test_must_eat ;;
    survive)  test_survive ;;
    all)
        test_invalid
        test_die
        test_must_eat
        test_survive
        ;;
    -h|--help)
        sed -n '2,11p' "$0"
        exit 0
        ;;
    *)
        echo "unknown section: $SECTION"
        sed -n '2,11p' "$0"
        exit 1
        ;;
esac

printf "\n%s== summary ==%s\n" "$BLUE" "$NC"
printf "  %spassed%s : %d\n" "$GREEN" "$NC" "$PASS"
printf "  %sfailed%s : %d\n" "$RED"   "$NC" "$FAIL"
if [ "$FAIL" -ne 0 ]; then
    printf "\n%sfailing tests:%s\n" "$YELLOW" "$NC"
    for name in "${FAILED_NAMES[@]}"; do
        printf "  - %s\n" "$name"
    done
    exit 1
fi
exit 0
