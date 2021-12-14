# 42 Philosophers


<strong>Overview</strong>

The goal of this project is to solve the [dining philosophers problem](https://en.wikipedia.org/wiki/Dining_philosophers_problem) by using [multi-threading](https://www.geeksforgeeks.org/multithreading-c-2/).

[Subject PDF](https://github.com/williamollio/philosophers/tree/master/subject)

# Grade
![wollio's 42Project Score](https://badge42.herokuapp.com/api/project/wollio/Philosophers)
# About
Each philosophers are represented by threads and are using shared memory which are the forks. In order to avoid anyconflicts regarding accessto to this common ressource, [mutexes](https://www.thegeekstuff.com/2012/05c-mutex-examples/) are used. Mutexes provide mutual exclusion over shared resources, as they can be locked andunlocked.
Locking a ressource allows to deny access to it to other threads at the same time. Thus this could avoid [data races](https://docs.oracle.com/cd/E19205-01/820-0619/geojs/index.html) but could create [deadlocks](https://docs.oracle.com/cd/E19205-01/820-0619/geokj/index.html).

# Explanations

The program should take the following arguments: number_of_philosophers time_to_die
time_to_eat time_to_sleep [number_of_times_each_philosopher_must_eat]

* <strong>number_of_philosophers</strong>: is the number of philosophers and also the number of forks.
* <strong>time_to_die</strong>: is in milliseconds, if a philosopher doesn’t start eating ’time_to_die’ milliseconds after starting their last meal or the beginning of the simulation,
it dies.
 time_to_eat: is in milliseconds and is the time it takes for a philosopher to eat. During that time they will need to keep the two forks.
* <strong>time_to_sleep</strong>: is in milliseconds and is the time the philosopher will spend sleeping.
* <strong>number_of_times_each_philosopher_must_eat</strong>: argument is optional, if all philosophers eat at least ’number_of_times_each_philosopher_must_eat’ the simulation will stop. If not specified, the simulation will stop only at the death of a philosopher.

# Clone
Open a terminal and run following command:
```
git clone <repository url>
```
# How to use

Go to the created repository and run following command:
```
make
```
To start run the following command (the last argument is optionnal):
```
./philo number_of_philosophers time_to_die time_to_eat time_to_sleep time_to_eat
```

Some test cases are provided as well as the expected behavior in [`test.txt`](test.txt)

Hit CTRL + C to kill the process
