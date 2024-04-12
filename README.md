# Philospher
### Dining Philosophers Problem
The Dining Philosophers problem is a classic concurrency problem often used to illustrate synchronization issues and techniques in computer science. The problem consists of a group of philosophers seated around a table, with a bowl of spaghetti at the center of the table. Each philosopher spends their time thinking and eating.

### Language : ![C language](https://img.shields.io/badge/C-00599C?style=for-the-badge&logo=c&logoColor=white)

### Overview
The Philosopher project at 42 is an implementation of the Dining Philosophers problem in a multithreaded environment. The goal is to develop a solution that prevents deadlock and starvation while ensuring that each philosopher can eat when they are hungry.

### Features
Multithreaded implementation: The project uses threads to simulate the philosophers and their actions of thinking and eating concurrently.
Synchronization mechanisms: Various synchronization techniques, such as mutexes or semaphores, are used to control access to shared resources (e.g., the forks on the table) and prevent race conditions.
Deadlock and starvation prevention: The solution must prevent situations where philosophers are deadlocked (unable to proceed due to resource contention) or starved (unable to eat indefinitely).

### Usage
#### Compilation
To compile the Philosopher program, run the following command:
```shell
make
```

#### Execution
To execute the Philosopher program, run the following command:

```shell
./philo [number_of_philosophers] [time_to_die] [time_to_eat] [time_to_sleep] [number_of_times_each_philosopher_must_eat]
```
* [number_of_philosophers] is the number of philosophers.
* [time_to_die] is the time that a philospher take to die.
* [time_to_eat] is the time that a philospher take to eat.
* [time_to_sleep] is the time that a philospher taker to sleep.
* [number_of_times_each_philosopher_must_eat] is the number of time each philosopher will eat before stop the processus. (optionnal)

