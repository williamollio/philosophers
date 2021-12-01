/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wollio <wollio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 19:46:20 by wollio            #+#    #+#             */
/*   Updated: 2021/12/01 19:46:44 by wollio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void *routine(void *var)
{
	int	i; // forks

	i = 0;
	t_philo *philo;
	philo = (t_philo *)var;
	printf("philo : %d\n", philo->id);
	//pthread_mutex_lock(&parse->forks[i]);
	//pthread_mutex_unlock(&parse->forks[i]);
	return (NULL);
}

int	ft_philo(t_parse *parse, t_philo **philo)
{
	int	i;

	philo = ft_allocate_philo(philo, parse);
	i = 0;
	printf("parse->nbr %d\n", parse->nbr);
	while (i < parse->nbr)
	{
		philo[i]->id = i + 1;
		printf("i %d\n", i);
		if (pthread_create(&philo[i]->thread, NULL, &routine, philo[i]))
		{
		 	perror("Creation of the thread has failed\n");
			return (EXIT_FAILURE);
		}
		i++;
	}
	i = 0;
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
