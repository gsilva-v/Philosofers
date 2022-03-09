/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosofers.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva-v <gsilva-v@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 11:12:12 by gsilva-v          #+#    #+#             */
/*   Updated: 2022/03/08 16:34:34 by gsilva-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOFERS_H
# define PHILOSOFERS_H

# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <string.h>
# include <sys/time.h>

# define INT_MAX 2147483647
# define FORK "has taken a fork"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define EAT "is eating"
# define DIED "died"

typedef struct s_values{
	int				one_philo;
	int				num_philo;
	int				time_die;
	int				time_sleep;
	int				time_eat;
	int				must_eat;
	int				someone_die;
	long			first_eat;
	pthread_mutex_t	*info_locker;
	pthread_mutex_t	*check_meals_locker;
	pthread_mutex_t	*last_meal_locker;
	pthread_mutex_t	*died_locker;
	pthread_mutex_t	*eating_locker;
}	t_values;

typedef struct s_philo{
	int				id;
	int				eat_counter;
	long			last_eat;
	pthread_mutex_t	*eating;
	int				is_eating;
	pthread_t		philos_thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	t_values		*values;
}	t_philo;

// Informations
void	show_inform(t_philo *philo, char *what_is_doing);

// Validate
void	validate(char **argv, int argc);

//  Lunching
void	*one_philo(t_philo *philo);
void	lets_lunch(t_philo *philo);
void	lunching(t_philo *philo);
int		check_satisfaction(t_philo *philo);
int		satisfied(t_philo *philo);

// Checker die
int		someone_died(t_philo *philo);
int		check_die(long time, t_philo *philo);
void	declare_death(t_philo *philo);

// Init
void	init(char **argv, t_values *values, t_philo **philo, \
pthread_mutex_t **forks);

// Time
long	current_time(void);
long	passed_time(long time_started);
void	miliseconds_sleep(int time_in_ms);

// Messages
void	print_and_exit(char *s);

//  Free
void	free_exit(t_values *values);
void	destroy_mutex_values(t_values *values, pthread_mutex_t *forks);
void	clean_all(t_philo *philo, t_values *values, pthread_mutex_t *forks);
void	close_dinner(t_philo *philo, t_values *values, pthread_mutex_t *forks);

// Utils
void	*ft_calloc(size_t nbytes, size_t sizemem);
int		ft_atoi(const char *str);
int		is_digit(char x);

#endif
