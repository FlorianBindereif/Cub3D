/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printnl.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozben <eozben@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 21:03:19 by eozben            #+#    #+#             */
/*   Updated: 2022/01/11 21:04:44 by eozben           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_printnl_fd(char *s, int fd)
{
	int		i;
	int		cc;

	if (s == NULL)
		return (0);
	cc = 0;
	i = 0;
	while (s[i] != '\0')
	{
		cc += write(fd, &s[i], 1);
		i++;
	}
	cc += write (fd, "\n", 1);
	return (cc);
}
