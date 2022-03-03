#include <philosofers.h>

void	set_values(char **argv, t_values *values)
{
	if (!values)
		values = (t_values *)ft_calloc(sizeof(t_values), 1);	
	values->num_philo = ft_atoi(argv[1]);
	values->time_die = ft_atoi(argv[2]);
	values->time_eat = ft_atoi(argv[3]);
	values->time_sleep = ft_atoi(argv[4]);
	values->must_eat = -1;
	if (argv[5])
		values->must_eat = ft_atoi(argv[5]);
	values->first_eat = 0;
	values->one_philo = 0;
	if (values->num_philo == 1)
		values->one_philo = 1;
	values->someone_die = 0;	
}

void	start_mutex(t_values *values)
{
	values->died_locker = (pthread_mutex_t *) ft_calloc(sizeof(pthread_mutex_t), 1);
	values->eating_locker = (pthread_mutex_t *) ft_calloc(sizeof(pthread_mutex_t), 1);
	values->info_locker = (pthread_mutex_t *) ft_calloc(sizeof(pthread_mutex_t), 1);
	values->last_meal_locker = (pthread_mutex_t *) ft_calloc(sizeof(pthread_mutex_t), 1);
	if (!values->died_locker || !values->eating_locker || !values->info_locker || !values->died_locker)
		free_exit(values);
	pthread_mutex_init(values->died_locker, NULL);
	pthread_mutex_init(values->last_meal_locker, NULL);
	pthread_mutex_init(values->info_locker, NULL);
	pthread_mutex_init(values->eating_locker, NULL);
}

void	start_forks(t_values *values, pthread_mutex_t **forks, int num_philo)
{
	int	index;

	index = 0;
	*forks = (pthread_mutex_t *) ft_calloc(sizeof(pthread_mutex_t), num_philo);
	if (!*forks)
		destroy_mutex_values(values, *forks);
	while (index < num_philo)
	{
		pthread_mutex_init(&(*forks)[index], NULL);
		index++;
	}
}

void	create_philos(t_philo **philo, t_values *values, pthread_mutex_t **forks)
{
	int	id;

	id = 0;
	*philo = (t_philo *) ft_calloc(sizeof(t_philo), values->num_philo);
	if (!*philo)
		clean_all(*philo, values, *forks);
	/*
		aqui sera criado os filosofos e os garfos, como o numero de garfos 
		é o mesmo de filosofos, a criação é dessa maneira.
		a atribuição dos garfos é: o filosofo atual recebe um garfo a esquerda que tem o 
		mesmo id que ele, e a direita recebe um id maior, assim quando chegar no proximo filosofo
		o atual ja tera um garfo certo pra colocar a sua esquerda, no fim, voltamos um id para alocar
		o garfo inicial a direita do ultimo filosofo.
	*/
	while (id < values->num_philo)
	{
		(*philo)[id].id = id + 1;
		(*philo)[id].last_eat = 0;
		(*philo)[id].eat_counter = 0;
		(*philo)[id].right_fork = &(*forks)[id];
		(*philo)[id].left_fork = &(*forks)[id + 1];
		(*philo)[id].values = values;
		id++;
	}
	id--;
	(*philo)[id].left_fork = &(*forks)[0];
}

void	init(char **argv, t_values *values, t_philo **philo, pthread_mutex_t **forks)
{
	set_values(argv, &(*values));
	start_mutex(values);
	start_forks(values, forks, values->num_philo);
	create_philos(philo, values, forks);
}