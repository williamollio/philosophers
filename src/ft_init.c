/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_init.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wollio <wollio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/12/01 19:44:16 by wollio            #+#    #+#             */
/*   Updated: 2021/12/10 17:40:55 by wollio           ###   ########.fr       */
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

int	ft_parsing(int argc, char *argv[])
{
	long nbr;
	long die;
	long eat;
	long sleep;
	long time;

	nbr = ft_atol(argv[1]); // manage failures
	die = ft_atol(argv[2]);
	eat = ft_atol(argv[3]);
	sleep = ft_atol(argv[4]);
	if (argc == 6)
		time = ft_atol(argv[5]);
	else
		time = INT_MAX;
	if (nbr > INT_MAX || nbr < 0
		|| die > INT_MAX || die < 0
		|| eat > INT_MAX || eat < 0
		|| sleep > INT_MAX || sleep < 0
		|| time > INT_MAX || time < 0)
		return (EXIT_FAILURE);
	if ((nbr == 0 && ft_strncmp(argv[1], "0", 1))
		|| (die == 0 && ft_strncmp(argv[2], "0", 1))
		|| (eat == 0 && ft_strncmp(argv[3], "0", 1))
		|| (sleep == 0 && ft_strncmp(argv[4], "0", 1))
		|| (time == 0 && ft_strncmp(argv[5], "0", 1)))
		return (EXIT_FAILURE);
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
	if (ft_parsing(argc, argv))
	{
		ft_putstr_fd("False inputs \n", 2);
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
