/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wollio <williamollio@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 10:24:38 by wollio            #+#    #+#             */
/*   Updated: 2021/11/26 12:02:12 by wollio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	ft_init(int argc, char *argv[], t_table *t)
{
	t = malloc (sizeof(t_table));
	if (t = 0)
	{
		ft_putstr_fd("Malloc of t_table has failed \n", 2);
		return (EXIT_FAILURE);
	}
	if (argc < 5 || argc > 6)
	{
		ft_putstr_fd("Wrong numbers of arguments \n", 2);
		return (EXIT_FAILURE);
	}
	t->nbr = ft_atoi(argv[1]);
	t->die = ft_atoi(argv[2]);
	t->eat = ft_atoi(argv[3]);
	t->sleep = ft_atoi(argv[4]);
	if (argc == 6)
		t->time = ft_atoi(argv[5]);
	else
		t->time = 0;
	return (EXIT_SUCCESS);
}

/** Returns the timestamp in milliseconds **/
long get_time(void)
{
	struct timeval tp;
	long milliseconds;

	gettimeofday(&tp, NULL);
	milliseconds = tp.tv_sec * 1000;
	milliseconds = tp.tv_usec / 1000;
	return (milliseconds);
}

