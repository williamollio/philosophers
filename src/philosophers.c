/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wollio <wollio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 18:35:32 by wollio            #+#    #+#             */
/*   Updated: 2021/12/01 19:44:00 by wollio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

//int pthread_create(pthread_t * thread, const pthread_attr_t * attr, void * (*start_routine)(void *), void *arg);
//int pthread_join(pthread_t th, void **thread_return);
//int pthread_detach(pthread_t thread);
//int pthread_mutex_destroy(pthread_mutex_t *mutex);
//int pthread_mutex_init(pthread_mutex_t *restrict mutex, const pthread_mutexattr_t *restrict attr);
//int pthread_mutex_lock(pthread_mutex_t *mutex);
//int pthread_mutex_unlock(pthread_mutex_t *mutex);

int	main(int argc, char *argv[])
{
	t_parse		*parse;
	t_philo		*philo;

	parse = malloc(sizeof(t_parse));
	// initialization of the parse struct
	if (ft_parse_init(argc, argv, parse))
		return (1);
	// allocate & initialize the array of forks
	if (ft_forks_init(parse))
		return (1);
	// creation of the threads
	if (ft_philo(parse, &philo))
		return (1);
	return (0);
}
