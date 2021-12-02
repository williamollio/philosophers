/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wollio <wollio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/26 10:24:38 by wollio            #+#    #+#             */
/*   Updated: 2021/12/02 16:44:29 by wollio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

void ft_putlong_fd(long n, int fd)
{
	char	res;

	if (n <=-2147483648)
	{
		write(fd, "-2147483648", 11);
		return ;
	}
	if (n < 0)
	{
		write(fd, "-", 1);
		n *= (-1);
	}
	if (n >= 10)
		ft_putnbr_fd(n / 10, fd);
	res = n % 10 + '0';
	write(fd, &res, 1);
}

/** Returns the timestamp in milliseconds **/
long get_time(void)
{
	struct timeval	tp;
	long			milliseconds;

	gettimeofday(&tp, NULL);
	milliseconds = tp.tv_sec * 1000;
	milliseconds = tp.tv_usec / 1000;
	return (milliseconds);
}

void	philo_write(t_philo *philo, char *str)
{
	pthread_mutex_lock(&philo->parse->write_lock);
	if (!philo->is_dead)
	{
		ft_putlong_fd(get_time(), 1);
		write (1, "\t", 1);
		ft_putlong_fd(philo->id, 1);
		write(1, " ", 1);
		write(1, str, ft_strlen(str));
		write(1, "\n", 1);
	}
	pthread_mutex_unlock(&philo->parse->write_lock);
}
