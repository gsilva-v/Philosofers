#ifndef PHILOSOFERS_H
# define PHILOSOFERS_H
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <pthread.h>
# include <string.h>
# include <sys/time.h>

typedef struct s_philo{
	int	num_philo;
	int	num_forks;
	int	time_die;
	int	time_sleep;
	int	time_eat;
	int	must_eat;

}	t_philo;


// Main

// Messages
void	error_message(char *s);


// Utils
void	*ft_calloc(size_t nbytes, size_t sizemem);
int		ft_atoi(const char *str);


#endif
