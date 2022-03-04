/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lunch.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva-v <gsilva-v@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 11:12:34 by gsilva-v          #+#    #+#             */
/*   Updated: 2022/03/04 13:26:03 by gsilva-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosofers.h>	

void	*philo_routine(void *philo)
{
	t_philo	*aux;

	aux = (t_philo *)philo;
	if (aux->id % 2 == 0)
		miliseconds_sleep(5);
	if (aux->values->one_philo)
		return (one_philo(philo));
	while (!someone_died(philo))
	{
		lunching(philo);
		if (satisfied(philo))
			return (NULL);
		show_inform(philo, SLEEP);
		miliseconds_sleep(aux->values->time_sleep);
		show_inform(philo, THINK);
	}
	return (NULL);
}

void	*death_checker(void *philo)
{
	t_philo	*aux;
	long	time;
	int		counter_philo;

	time = 0;
	aux = (t_philo *)philo;
	while (!check_satisfaction(aux))
	{
		counter_philo = 0;
		while (counter_philo < aux->values->num_philo)
		{
			time = passed_time(aux->values->first_eat);
			if (check_die(time, aux))
			{
				show_inform(&aux[counter_philo], DIED);
				declare_death(&aux[counter_philo]);
				return (NULL);
			}
			counter_philo++;
		}
		miliseconds_sleep(1);
	}
	return (NULL);
}

void	lets_lunch(t_philo *philo)
{
	pthread_t	infos;
	int			i;

	i = 0;
	philo->values->first_eat = current_time();
	while (i < philo->values->num_philo)
	{
		pthread_create(&philo[i].philos_thread, NULL, &philo_routine, \
		&philo[i]);
		i++;
	}
	pthread_create(&infos, NULL, &death_checker, philo);
	i = 0;
	while (i < philo->values->num_philo)
	{
		pthread_join(philo[i].philos_thread, NULL);
		i++;
	}
	pthread_join(infos, NULL);
}
