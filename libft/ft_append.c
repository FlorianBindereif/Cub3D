/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_append.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbindere <fbindere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 20:04:25 by fbindere          #+#    #+#             */
/*   Updated: 2022/01/05 20:04:42 by fbindere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_append(char *line, char c)
{
	int		length;
	int		i;
	char	*longer;

	if (line == NULL)
		return (NULL);
	length = ft_strlen(line);
	longer = ft_calloc(length + 2, sizeof(char));
	if (longer == NULL)
		ft_free((void *)&line, ft_strlen(line));
	i = 0;
	while (line && line[i] != '\0')
	{
		longer[i] = line[i];
		i++;
	}
	if (longer)
		longer[i] = c;
	if (line)
		free(line);
	return (longer);
}
