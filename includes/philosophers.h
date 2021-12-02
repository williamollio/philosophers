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
	int				nbr; // init
	int				die; // init
	int				eat; // init
	int				sleep; // init
	int				time; // init
	pthread_mutex_t	*forks; // allocate + init
	pthread_mutex_t	wait; // init
	pthread_mutex_t	write_lock; // init
	int				wait_flag; // init
	int				i; // init
}				t_parse;

typedef struct	s_philo
{
	pthread_t		thread; // allocate + init
	int				id; // init
	int				is_dead; // init
	t_parse			*parse; // ok
	pthread_mutex_t	*right_fork; // no
	pthread_mutex_t	*left_fork; // no
}				t_philo;

long	get_time(void);
int		ft_parse_init(int argc, char *argv[], t_parse *parse);
int		ft_mutex_init(t_parse *parse);
int		ft_philo(t_parse *parse, t_philo **philo);
t_philo	**ft_allocate_philo(t_philo **philo, t_parse *parse);
void	philo_write(t_philo *philo, char *str);

/* QUESTIONS */
/* allocation philo struct */