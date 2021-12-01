/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_allocate.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wollio <wollio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 19:43:04 by wollio            #+#    #+#             */
/*   Updated: 2021/12/01 19:43:23 by wollio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

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
		i++;
	}
	return (philo);
}