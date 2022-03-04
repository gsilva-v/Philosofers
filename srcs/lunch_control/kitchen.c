/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   kitchen.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva-v <gsilva-v@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 11:12:31 by gsilva-v          #+#    #+#             */
/*   Updated: 2022/03/04 11:17:46 by gsilva-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosofers.h>

void	*one_philo(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	show_inform(philo, FORK);
	pthread_mutex_unlock(philo->left_fork);
	return (NULL);
}

int	someone_died(t_philo *philo)
{
	pthread_mutex_lock(philo->values->died_locker);
	if (philo->values->someone_die)
	{
		pthread_mutex_unlock(philo->values->died_locker);
		return (1);
	}
	pthread_mutex_unlock(philo->values->died_locker);
	return (0);
}

int	check_satisfaction(t_philo *philo)
{
	int	who_already_ate;
	int	philo_counter;

	who_already_ate = 0;
	philo_counter = 0;
	while (philo_counter < philo->values->num_philo)
	{
		if (satisfied(philo))
			who_already_ate++;
		philo_counter++;
	}
	if (who_already_ate == philo->values->num_philo)
		return (1);
	return (0);
}

int	satisfied(t_philo *philo)
{
	pthread_mutex_lock(philo->values->check_meals_locker);
	if (philo->eat_counter == philo->values->must_eat)
	{
		pthread_mutex_unlock(philo->values->check_meals_locker);
		return (1);
	}
	pthread_mutex_unlock(philo->values->check_meals_locker);
	return (0);
}

void	lunching(t_philo *philo)
{
	pthread_mutex_lock(philo->right_fork);
	pthread_mutex_lock(philo->left_fork);
	if (someone_died(philo))
	{
		pthread_mutex_unlock(philo->right_fork);
		pthread_mutex_unlock(philo->left_fork);
	}
	show_inform(philo, FORK);
	show_inform(philo, FORK);
	show_inform(philo, EAT);
	miliseconds_sleep(philo->values->time_eat);
	pthread_mutex_lock(philo->values->last_meal_locker);
	philo->last_eat = passed_time(philo->values->first_eat);
	philo->eat_counter++;
	pthread_mutex_unlock(philo->values->last_meal_locker);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}
