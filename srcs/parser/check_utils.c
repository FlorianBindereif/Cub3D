/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbindere <fbindere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 21:58:08 by eozben            #+#    #+#             */
/*   Updated: 2022/04/28 20:49:50 by fbindere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	is_empty_tile(char tile)
{
	if (tile == ' ' || tile == '\0')
		return (1);
	return (0);
}

void	check_valid_zero(t_cub *cub, int x, int y)
{
	int	i;
	int	j;

	i = -1;
	while (i < 2)
	{
		j = -1;
		while (j < 2)
		{
			if (is_empty_tile(cub->map.map[y + i][x + j]))
				map_error(cub, NULL, "Invalid map configuration");
			j++;
		}
		i++;
	}
}

int	is_player(char tile)
{
	if (tile == 'N')
		return (1);
	if (tile == 'E')
		return (1);
	if (tile == 'S')
		return (1);
	if (tile == 'W')
		return (1);
	return (0);
}

int	is_sprite(char c)
{
	if (c == 'D' || c == 'L' || c == 'B' || c == 'P' || c == 'F')
		return (1);
	return (0);
}
