/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wollio <wollio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 18:35:32 by wollio            #+#    #+#             */
/*   Updated: 2021/12/07 17:20:05 by wollio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

//int pthread_create(pthread_t * thread, const pthread_attr_t * attr, void * (*start_routine)(void *), void *arg);
//int pthread_join(pthread_t th, void **thread_return);
//int pthread_detach(pthread_t thread);
//int pthread_mutex_destroy(pthread_mutex_t *mutex);
//int pthread_mutex_init(pthread_mutex_t *restrict mutex, const pthread_mutexattr_t *restrict attr);
//int pthread_mutex_lock(pthread_mutex_t *mutex);
//int pthread_mutex_unlock(pthread_mutex_t *mutex);

int	ft_destroy_threads(t_parse *parse, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < parse->nbr)
	{
		if (pthread_join(philo[i].thread, NULL))
		{
			perror("Joining of the threads has failed\n");
			return (EXIT_FAILURE);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}

void	ft_destroy_mutex(t_parse *parse)
{
	int	i;

	i = 0;

	while (i < parse->nbr)
	{
		pthread_mutex_unlock(&parse->forks[i]);
		pthread_mutex_destroy(&parse->forks[i]);
		i++;
	}
	pthread_mutex_unlock(&parse->wait);
	pthread_mutex_destroy(&parse->wait);
	pthread_mutex_unlock(&parse->write_lock);
	pthread_mutex_destroy(&parse->write_lock);
}

int	main(int argc, char *argv[])
{
	t_parse		*parse;
	t_philo		*philo;

	parse = malloc(sizeof(t_parse));
	// initialization of the parse struct
	if (ft_parse_init(argc, argv, parse))
		return (1);
	// allocate & initialize the array of forks
	if (ft_mutex_init(parse))
		return (1);
	// creation of the threads
	philo = ft_philo(parse);
	// destroy threads
	if (ft_destroy_threads(parse, philo))
		return (1);
	// destroy and unlock mutex
	ft_destroy_mutex(parse);
	return (0);
}
