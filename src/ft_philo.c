/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wollio <wollio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 19:46:20 by wollio            #+#    #+#             */
/*   Updated: 2021/12/13 15:09:27 by wollio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	ft_wait_for_all(t_philo *philo)
{
	pthread_mutex_lock(&philo->parse->wait);
	if (philo->parse->wait_flag == 0)
	{
		philo->parse->wait_flag = 1;
		while (1)
		{
			if (philo->parse->i == philo->parse->nbr)
				break ;
			usleep(100);
		}
	}
	pthread_mutex_unlock(&philo->parse->wait);
}

void	*ft_routine(void *var)
{
	int		i;
	t_philo	*philo;

	i = 0;
	philo = (t_philo *)var;
	ft_wait_for_all(philo);
	philo->parse->start = get_time();
	philo->time_eat = philo->parse->time;
	philo->death_clock = philo->parse->start + philo->parse->die;
	if (philo->id % 2 != 0)
		ft_usleep(philo->parse->eat / 2);
	while (philo->parse->running == TRUE)
	{
		if (philo->state == thinking)
			ft_eat(philo);
		if (philo->time_eat == 0)
			break ;
		if (philo->state == eating)
			ft_sleep(philo);
		if (philo->state == sleeping)
			ft_think(philo);
	}
	return (NULL);
}

t_philo	*ft_philo(t_parse *parse)
{
	pthread_t	dead;
	t_philo		*philo;

	philo = ft_allocate_philo(parse);
	parse->running = TRUE;
	while (parse->i < parse->nbr)
	{
		philo[parse->i].id = parse->i + 1;
		if (pthread_create(&philo[parse->i].thread, NULL,
				&ft_routine, &philo[parse->i]))
		{
			perror("Creation of the thread has failed\n");
		}
		ft_usleep(100);
		parse->i++;
	}
	ft_usleep(100);
	if (pthread_create(&dead, NULL, &ft_checker, philo))
	{
		perror("Creation of the checker has failed\n");
	}
	pthread_join(dead, NULL);
	return (philo);
}
