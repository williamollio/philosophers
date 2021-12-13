/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wollio <williamollio@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 18:35:32 by wollio            #+#    #+#             */
/*   Updated: 2021/12/13 12:15:36 by wollio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	main(int argc, char *argv[])
{
	t_parse		*parse;
	t_philo		*philo;

	parse = malloc(sizeof(t_parse));
	if (ft_parse_init(argc, argv, parse))
		return (1);
	if (ft_mutex_init(parse))
		return (1);
	philo = ft_philo(parse);
	if (ft_destroy_threads(parse, philo))
		return (1);
	ft_destroy_mutex(parse, philo);
	return (0);
}
