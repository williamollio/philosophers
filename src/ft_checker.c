/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_checker.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wollio <wollio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/13 14:51:35 by wollio            #+#    #+#             */
/*   Updated: 2021/12/14 16:43:13 by wollio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	ft_check_death(t_philo *philo, int i)
{
	if (get_time() > philo[i].death_clock)
	{
		philo[i].state = died;
		print_state(&philo[i]);
		philo->parse->running = FALSE;
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

void	ft_done_eating(t_philo *philo, int *flag, int i)
{
	if (philo->parse->time != INT_MAX && philo[i].time_eat <= 0)
	{
		pthread_mutex_lock(&philo->parse->time_eat);
		(*flag)++;
		pthread_mutex_unlock(&philo->parse->time_eat);
	}
}

int	ft_all_finish_eating(t_philo *philo, int flag, int i)
{
	if (flag == i)
	{
		philo->parse->running = FALSE;
		printf("Philosophers finish eating \n");
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

void	*ft_checker(void *var)
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
			if (ft_check_death(philo, i))
				return (NULL);
			ft_done_eating(philo, &flag, i);
			i++;
		}
		if (ft_all_finish_eating(philo, flag, i))
			return (NULL);
	}
	return (NULL);
}

int	ft_thread_checker(t_philo *philo)
{
	pthread_t	dead;

	if (pthread_create(&dead, NULL, &ft_checker, philo))
	{
		ft_putstr_fd("Creation of the checker has failed\n", 1);
		return (EXIT_FAILURE);
	}
	pthread_join(dead, NULL);
	return (EXIT_SUCCESS);
}
