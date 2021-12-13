#ifndef PHILOSOPHERS_H
#define PHILOSOPHERS_H

#include <stdbool.h>
#include <pthread.h>
#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include "../libft/libft.h"
#include <sys/time.h>
#include <limits.h>

#define TRUE 1
#define FALSE 0

typedef enum u_state
{
	thinking,
	taking_fork,
	eating,
	sleeping,
	died,
}			t_state;

typedef struct	s_parse
{
	int				nbr;
	int				die;
	int				eat;
	int				sleep;
	int				time;
	pthread_mutex_t	*forks;
	pthread_mutex_t	wait;
	pthread_mutex_t	write_lock;
	pthread_mutex_t	time_eat;
	int				wait_flag;
	int				i;
	long			start;
	bool			running;
}				t_parse;

typedef struct	s_philo
{
	pthread_t		thread;
	long			death_clock;
	int				id;
	int				is_dead;
	int				time_eat;
	int				state;
	t_parse			*parse;
	pthread_mutex_t	*right_fork;
	pthread_mutex_t	*left_fork;
}				t_philo;

long	get_time(void);
int		ft_parse_init(int argc, char *argv[], t_parse *parse);
int		ft_mutex_init(t_parse *parse);
t_philo	*ft_philo(t_parse *parse);
t_philo	*ft_allocate_philo(t_parse *parse);
void	philo_write(t_philo *philo, char *str, long start);
void	ft_usleep(long time);
void	ft_eat(t_philo *philo);
void	ft_sleep(t_philo *philo);
void	ft_think(t_philo *philo);
void	print_state(t_philo *philo);
void	ft_destroy_mutex(t_parse *parse, t_philo *philo);
int		ft_destroy_threads(t_parse *parse, t_philo *philo);
void	ft_forks(t_parse *parse, t_philo *philo);

#endif
