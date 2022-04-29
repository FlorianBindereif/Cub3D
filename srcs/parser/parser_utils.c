/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbindere <fbindere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 21:53:30 by eozben            #+#    #+#             */
/*   Updated: 2022/04/28 20:50:46 by fbindere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	ft_is_whitespace(char c)
{
	if (c == ' ' || c == '\t' || c == '\r')
		return (1);
	else
		return (0);
}

int	skip_whitespaces(char *str)
{
	int	i;

	i = 0;
	while (ft_is_whitespace(str[i]))
		i++;
	return (i);
}

int	ft_is_empty_line(char *s)
{
	int	i;

	i = 0;
	while (ft_is_whitespace(s[i]))
		i++;
	if (s[i] == '\n')
		return (1);
	return (0);
}

char	*get_next_written_line(int fd)
{
	char	*line;

	while (1)
	{
		line = get_next_line(fd);
		if (!line)
			return (NULL);
		if (!ft_is_empty_line(line))
			return (line);
		free(line);
	}
}

int	is_eof(int fd)
{
	char	*line;

	line = get_next_written_line(fd);
	if (line)
	{
		free(line);
		return (0);
	}
	return (1);
}
