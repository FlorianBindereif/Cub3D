/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozben <eozben@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/15 14:05:21 by eozben            #+#    #+#             */
/*   Updated: 2021/06/25 13:57:59 by eozben           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	size_t	i;
	size_t	src_len;

	i = 0;
	if (src == (char *) NULL)
		return ((size_t) NULL);
	src_len = ft_strlen(src);
	if (!dest || !src)
		return (0);
	if (!size)
		return (src_len);
	while (*(src + i) != '\0' && i < (size - 1) && size > 0)
	{
		*(dest + i) = *(src + i);
		i++;
	}
	if (size < src_len)
		*(dest + size - 1) = '\0';
	else if (size != 0)
		*(dest + i) = '\0';
	return (src_len);
}
