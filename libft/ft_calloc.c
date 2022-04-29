/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozben <eozben@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 16:50:46 by eozben            #+#    #+#             */
/*   Updated: 2021/06/23 19:16:05 by eozben           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nitems, size_t size)
{
	size_t		space;
	size_t		i;
	void		*ptr;

	space = nitems * size;
	ptr = malloc(space);
	if (!ptr)
		return (NULL);
	i = 0;
	while (i < space)
	{
		((char *)ptr)[i] = 0;
		i++;
	}
	return (ptr);
}
