#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "../libft/libft.h"
#include <sys/time.h>

// ./philosophers 5 800 200 200

typedef struct	s_table
{
	int	nbr; // number_of_philosophers
	int	die; // time_to_die
	int	eat; // time_to_eat
	int	sleep; // time_to_sleep
	int	time; // xynumber_of_times_each_philosopher_must_eat
	pthread_mutex_t *forks;
}				t_table;

typedef struct	s_struct
{
	pthread_t		thread;
	int				id;
	t_table			*table;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
}				t_struct;

long	get_time(void);
int		ft_init(int argc, char *argv[], t_table *t);

	/* Order
pick up forks
eat
sleep
think
*/

	/*
write the informations into a buffer before to print it and then use the write function
argv into one struct
struct
*/
