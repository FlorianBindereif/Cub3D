/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozben <eozben@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/06/17 12:42:02 by eozben            #+#    #+#             */
/*   Updated: 2021/06/23 19:30:24 by eozben           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *str, int c)
{
	int		i;

	i = 0;
	while (str[i] != '\0')
		i++;
	while (str[i] != c && &str[i] != &str[0])
		i--;
	if (str[i] == c)
		return ((char *)&str[i]);
	else
		return (NULL);
}
