#include <philosofers.h>	

void	*philo_routine(void *philo)
{
	t_philo	*aux;

	aux = (t_philo *)philo;
	if (aux->id % 2 == 0)
		miliseconds_sleep(5);//isso é para nao haver corrida de dados
	if (aux->values->one_philo)
		return (NULL);
	while (!someone_died(philo))
	{
		lunching(philo);
		if (satisfied(philo))
			return (NULL);
		show_inform(philo, "sleeping");
		miliseconds_sleep(aux->values->time_sleep);
		show_inform(philo, "thinking");
 	}
}

void	*info_routine(void *philo)
{

}

void	lets_lunch(t_philo *philo, int num_philos)
{
	pthread_t	infos;
	int			i;

	i = 0;
	philo->values->first_eat = current_time();
	while(i < philo->values->num_philo)
	{
		pthread_create(&philo[i].philos_thread, NULL, &philo_routine, &philo[i]);
		i++;
	}
	pthread_create(&infos, NULL, &info_routine, philo);
	i = 0;
	while(i < philo->values->num_philo)
	{
		pthread_join(philo[i].philos_thread, NULL);
		i++;
	}
	pthread_join(infos, NULL);
}