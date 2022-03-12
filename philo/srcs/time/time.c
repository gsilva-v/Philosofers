/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva-v <gsilva-v@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 11:12:43 by gsilva-v          #+#    #+#             */
/*   Updated: 2022/03/04 11:12:47 by gsilva-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosofers.h>

void	miliseconds_sleep(int time_in_ms)
{
	long	start_time;

	start_time = current_time();
	while ((current_time() - start_time) < (long)time_in_ms)
		usleep(10);
}

long	current_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return ((time.tv_sec * 1000) + (time.tv_usec / 1000));
}

long	passed_time(long time_started)
{
	return (current_time() - time_started);
}
