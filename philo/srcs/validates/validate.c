/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva-v <gsilva-v@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 11:12:58 by gsilva-v          #+#    #+#             */
/*   Updated: 2022/03/12 08:03:46 by gsilva-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosofers.h>

static void	check_argc(int argc)
{
	if (argc > 6)
		print_and_exit("Too many arguments");
	if (argc < 5)
		print_and_exit("Too few arguments");
}

static int	check_if_is_digit_only(char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (argv[i])
	{
		j = 0;
		if (ft_atoi(argv[i]) > INT_MAX || ft_atoi(argv[i]) < 0)
		{
			if (ft_strncmp(argv[i], "-", -1))
				print_and_exit(INVALID_ARG);
			return (1);
		}
		while (argv[i][j])
		{
			if (is_digit(argv[i][j]))
				return (1);
			j++;
		}
		i++;
	}
	return (0);
}

void	validate(char **argv, int argc)
{
	check_argc(argc);
	if (check_if_is_digit_only(argv))
		print_and_exit("invalid argument, use only number");
}
