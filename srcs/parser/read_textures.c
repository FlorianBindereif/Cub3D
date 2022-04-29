/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbindere <fbindere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 20:38:22 by fbindere          #+#    #+#             */
/*   Updated: 2022/04/28 20:41:33 by fbindere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	create_trgb(int r, int g, int b)
{
	return (r << 16 | g << 8 | b);
}

int	read_colour(t_cub *cub, char *str, int i)
{
	char	**colour_array;
	int		colour[3];
	int		atoi_result;
	int		j;

	i += 1;
	i += skip_whitespaces(&str[i]);
	colour_array = ft_split(&str[i], ',');
	if (!colour_array)
		map_error(cub, str, "allocating floor colour");
	j = 0;
	while (colour_array[j])
	{
		if (!ft_atoi(colour_array[j], &atoi_result)
			|| (atoi_result > 255 || atoi_result < 0) || j > 2)
		{
			ft_free_strarray(colour_array);
			map_error(cub, str, "invalid colour code floor");
		}
		colour[j] = atoi_result;
		j++;
	}
	ft_free_strarray(colour_array);
	return (create_trgb(colour[0], colour[1], colour[2]));
}

char	*read_path(t_cub *cub, char *str, int i)
{
	char	*path;

	i += 2;
	i += skip_whitespaces(&str[i]);
	path = ft_strdup(&str[i]);
	if (!path)
		map_error(cub, str, "allocating texture path");
	return (path);
}

void	check_identifier(t_cub *cub, char *str)
{
	int	i;

	i = 0;
	str[ft_strlen(str) - 1] = '\0';
	i = skip_whitespaces(&str[i]);
	if (!ft_strncmp("NO", &str[i], 2))
		cub->map.paths[NORTH] = read_path(cub, str, i);
	else if (!ft_strncmp("SO", &str[i], 2))
		cub->map.paths[SOUTH] = read_path(cub, str, i);
	else if (!ft_strncmp("WE", &str[i], 2))
		cub->map.paths[WEST] = read_path(cub, str, i);
	else if (!ft_strncmp("EA", &str[i], 2))
		cub->map.paths[EAST] = read_path(cub, str, i);
	else if (str[i] == 'F')
		cub->map.f_color = read_colour(cub, &str[i], i);
	else if (str[i] == 'C')
		cub->map.c_color = read_colour(cub, &str[i], i);
	else
		map_error(cub, str, "no valid type identifier");
}

int	read_textures(t_cub *cub)
{
	char	*str;
	int		line_count;

	line_count = 0;
	while (line_count < 6)
	{
		str = get_next_line(cub->map.fd);
		if (!str)
			break ;
		if (!ft_is_empty_line(str))
		{
			check_identifier(cub, str);
			line_count++;
		}
		free(str);
	}
	if (line_count != 6)
		map_error(cub, NULL, "Invalid texture configuration");
	return (0);
}
