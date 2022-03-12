/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva-v <gsilva-v@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 11:12:37 by gsilva-v          #+#    #+#             */
/*   Updated: 2022/03/04 11:12:38 by gsilva-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

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
	lets_lunch(philo);
	close_dinner(philo, &values, forks);
	return (0);
}
