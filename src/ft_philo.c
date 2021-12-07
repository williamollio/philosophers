/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wollio <wollio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 19:46:20 by wollio            #+#    #+#             */
/*   Updated: 2021/12/07 17:40:10 by wollio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void *ft_checker(void *var)
{
	t_philo	*philo;
	int		i;
	int		flag;

	philo = (t_philo *)var;
	while (1)
	{
		i = 0;
		flag = 0;
		while (i < philo->parse->nbr)
		{
			printf("shit in checker %d\n", i);
			if (get_time() > philo[i].death_clock)
			{
				philo->parse->running = FALSE;
				break;
			}
			if (philo->parse->time && philo[i].time_eat == 0)
				flag++;
			i++;
		}
		if (flag == i)
		{
			philo->parse->running = FALSE;
			break;
		}
	}
	return (NULL);
}

void	*ft_routine(void *var)
{
	int		i;

	i = 0;
	t_philo *philo;
	philo = (t_philo *)var;
	printf("shit0 in routine %d\n", philo->id);
	pthread_mutex_lock(&philo->parse->wait);
	printf("shit01 in routine %d\n", philo->id);
	if (philo->parse->wait_flag == 0)
	{
		printf("shit10 in routine %d\n", philo->id);
		philo->parse->wait_flag = 1;
		printf("shit11 in routine %d\n", philo->id);
		while (1)
		{
			if (philo->parse->i == philo->parse->nbr)
				break;
		}
	}
	printf("shit2 in routine %d\n", philo->id);
	pthread_mutex_unlock(&philo->parse->wait);
	printf("shit21 in routine %d\n", philo->id);
	philo->parse->start = get_time();
	printf("shit22 in routine %d\n", philo->id);
	philo->time_eat = philo->parse->time;
	printf("shit23 in routine %d\n", philo->id);
	philo->death_clock = philo->parse->start + philo->parse->die;
	printf("shit3 in routine %d\n", philo->id);
	if (philo->id % 2 != 0)
		ft_usleep(philo->parse->eat / 2);
	printf("shit4 in routine %d\n", philo->id);
	while (philo->parse->running && philo->parse->time != 0)
	{
		if (philo->state == thinking)
			ft_eat(philo);
		if (philo->state == eating)
			ft_sleep(philo);
		if (philo->state == sleeping)
			ft_think(philo);
	}
	//ft_quite(philo);
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
		if (pthread_create(&philo[parse->i].thread, NULL, &ft_routine, &philo[parse->i]))
		{
		 	perror("Creation of the thread has failed\n");
		}
		parse->i++;
	}
	if (pthread_create(&dead, NULL, &ft_checker, philo))
	{
	 	perror("Creation of the checker has failed\n");
	}
	pthread_join(dead, NULL);
	return (philo);
}
