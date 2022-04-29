/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_freestrarray.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozben <eozben@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/24 23:11:23 by eozben            #+#    #+#             */
/*   Updated: 2022/01/11 22:33:48 by eozben           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_free_strarray(char **split)
{
	int	i;

	i = 0;
	if (split == NULL)
		return (0);
	while (split[i])
		free(split[i++]);
	if (split)
		free(split);
	return (0);
}
