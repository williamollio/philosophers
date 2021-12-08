/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wollio <wollio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 19:46:20 by wollio            #+#    #+#             */
/*   Updated: 2021/12/08 18:29:20 by wollio           ###   ########.fr       */
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
			if (get_time() > philo[i].death_clock)
			{
				printf("get_time() %ld \n", get_time());
				printf("philo[i].death_clock %ld \n", philo[i].death_clock);
				philo[i].state = died;
				print_state(&philo[i]);
				philo->parse->running = FALSE;
				return (NULL);
			}
			if (philo->parse->time != INT_MAX && philo[i].time_eat <= 0)
			{
				pthread_mutex_lock(&philo->parse->time_eat);
				flag++;
				pthread_mutex_unlock(&philo->parse->time_eat);
			}
			i++;
		}
		if (flag == i)
		{
			philo->parse->running = FALSE;
			printf("Philosophers finish eating \n");
			return (NULL);
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
	philo->time_eat = philo->parse->time;
	philo->death_clock = philo->parse->start + philo->parse->die;
	if (philo->id % 2 != 0)
		ft_usleep(philo->parse->eat / 2);
	while (philo->parse->running == TRUE)
	{
		if (philo->state == thinking)
			ft_eat(philo);
		if (philo->time_eat == 0)
			break;
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
	ft_usleep(500);
	if (pthread_create(&dead, NULL, &ft_checker, philo))
	{
	 	perror("Creation of the checker has failed\n");
	}
	pthread_join(dead, NULL);
	return (philo);
}
