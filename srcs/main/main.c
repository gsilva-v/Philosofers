#include <philosofers.h>



int	check_args(int argc)
{
	if (argc > 6)
	{
		error_message("Too many arguments");
		return (1);
	}
	if (argc < 5)
	{
		error_message("Too few arguments");
		return (1);
	}
	return (0);
}

void	atribute_args(char **argv, t_philo *philo)
{
	philo->num_philo = ft_atoi(argv[1]);
	philo->time_die = ft_atoi(argv[2]);
	philo->time_eat = ft_atoi(argv[3]);
	philo->time_sleep = ft_atoi(argv[4]);
	philo->must_eat = -1;
	if (argv[5])
		philo->must_eat = ft_atoi(argv[5]);

}


int	main(int argc, char **argv)
{
	t_philo *philo;

	if (check_args(argc))
		return (1);
	philo = (t_philo *)ft_calloc (sizeof(t_philo), 1);
	atribute_args(argv, philo);
	
	
	
	return (0);
}