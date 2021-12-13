/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_state.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wollio <williamollio@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 18:52:49 by wollio            #+#    #+#             */
/*   Updated: 2021/12/13 12:38:53 by wollio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	print_state(t_philo *philo)
{
	long	current;
	pthread_mutex_lock(&philo->parse->write_lock);
	current = get_time() - philo->parse->start;
	if (philo->state == thinking && philo->parse->running == TRUE)
		printf("%ld \t %d \t %s\n", current, philo->id, "is thinking");
	if (philo->state == taking_fork && philo->parse->running == TRUE)
		printf("%ld \t %d \t %s\n", current, philo->id, "has taken a fork");
	if (philo->state == eating && philo->parse->running == TRUE)
		printf("%ld \t %d \t %s\n", current, philo->id, "is eating");
	if (philo->state == sleeping && philo->parse->running == TRUE)
		printf("%ld \t %d \t %s\n", current, philo->id, "is sleeping");
	if (philo->state == died && philo->parse->running == TRUE)
		printf("%ld \t %d \t %s\n", current, philo->id, "died");
	pthread_mutex_unlock(&philo->parse->write_lock);
}

void	ft_eat(t_philo *philo)
{

	pthread_mutex_lock(philo->right_fork);
	philo->state = taking_fork;
	if (philo->parse->nbr == 1)
	{
		print_state(philo);
		ft_usleep(philo->parse->die * 2);
		pthread_mutex_unlock(philo->right_fork);
		return;
	}
	pthread_mutex_lock(philo->left_fork);
	print_state(philo);
	print_state(philo);
	philo->state = eating;
	print_state(philo);
	philo->death_clock = get_time() + philo->parse->die;
	ft_usleep(philo->parse->eat);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
	philo->time_eat--;
}

void	ft_sleep(t_philo *philo)
{
	philo->state = sleeping;
	print_state(philo);
	ft_usleep(philo->parse->sleep);
}

void	ft_think(t_philo *philo)
{
	philo->state = thinking;
	print_state(philo);
}
