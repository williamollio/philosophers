#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "../libft/libft.h"
#include <sys/time.h>

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

// ./philosophers 5 800 200 200

typedef struct	s_parse
{
	int	nbr; // number_of_philosophers
	int	die; // time_to_die
	int	eat; // time_to_eat
	int	sleep; // time_to_sleep
	int	time; // xynumber_of_times_each_philosopher_must_eat
	pthread_mutex_t *forks;
}				t_parse;

typedef struct	s_philo
{
	pthread_t		thread;
	int				id;
	t_parse			*parse;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
}				t_philo;

long	get_time(void);
int		ft_parse_init(int argc, char *argv[], t_parse *parse);
int		ft_forks_init(t_parse *parse);
int		ft_philo(t_parse *parse, t_philo **philo);
t_philo	**ft_allocate_philo(t_philo **philo, t_parse *parse);

/* QUESTIONS */
/* allocation philo struct */