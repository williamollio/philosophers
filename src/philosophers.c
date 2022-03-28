/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wollio <wollio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 18:35:32 by wollio            #+#    #+#             */
/*   Updated: 2022/01/19 10:51:07 by wollio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	main(int argc, char *argv[])
{
	t_parse		*parse;
	t_philo		*philo;

	parse = malloc(sizeof(t_parse));
	if (parse == 0)
	{
		ft_putstr_fd("Malloc of t_parse has failed \n", 2);
		return (EXIT_FAILURE);
	}
	if (ft_parse_init(argc, argv, parse))
		return (EXIT_FAILURE);
	if (ft_mutex_init(parse))
		return (EXIT_FAILURE);
	philo = ft_philo(parse);
	if (philo == NULL)
		return (EXIT_FAILURE);
	if (ft_thread_checker(philo))
		return (EXIT_FAILURE);
	if (ft_destroy_threads(parse, philo))
		return (EXIT_FAILURE);
	ft_destroy_mutex(parse, philo);
	return (EXIT_SUCCESS);
}
