#include <philosofers.h>

int	main(int argc, char **argv)
{
	t_philo			*philo;
	t_values		values;
	pthread_mutex_t	*forks;

	philo = NULL;
	forks = NULL;
	validate(argv, argc);
	init(argv, &values, &philo, &forks);
	lets_lunch(philo, values.num_philo);
	printf("deu tudo certo!!\n");
	
	
	return (0);
}