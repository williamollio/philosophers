/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_state.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wollio <wollio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/03 18:52:49 by wollio            #+#    #+#             */
/*   Updated: 2021/12/03 19:11:44 by wollio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	print_state(t_philo *philo)
{
	long	current;
	pthread_mutex_lock(&philo->parse->write_lock);
	current = get_time() - philo->parse->start;
	if (philo->state == thinking)
		printf("%ld", current, philo->id, "is thinking");
	if (philo->state == taking_fork)
		printf("%ld", current, philo->id, "has taken a fork");
	if (philo->state == eating)
		printf("%ld", current, philo->id, "is eating");
	if (philo->state == sleeping)
		printf("%ld", current, philo->id, "is sleeping");
	if (philo->state == died)
		printf("%ld", current, philo->id, "died");
	pthread_mutex_unlock(&philo->parse->write_lock);
}

void	ft_eat(t_philo *philo)
{

	pthread_mutex_lock(&philo->right_fork);
	philo->state = taking_fork;
	print_state(philo);
	pthread_mutex_unlock(&philo->right_fork);
}
void	ft_sleep(t_philo *philo)
{

}

void	ft_think(t_philo *philo)
{

}