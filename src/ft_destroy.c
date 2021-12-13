/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wollio <williamollio@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/08 12:54:13 by wollio            #+#    #+#             */
/*   Updated: 2021/12/13 12:19:31 by wollio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

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

void	ft_destroy_mutex(t_parse *parse, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < parse->nbr)
	{
		pthread_mutex_unlock(&philo->left_fork[i]);
		pthread_mutex_destroy(&philo->left_fork[i]);
		i++;
	}
	pthread_mutex_unlock(&parse->wait);
	pthread_mutex_destroy(&parse->wait);
	pthread_mutex_unlock(&parse->write_lock);
	pthread_mutex_destroy(&parse->write_lock);
	pthread_mutex_unlock(&parse->time_eat);
	pthread_mutex_lock(&parse->time_eat);
}
