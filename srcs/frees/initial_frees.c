#include <philosofers.h>

void	free_exit(t_values *values)
{
	free(values->died_locker);
	free(values->last_meal_locker);
	free(values->info_locker);
	free(values->eating_locker);
	printf("Something is wrong\n");
	exit(1);
}

void	destroy_mutex_values(t_values *values, pthread_mutex_t *forks)
{
	pthread_mutex_destroy(values->died_locker);
	pthread_mutex_destroy(values->eating_locker);
	pthread_mutex_destroy(values->last_meal_locker);
	pthread_mutex_destroy(values->info_locker);
	free(forks);
	free_exit(values);
}

void	clean_all(t_philo *philo, t_values *values, pthread_mutex_t *forks)
{
	int	i;

	i = 0;
	while (i< values->num_philo)
	{
		pthread_mutex_destroy(&forks[i]);
		i++;
	
	}
	free(philo);
	destroy_mutex_values(values, forks);
}
