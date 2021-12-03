/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_allocate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wollio <wollio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 19:43:04 by wollio            #+#    #+#             */
/*   Updated: 2021/12/03 11:11:27 by wollio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void ft_init_forks(t_philo *philo, t_parse *parse, int i)
{
	if (i == 0)
	{
		philo->right_fork = &parse->forks[parse->nbr - 1];
		philo->left_fork = &parse->forks[i];
	}
	else
	{
		philo->right_fork = &parse->forks[i - 1];
		philo->left_fork = &parse->forks[i];
	}
}

/* actually allocate and init */
t_philo **ft_allocate_philo(t_philo **philo, t_parse *parse)
{
	int	i;

	i = 0;
	philo = malloc (parse->nbr * sizeof(t_philo));
	if (philo == 0)
		ft_putstr_fd("Malloc of t_philo has failed \n", 2);
	while (i < parse->nbr)
	{
		philo[i] = malloc (sizeof(t_philo));
		if (philo[i] == 0)
			ft_putstr_fd("Malloc of t_philo[i] has failed \n", 2);
		philo[i]->parse = parse;
		philo[i]->is_dead = 0;
		ft_init_forks(philo[i], parse, i);
		i++;
	}
	return (philo);
}