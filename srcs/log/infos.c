#include <philosofers.h>

void	show_inform(t_philo *philo, char *what_is_doing)
{
	long	time;

	pthread_mutex_lock(philo->values->info_locker);
	time = passed_time(philo->values->first_eat);
	if (!philo->values->someone_die)
		printf("%ld %d %s \n", time, philo->id, what_is_doing);
	pthread_mutex_unlock(philo->values->info_locker);
}
