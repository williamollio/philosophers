/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wollio <williamollio@student.42.fr>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 18:35:32 by wollio            #+#    #+#             */
/*   Updated: 2021/11/26 12:07:55 by wollio           ###   ########.fr       */
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
	t_table		t;
	t_struct	s;

	if (ft_init(argc, argv, &t))
		return (1);
	t.forks = malloc(t.nbr * sizeof(pthread_mutex_t));
	if (t.forks == 0)
	{
		ft_putstr_fd("Malloc of t_table has failed \n", 2);
		return (1);
	}
	return (0);
		// struct = malloc(numphil * sizeof(t_struct));
		// i = 0;
		// pthread_mutex_init(&mutex, NULL);
		// while (i < 4)
		// {
		// 	if (pthread_create(&s[i]->thread, NULL, &routine, &s[i])) // we give here the adress we are gonna store the handle
		// 	{
		// 	 	perror("creation of the thread has failed\n");
		// 		return (1);
		// 	}
		// 	i++;
		// }
		// i = 0;
		// while (i < 4)
		// {
		// 	if (pthread_join(&s[i]->thread, NULL)) // here we give the value
		// 	{
		// 		perror("joining of the threads has failed\n");
		// 		return (2);
		// 	}
		// 	i++;
		// }
		// pthread_mutex_destroy(&mutex);
}
