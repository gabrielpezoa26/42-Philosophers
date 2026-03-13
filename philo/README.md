# Philosophers

This is my implementation of the Philosophers project for the 42 curriculum. It's a simulation of the classic dining philosophers problem using POSIX threads and mutexes in C.

## Overview

The project simulates philosophers sitting around a table with a bowl of spaghetti in the middle. They alternate between eating, sleeping, and thinking. 
- There is one fork per philosopher on the table.
- A philosopher needs two forks to eat.
- To prevent deadlocks and data races, access to the forks (and shared states) is protected using mutexes.
- If a philosopher starves, the simulation stops.

## Compiling

Clone the repository and run `make` inside the `philo` directory to build the executable.

```bash
cd philo
make
```

This compiles the source files into the `philo` executable.

Other available `make` commands:
- `make clean`: Removes object files.
- `make fclean`: Removes object files and the executable.
- `make re`: Recompiles everything from scratch.

## Usage

Run the program with the following arguments:

```bash
./philo <number_of_philosophers> <time_to_die> <time_to_eat> <time_to_sleep> [number_of_times_each_philosopher_must_eat]
```

- `number_of_philosophers`: The number of philosophers and forks.
- `time_to_die`: Time in milliseconds. If a philosopher hasn't started eating `time_to_die` ms after their last meal started (or since the beginning of the simulation), they die.
- `time_to_eat`: Time in milliseconds it takes for a philosopher to eat.
- `time_to_sleep`: Time in milliseconds a philosopher spends sleeping.
- `[number_of_times_each_philosopher_must_eat]`: (Optional) The simulation stops if all philosophers have eaten at least this many times. If left empty, the simulation runs until someone dies.

### Example

To test a scenario where no philosopher should die:
```bash
./philo 5 800 200 200
```

To test a scenario where the simulation stops after each philosopher eats 3 times:
```bash
./philo 3 100 100 100 3
```

## Logs

The program prints the state changes of the philosophers to the standard output. The format looks like this:

```text
timestamp_in_ms X has taken a fork
timestamp_in_ms X is eating
timestamp_in_ms X is sleeping
timestamp_in_ms X is thinking
timestamp_in_ms X died
```
*(Where `X` is the philosopher's ID from 1 to `number_of_philosophers`)*. The logs are protected by a mutex so that they don't get mixed up when printed by different threads.