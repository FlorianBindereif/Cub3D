/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozben <eozben@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 17:52:55 by eozben            #+#    #+#             */
/*   Updated: 2021/06/23 19:20:21 by eozben           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *str, int c, size_t n)
{
	size_t			i;
	const char		*s;

	s = (const char *)str;
	i = 0;
	while (i < n)
	{
		if (s[i] == c)
			return ((void *)(s + i));
		i++;
	}
	return (NULL);
}
