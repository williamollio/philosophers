#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "./libft/libft.h"
#include <sys/time.h>



/* table
number_of_philosophers
time_to_die
time_to_eat
time_to_sleep
pthread_mutex_t *FORKS; --> FORKS = malloc(numphil * sizeof(pthread_mutex_t));
[number_of_times_each_philosopher_must_eat]
*/

// write the informations into a buffer before to print it and then use the write function

// argv into one struct
// struct

typedef struct	s_struct
{
	pthread_t	thread;
	int			id;
	t_table     *table
	pthread_mutex_t *right_fork;
	pthread_mutex_t *left_fork;
}				t_struct;

//pick up forks
// eat
// sleep
// think