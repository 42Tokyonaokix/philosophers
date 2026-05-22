*This project has been created as part of the 42 curriculum by .*

# 1.Description

This project is a simulation program that solves the classical "dining philosophers" problem using multi-threaded programming. Each philosopher is represented as a thread, and they repeatedly cycle through "eating," "sleeping," and "thinking" while competing for the shared resource, the fork (mutex).

# 2.Technical Chices

## 2.1 Data Structure Design

### 2.1.1 t_system

To maintain read-only rules shared across the entire simulation and global resources shared between threads.

```c
# include <pthread.h>
This project implements a multithreaded simulation of the classical "dining philosophers" problem as part of the 42 curriculum.

# Description

Each philosopher is represented by a thread that cycles through eating, sleeping, and thinking while competing for forks (mutexes).

# Technical Choices

## Data structures

Brief summaries of the two primary structs used by the program (see `philo/includes/philo.h` for the definitive definitions):

- `t_system`: global simulation parameters and shared resources (fork mutex array, print mutex, death/state mutexes, timestamps, etc.).
- `t_philo`: per-philosopher state (id, last meal time, meals eaten, left/right fork pointers, per-philosopher mutex, back-reference to `t_system`).

## Synchronization and deadlock avoidance

- Per-philosopher mutexes protect `last_meal_time` and related state from concurrent monitor and philosopher threads.
- A global print mutex serializes console output.
- Deadlock avoidance is achieved by ordering fork acquisition or slightly staggering philosopher start times (even/odd parity), depending on runtime conditions.

## Timing

- Uses `gettimeofday` to implement millisecond-precision time tracking and a short-loop `usleep` based wait to implement accurate sleeps.
- A monitor thread periodically checks `current_time - last_meal_time >= time_to_die` to detect deaths and stop the simulation.

# Compilation and usage

To build the program, run in the project root:

```bash
make
```

This produces the binary named `philo` (see `philo/Makefile`). Run it as:

```bash
./philo <number_of_philosophers> <time_to_die_ms> <time_to_eat_ms> <time_to_sleep_ms> [number_of_times_each_philosopher_must_eat]
```

Arguments:

- `number_of_philosophers`: number of philosophers (and forks).
- `time_to_die_ms`: milliseconds a philosopher may go without starting to eat before dying.
- `time_to_eat_ms`: duration of the eating action (forks held during this time).
- `time_to_sleep_ms`: duration of the sleeping action.
- `number_of_times_each_philosopher_must_eat` (optional): if provided, the simulation ends when every philosopher has eaten at least this many times; otherwise it runs until a philosopher dies.

# Notes and known issues

- This README is a companion summary; the authoritative behavior and types are defined in `philo/includes/philo.h` and implemented under `philo/srcs/`.
- If you want a checklist to compare against the subject PDF (required behavior, output format, edge cases), please upload `philosophers.pdf` and I will perform a line-by-line compliance review.

# References

- POSIX threads man pages (`pthread_create`, `pthread_mutex_lock`, etc.)
- `gettimeofday` / `usleep`
- Dining Philosophers — https://en.wikipedia.org/wiki/Dining_philosophers_problem

# AI usage

This project used AI as an assistant under the author's review: learning, code review, and writing assistance phases were involved. The author verified and accepted all changes made with AI help.
 pthread_mutex_t *right_fork;
