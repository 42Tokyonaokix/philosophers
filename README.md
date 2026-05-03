*This project has been created as part of the 42 curriculum by <natakaha>.*

# 1.Description
本プロジェクトは、古典的な「食事する哲学者」の問題をマルチスレッドプログラ
ミングを用いて解決するシミュレーションプログラムである。各哲学者はスレッド
として表現され、共有リソースであるフォーク(ミューテックス)を奪い合いなが
ら「食べる」「寝る」「考える」のサイクルを繰り返す。


# 2.Technical Chices

## 2.1 Data Structure Design

### 2.1.1 t_system

シミュレーション全体で共有される読み取り専用のルールと、スレッド間で共有さ
れるグローバルなリソースを保持する。

```c
# include <pthread.h>

typedef struct s_system {
 int num_philos;
 long time_to_die;
 long time_to_eat;
 long time_to_sleep;
 int must_eat_count;
 pthread_mutex_t *forks;
 pthread_mutex_t *print_mutex;
 pthread_mutex_t *dead_mutex;
 int philos_state;
}	t_system;

```

### 2.1.2 t_philo

各哲学者の固有データと、自分が使用するリソースへの参照を保持する。

```c

typedef struct s_philo {
 int id;
 long last_meal_time;
 int meals_eaten;
 pthread_mutex_t *left_fork;
 pthread_mutex_t *right_fork;
 pthread_mutex_t state_mutex;
 t_system *system;
} t_philo;

```

### 2.1.2 t_philo

各哲学者の固有データと、自分が使用するリソースへの参照を保持する。

```c

typedef struct s_philo {
 int id;
 long last_meal_time;
 int meals_eaten;
 pthread_mutex_t *left_fork;
 pthread_mutex_t *right_fork;
 pthread_mutex_t state_mutex;
 t_system *system;
} t_philo;

```

##

### 2.1.2 t_philo

各哲学者の固有データと、自分が使用するリソースへの参照を保持する。

```c

typedef struct s_philo {
 int id;
 long last_meal_time;
 int meals_eaten;
 pthread_mutex_t *left_fork;
 pthread_mutex_t *right_fork;
 pthread_mutex_t state_mutex;
 t_system *system;
} t_philo;

```

## 2.2 同期と並列処理の戦略

### 2.2.1 データレース対策 (Data Race Prevention)

「監視スレッド（読み取り）」と「食事スレッド（書き込み）」が同時に
last_meal_time にアクセスすることを防ぐため、各哲学者が持つ state_mutex
を使用する。また、死亡フラグの更新・確認には dead_mutex を、ログ出力の乱れ
を防ぐには print_mutex を使用する。

### 2.2.2 デッドロック回避 (Deadlock Avoidance)

対称性を崩すため、偶数番号の哲学者の開始時間を usleep でわずかに遅らせる、
または左右のフォークを取る順番を偶数・奇数で逆にすることで、全員が一斉に片
方のフォークを持って固まることを防ぐ。

## 2.3 時間管理と監視

### 2.3.1 正確な待機 (ft_usleep)

OSのスケジュールによる遅延を最小限にするため、gettimeofday を使用した高
精度なルー待機関数を自作する。短い usleep を繰り返しながら、目標時刻まで
現在時刻を確認し続ける。

#### 2.3.2 監視ロジック (Monitoring)

メインスレッドが全哲学者を巡回し、以下の条件を確認する：
判定条件： (現在時刻 - last_meal_time) >= time_to_die
条件が真となった場合、死亡フラグを立てて全スレッドに停止を通知する。

```c

typedef struct s_philo {
 int id;
 long last_meal_time;
 int meals_eaten;
 pthread_mutex_t *left_fork;
 pthread_mutex_t *right_fork;
 pthread_mutex_t state_mutex;
 t_system *system;
} t_philo;

```

## 2.2 同期と並列処理の戦略

### 2.2.1 データレース対策 (Data Race Prevention)
「監視スレッド（読み取り）」と「食事スレッド（書き込み）」が同時に
last_meal_time にアクセスすることを防ぐため、各哲学者が持つ state_mutex
を使用する。また、死亡フラグの更新・確認には dead_mutex を、ログ出力の乱れ
を防ぐには print_mutex を使用する。

### 2.2.2 デッドロック回避 (Deadlock Avoidance)
対称性を崩すため、偶数番号の哲学者の開始時間を usleep でわずかに遅らせる、
または左右のフォークを取る順番を偶数・奇数で逆にすることで、全員が一斉に片
方のフォークを持って固まることを防ぐ。

## 2.3 時間管理と監視

### 2.3.1 正確な待機 (ft_usleep)
OSのスケジュールによる遅延を最小限にするため、gettimeofday を使用した高
精度なループ待機関数を自作する。短い usleep を繰り返しながら、目標時刻まで
現在時刻を確認し続ける。

#### 2.3.2 監視ロジック (Monitoring)
メインスレッドが全哲学者を巡回し、以下の条件を確認する：
判定条件： (現在時刻 - last_meal_time) >= time_to_die
条件が真となった場合、死亡フラグを立てて全スレッドに停止を通知する。

# 3.Instructions

### Compilation

本プロジェクトには `Makefile` が含まれています。ソースコードをコンパイルするには、リポジトリのルートディレクトリで以下のコマンドを実行してください：

```bash

make

```

コンパイル完了後、生成されたphilo事項ファイルを以下の引数とともに実行します。

```bash

./philo <number_of_philoophers> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_times_each_philoopher_must_eat]

```

- number_of_philoophers: 哲学者の数（＝テーブルにあるフォークの数）。

- time_to_die (ミリ秒): 寿命。前回の食事開始時、またはシミュレーション開始時からこの時間が経過しても次の食事が始まらない場合、その哲学者は餓死します。

- time_to_eat (ミリ秒): 食事にかかる時間。この間、哲学者は2本のフォークを保持し続けます。

- time_to_sleep (ミリ秒): 睡眠にかかる時間。

- [number_of_times_each_philoopher_must_eat] (オプション): 全哲学者がこの指定回数以上食事を終えた場合、シミュレーションが終了します。指定されない場合、誰かが死ぬまでシミュレーションは続きます。

