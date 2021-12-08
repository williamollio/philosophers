/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wollio <wollio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 18:35:32 by wollio            #+#    #+#             */
/*   Updated: 2021/12/08 13:26:01 by wollio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	main(int argc, char *argv[])
{
	t_parse		*parse;
	t_philo		*philo;

	parse = malloc(sizeof(t_parse));
	// initialization of the parse struct
	if (ft_parse_init(argc, argv, parse))
		return (1);
	// allocate & initialize the array of forks
	if (ft_mutex_init(parse))
		return (1);
	// // creation of the threads
	philo = ft_philo(parse);
	// // destroy threads
	if (ft_destroy_threads(parse, philo))
		return (1);
	// // destroy and unlock mutex
	ft_destroy_mutex(parse, philo);
	return (0);
}
