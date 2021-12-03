/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wollio <wollio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 19:46:20 by wollio            #+#    #+#             */
/*   Updated: 2021/12/03 19:08:22 by wollio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	*routine(void *var)
{
	int		i;
	long	start;

	i = 0;
	t_philo *philo;
	philo = (t_philo *)var;
	pthread_mutex_lock(&philo->parse->wait);
	if (philo->parse->wait_flag == 0)
	{
		philo->parse->wait_flag = 1;
		while (1)
		{
			if (philo->parse->i == philo->parse->nbr)
				break;
		}
	}
	pthread_mutex_unlock(&philo->parse->wait);
	philo->parse->start = get_time();
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(philo->right_fork);
		pthread_mutex_lock(philo->left_fork);
		philo_write(philo, "starts eating", start);
		ft_usleep(philo->parse->eat);
		philo_write(philo, "finishes eating", start);
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
	}
	while (1)
	{
		if (philo->state == thinking)
			ft_eat(philo);
		else if (philo->state == eating)
			ft_sleep(philo);
		else if (philo->state == sleeping)
			ft_think(philo);
	}
	return (NULL);
}

int	ft_philo(t_parse *parse, t_philo **philo)
{
	int	i;
	//pthread_t dead;

	i = 0;
	philo = ft_allocate_philo(philo, parse);
	while (parse->i < parse->nbr)
	{
		philo[parse->i]->id = parse->i + 1;
		if (pthread_create(&philo[parse->i]->thread, NULL, &routine, philo[parse->i]))
		{
		 	perror("Creation of the thread has failed\n");
			return (EXIT_FAILURE);
		}
		parse->i++;
	}
	while (i < parse->nbr)
	{
		if (pthread_join(philo[i]->thread, NULL))
		{
			perror("Joining of the threads has failed\n");
			return (EXIT_FAILURE);
		}
		i++;
	}
	return (EXIT_SUCCESS);
}
