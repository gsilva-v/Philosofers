#include <philosofers.h>

int	someone_died(t_philo *philo)
{

	return (0);
}

int	satisfied(t_philo *philo)
{
	pthread_mutex_lock(philo->values->check_meals_locker);
	if (philo->eat_counter == philo->values->must_eat)
	{
		pthread_mutex_lock(philo->values->check_meals_locker);
		return (1);
	}
	pthread_mutex_lock(philo->values->check_meals_locker);
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
	show_inform(philo, "has taken a fork");
	show_inform(philo, "has taken a fork");
	show_inform(philo, "eating");
	pthread_mutex_lock(philo->values->last_meal_locker);
	philo->last_eat = passed_time(philo->values->first_eat);
	philo->eat_counter++;
	pthread_mutex_unlock(philo->values->last_meal_locker);
	pthread_mutex_unlock(philo->right_fork);
	pthread_mutex_unlock(philo->left_fork);
}