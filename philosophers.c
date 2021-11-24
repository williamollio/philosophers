/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: wollio <wollio@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 18:35:32 by wollio            #+#    #+#             */
/*   Updated: 2021/11/24 16:16:46 by wollio           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

//int pthread_create(pthread_t * thread, const pthread_attr_t * attr, void * (*start_routine)(void *), void *arg);
//int pthread_join(pthread_t th, void **thread_return);
//int pthread_detach(pthread_t thread);
//int pthread_mutex_destroy(pthread_mutex_t *mutex);
//int pthread_mutex_init(pthread_mutex_t *restrict mutex, const pthread_mutexattr_t *restrict attr);
//int pthread_mutex_lock(pthread_mutex_t *mutex);
//int pthread_mutex_unlock(pthread_mutex_t *mutex);

int mails = 0;
pthread_mutex_t mutex;

void* routine(void *var)
{
	t_struct *struct;
	struct = (t_struct *)var;

    for (int i = 0; i < 10000; i++) {
        pthread_mutex_lock(&mutex);
        mails++;
    	pthread_mutex_unlock(&mutex);
        // read mails
        // increment
        // write mails
    }
	return NULL;
}

int main(int argc, char* argv[]) {
	int			i;

	t_struct *struct;

	struct = malloc(numphil * sizeof(t_struct));
	i = 0;
	pthread_mutex_init(&mutex, NULL);
	while (i < 4)
	{
		if (pthread_create(&struct[i]->thread, NULL, &routine, &struct[i])) // we give here the adress we are gonna store the handle
		{
		 	perror("creation of the thread has failed\n");
			return (1);
		}
		i++;
	}
	i = 0;
	while (i < 4)
	{
		if (pthread_join(&struct[i]->thread, NULL)) // here we give the value
		{
			perror("joining of the threads has failed\n");
			return (2);
		}
		i++;
	}

	pthread_mutex_destroy(&mutex);
	printf("Number of mails: %d\n", mails);
	return 0;
}

/*
** Returns the timestamp in milliseconds
*/

long	get_time(void)
{
	struct timeval	tp;
	long		milliseconds;

	gettimeofday(&tp, NULL);
	milliseconds = tp.tv_sec * 1000;
	milliseconds = tp.tv_usec / 1000;
	return (milliseconds);
}

/*
** Prints time, sleeps 200ms, repeats!
*/

int main(void)
{
    long start_time;

		// Remember when we started
    start_time = get_time();

    while (1)
    {
				// Print time from start, in ms
        printf("%ld\n", get_time() - start_time);

				// Sleep 200 times 1000 microseconds (1 millisecond)
        usleep(200 * 1000);
    }
}