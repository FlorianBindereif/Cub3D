/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozben <eozben@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 16:31:53 by eozben            #+#    #+#             */
/*   Updated: 2021/06/23 19:29:22 by eozben           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t dstsize)
{
	size_t		d_len;
	size_t		s_len;
	size_t		d_index;
	size_t		i;

	d_len = ft_strlen(dst);
	s_len = ft_strlen(src);
	d_index = d_len;
	i = 0;
	if (dstsize == 0)
		return (s_len);
	if (dstsize < d_len)
		return (s_len + dstsize);
	else
	{
		while (src[i] != '\0' && dstsize > 0 && d_index < dstsize - 1)
		{
			dst[d_index] = src[i];
			d_index++;
			i++;
		}
		dst[d_index] = '\0';
		return (d_len + s_len);
	}
}
