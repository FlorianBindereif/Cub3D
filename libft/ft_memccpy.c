/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozben <eozben@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/16 16:50:25 by eozben            #+#    #+#             */
/*   Updated: 2021/06/23 19:19:54 by eozben           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memccpy(void *dest, const void *src, int c, size_t n)
{
	size_t					i;
	unsigned char			ch;
	unsigned char			*destt;
	const unsigned char		*srcc;	

	ch = (unsigned char)c;
	destt = (unsigned char *)dest;
	srcc = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		destt[i] = srcc[i];
		if (srcc[i] == ch)
			return (dest + i + 1);
		i++;
	}
	return (NULL);
}
