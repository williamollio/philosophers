/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wollio <wollio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 19:44:16 by wollio            #+#    #+#             */
/*   Updated: 2021/12/08 13:39:08 by wollio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	ft_mutex_init(t_parse *parse)
{
	int		i;

	i = 0;
	pthread_mutex_init(&parse->wait, NULL);
	pthread_mutex_init(&parse->write_lock, NULL);
	pthread_mutex_init(&parse->time_eat, NULL);
	parse->forks = malloc(parse->nbr * sizeof(pthread_mutex_t));
	if (parse->forks == 0)
	{
		ft_putstr_fd("Malloc of forks has failed \n", 2);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

int	ft_parse_init(int argc, char *argv[], t_parse *parse)
{
	if (parse == 0)
	{
		ft_putstr_fd("Malloc of t_parse has failed \n", 2);
		return (EXIT_FAILURE);
	}
	if (argc < 5 || argc > 6)
	{
		ft_putstr_fd("Wrong numbers of arguments \n", 2);
		return (EXIT_FAILURE);
	}
	parse->nbr = ft_atoi(argv[1]); // manage failures
	parse->die = ft_atoi(argv[2]);
	parse->eat = ft_atoi(argv[3]);
	parse->sleep = ft_atoi(argv[4]);
	if (argc == 6)
		parse->time = ft_atoi(argv[5]);
	else
		parse->time = INT_MAX;
	parse->wait_flag = 0;
	parse->i = 0;
	return (EXIT_SUCCESS);
}
