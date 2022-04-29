/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbindere <fbindere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 20:03:14 by fbindere          #+#    #+#             */
/*   Updated: 2022/04/29 16:27:27 by fbindere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	get_map_size(char *map_line, int *longest_line, int *line_count)
{
	int	i;
	int	current_line;

	current_line = 0;
	*longest_line = 0;
	*line_count = 0;
	i = 0;
	while (map_line[i])
	{
		if (map_line[i] == '\n')
		{
			*line_count += 1;
			if (current_line > *longest_line)
				*longest_line = current_line;
			current_line = 0;
		}
		i++;
		current_line++;
	}
	if (map_line[i - 1] != '\n' && !map_line[i])
		*line_count += 1;
}

static int	get_line_length(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '\n')
			return (i);
		i++;
	}
	return (i - 1);
}

static void	create_map_array(t_cub *cub, char *map_line)
{
	int	i;
	int	j;

	get_map_size(map_line, &cub->map.map_length, &cub->map.map_height);
	cub->map.map = ft_calloc(cub->map.map_height + 1, cub->map.map_length);
	if (!cub->map.map)
		map_error(cub, map_line, "Allocating map");
	i = 0;
	j = 0;
	while (map_line[i])
	{
		cub->map.map[j] = ft_substr(map_line, i,
				get_line_length(&map_line[i]) + 1);
		if (cub->map.map[j][ft_strlen(cub->map.map[j]) - 1] == '\n')
			cub->map.map[j][ft_strlen(cub->map.map[j]) - 1] = '\0';
		i += get_line_length(&map_line[i]) + 1;
		j++;
	}
	free(map_line);
}

static char	*append_mapline(t_cub *cub, char *map_line, char *line)
{
	char	*tmp;

	tmp = map_line;
	map_line = ft_strjoin(map_line, line);
	free(tmp);
	if (!map_line)
		map_error(cub, line, "Allocating map");
	return (map_line);
}

void	read_map(t_cub *cub)
{
	char	*line;
	char	*map_line;

	map_line = get_next_written_line(cub->map.fd);
	if (!map_line)
		map_error(cub, NULL, "No map specified");
	while (1)
	{
		line = get_next_line(cub->map.fd);
		if (!line)
			break ;
		if (ft_is_empty_line(line))
		{
			free(line);
			if (is_eof(cub->map.fd))
				break ;
			map_error(cub, map_line, "Empty line in map");
		}
		map_line = append_mapline(cub, map_line, line);
		free(line);
	}
	create_map_array(cub, map_line);
}
