/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: gsilva-v <gsilva-v@student.42sp.org.br>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/04 11:12:51 by gsilva-v          #+#    #+#             */
/*   Updated: 2022/03/04 11:12:52 by gsilva-v         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <philosofers.h>

void	ft_bzero(void *s, size_t n)
{
	memset(s, '\0', n);
}

void	*ft_calloc(size_t nbytes, size_t sizemem)
{
	void	*ptr;

	ptr = malloc(nbytes * sizemem);
	if (ptr == 0)
		return (0);
	ft_bzero(ptr, (nbytes * sizemem));
	return (ptr);
}
