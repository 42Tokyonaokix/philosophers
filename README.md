*This project has been created as part of the 42 curriculum by .*

# 1.Description

This project is a simulation program that solves the classical "dining philosophers" problem using multi-threaded programming. Each philosopher is represented as a thread, and they repeatedly cycle through "eating," "sleeping," and "thinking" while competing for the shared resource, the fork (mutex).

# 2.Technical Chices

## 2.1 Data Structure Design

### 2.1.1 t\_system

To maintain read-only rules shared across the entire simulation and global resources shared between threads.

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

### 2.1.2 t\_philo

To maintain the unique data of each philosopher and references to the resources they use.

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

### 2.1.2 t\_philo

To maintain the unique data of each philosopher and references to the resources they use.

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

### 2.1.2 t\_philo

To maintain the unique data of each philosopher and references to the resources they use.

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

## 2.2 Strategies for Synchronization and Parallel Processing

### 2.2.1 Data Race Prevention (Data Race Prevention)

To prevent the "monitor thread (reading)" and "dining thread (writing)" from accessing last\_meal\_time simultaneously, the state\_mutex held by each philosopher is used. Additionally, dead\_mutex is used for updating and checking the death flag, and print\_mutex is used to prevent confusion in log output.

### 2.2.2 Deadlock Avoidance

To prevent everyone from freezing at the same time with one fork, either slightly delay the start time of philosophers with even numbers using usleep, or reverse the order of taking the left and right forks in an even-odd manner.

## 2.3 Time Management and Monitoring

### 2.3.1 accurate waiting

To minimize delays due to OS scheduling, create a high-precision sleep function using gettimeofday. Continuously check the current time while repeatedly using short usleep until the target time is reached.

#### 2.3.2 Monitoring Logic

Main thread iterates through all philosophers and checks the following conditions: Evaluation criteria: (current time - last\_meal\_time) >= time\_to\_die If the condition is true, it sets the death flag and notifies all threads to stop.

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

#### 2.3 2.3.3 Optimal Waiting Time (thinking.c)

This algo defines the two different sleep time.

The one is "eat\_time - sleep\_time". It is the basic think\_time which can make eat\_time = sleep\_time + think\_time. So it enables philos to gain eat-and-rest cycles. this cycles sync odds and evens because of the sharing forks with next ones.

The other is "eat\_time \* 2 - sleep\_time". When number of philos are odd, the first way has a problem. The last philo cant have a fork because the next one is also has odd id. this irregular think\_time happens number-of-philos a time. its because every time needs one rest person.

its the time schedule example when ./philo 7 300 90 90

| 1 | 2 | 3 | 4 | 5 | 6 | 7 |
| --- | --- | --- | --- | --- | --- | --- |
| eat | t&s | eat | t&s | eat | t&s | t&s |
| t&s | eat | t&s | eat | t&s | eat | t&s |
| t&s | t&s | eat | t&s | eat | t&s | eat |
| eat | t&s | t&s | eat | t&s | eat | t&s |
| t&s | eat | t&s | t&s | eat | t&s | eat |

# 3.Instructions

### Compilation

This project includes `Makefile` . To compile the source code, run the following command in the root directory of the repository:

```bash

make

```

After the compilation is complete, the generated philo\_simulation file will be executed with the following arguments.

```bash

./philo <number_of_philoophers> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_times_each_philoopher_must_eat]

```


    number\_of\_philosophers: The number of philosophers (= the number of forks on the table).
    
*   time\_to\_die (milliseconds): The lifespan. If a philosopher does not start the next meal after the specified time has elapsed since the last meal start time or the start of the simulation, that philosopher will die of starvation.
    
*    time\_to\_eat (milliseconds): the time it takes to eat. During this time, the philosopher keeps holding two forks.
    
*   time\_to\_sleep (milliseconds): the time it takes to sleep.
    
*   \[number\_of\_times\_each\_philosopher\_must\_eat\] (optional): the simulation ends if all philosophers have finished eating at least this many times. if not specified, the simulation continues until someone dies.