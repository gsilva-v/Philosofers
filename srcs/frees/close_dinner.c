#include <philosofers.h>

void	clean_table(t_philo *philo, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	while (i < philo->values->num_philo)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	}
	free(philo);
	free(forks);
}

void	erase_values(t_values *values)
{
	pthread_mutex_destroy(values->check_meals_locker);
	pthread_mutex_destroy(values->died_locker);
	pthread_mutex_destroy(values->eating_locker);
	pthread_mutex_destroy(values->info_locker);
	pthread_mutex_destroy(values->last_meal_locker);
	free(values->check_meals_locker);
	free(values->died_locker);
	free(values->eating_locker);
	free(values->info_locker);
	free(values->last_meal_locker);
}

void	close_dinner(t_philo *philo, t_values *values, pthread_mutex_t *forks)
{
	clean_table(philo, forks);
	erase_values(values);
}
