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

typedef enum u_state
{
	thinking,
	taking_fork,
	eating,
	sleeping,
	died,
} t_state;

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
	int				start; // init
}				t_parse;

typedef struct	s_philo
{
	pthread_t		thread; // allocate + init
	int				id; // init
	int				is_dead; // init
	int				state; // yes
	t_parse			*parse; // ok
	pthread_mutex_t	*right_fork; // ok
	pthread_mutex_t	*left_fork; // ok
}				t_philo;

long	get_time(void);
int		ft_parse_init(int argc, char *argv[], t_parse *parse);
int		ft_mutex_init(t_parse *parse);
int		ft_philo(t_parse *parse, t_philo **philo);
t_philo	**ft_allocate_philo(t_philo **philo, t_parse *parse);
void	philo_write(t_philo *philo, char *str, long start);
void	ft_usleep(long time);
void	ft_eat(t_philo *philo);
void	ft_sleep(t_philo *philo);
void	ft_think(t_philo *philo);
void	print_state(t_philo *philo);

/* QUESTIONS */
/* allocation philo struct */

/* TO DO */
/* destroy mutex before to quit */