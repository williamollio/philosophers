/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_allocate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wollio <williamollio@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 19:43:04 by wollio            #+#    #+#             */
/*   Updated: 2021/12/13 12:19:44 by wollio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void	ft_init_forks(t_philo *philo, t_parse *parse, int i)
{
	if (i == 0)
	{
		philo[i].right_fork = &parse->forks[parse->nbr - 1];
		philo[i].left_fork = &parse->forks[i];
	}
	else
	{
		philo[i].right_fork = &parse->forks[i - 1];
		philo[i].left_fork = &parse->forks[i];
	}
}

void	ft_forks(t_parse *parse, t_philo *philo)
{
	int	i;

	i = 0;
	while (i < parse->nbr)
	{
		philo[i].parse = parse;
		ft_init_forks(philo, parse, i);
		pthread_mutex_init(philo[i].left_fork, NULL);
		i++;
	}
}

t_philo	*ft_allocate_philo(t_parse *parse)
{
	t_philo	*philo;

	philo = (t_philo *)malloc(parse->nbr * sizeof(t_philo));
	if (philo == 0)
			ft_putstr_fd("Malloc of t_philo[i] has failed \n", 2);
	ft_forks(parse, philo);
	return (philo);
}
