/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wollio <wollio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 19:46:20 by wollio            #+#    #+#             */
/*   Updated: 2021/12/02 16:40:29 by wollio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	*routine(void *var)
{
	int	i;

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
	philo_write(philo, "starts eating");
	usleep(philo->parse->eat * 1000);
	philo_write(philo, "finishes eating");
	return (NULL);
}

int	ft_philo(t_parse *parse, t_philo **philo)
{
	int i;

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
