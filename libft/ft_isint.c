/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isint.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozben <eozben@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/14 21:06:46 by eozben            #+#    #+#             */
/*   Updated: 2021/10/21 15:35:56 by eozben           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isint(char *number)
{
	int		tmp;
	char	*save;

	if (number == NULL)
		return (0);
	tmp = 0;
	save = ft_itoa(ft_atoi(number));
	if (ft_strcmp(save, number))
		tmp = 1;
	free(save);
	return (tmp);
}
