/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_map.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbindere <fbindere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 20:02:44 by fbindere          #+#    #+#             */
/*   Updated: 2022/04/29 21:09:55 by fbindere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static int	check_x_border(char *s, int i)
{
	while (s[i])
	{
		if (ft_is_whitespace(s[i]))
		{
			i++;
			continue ;
		}
		if (s[i] != '1')
			return (0);
		i++;
	}
	return (1);
}

static int	check_border(t_cub *cub)
{
	int	y;

	if (!check_x_border(cub->map.map[0], skip_whitespaces(cub->map.map[0])))
		map_error(cub, NULL, "Invalid vertical border");
	if (!check_x_border(cub->map.map[cub->map.map_height - 1],
			skip_whitespaces(cub->map.map[cub->map.map_height - 1])))
		map_error(cub, NULL, "Invalid vertical border");
	y = 1;
	while (y < cub->map.map_height - 1)
	{
		if (cub->map.map[y][skip_whitespaces(cub->map.map[y])] != '1')
			map_error(cub, NULL, "Invalid border");
		y++;
	}
	return (1);
}

static void	parse_sprite(char c, t_cub *cub, int x, int y)
{
	if (c == 'D')
	{
		if (cub->map.door_count > 15)
			map_error(cub, NULL, "More than 15 doors");
		cub->map.map_doors[cub->map.door_count].x = x;
		cub->map.map_doors[cub->map.door_count].y = y;
		cub->map.door_count += 1;
	}
	else if (c == 'L' || c == 'B' || c == 'P' || c == 'F')
	{
		if (cub->map.spr_count > 150)
			map_error(cub, NULL, "More than 150 sprites");
		if (c == 'L')
			cub->map.map_spr[cub->map.spr_count].type = LAMP;
		else if (c == 'B')
			cub->map.map_spr[cub->map.spr_count].type = BARREL;
		else if (c == 'P')
			cub->map.map_spr[cub->map.spr_count].type = PILLAR;
		else if (c == 'F')
			cub->map.map_spr[cub->map.spr_count].type = FOE;
		cub->map.map_spr[cub->map.spr_count].coord.x = x + 0.5;
		cub->map.map_spr[cub->map.spr_count].coord.y = y + 0.5;
		cub->map.spr_count += 1;
	}
}

static int	player_values(t_map *map, t_player *player, int x, int y)
{
	static int	playercount;

	if (x == 0 || y == 0)
		return (playercount);
	player->pos.x = x + 0.5;
	player->pos.y = y + 0.5;
	if (map->map[y][x] == 'N')
		map->p_dir = NORTH;
	else if (map->map[y][x] == 'E')
		map->p_dir = EAST;
	else if (map->map[y][x] == 'S')
		map->p_dir = SOUTH;
	else if (map->map[y][x] == 'W')
		map->p_dir = WEST;
	playercount++;
	return (playercount);
}

void	check_map_validity(t_cub *cub, t_player *player)
{
	int	y;
	int	x;

	check_border(cub);
	y = 1;
	while (y < cub->map.map_height - 1)
	{
		x = 1;
		while (cub->map.map[y][x])
		{
			if (cub->map.map[y][x] == '0')
				check_valid_zero(cub, x, y);
			else if (is_player(cub->map.map[y][x]))
				player_values(&cub->map, player, x, y);
			else if (is_sprite(cub->map.map[y][x]))
				parse_sprite(cub->map.map[y][x], cub, x, y);
			else if (cub->map.map[y][x] != '1'
				&& !ft_is_whitespace(cub->map.map[y][x]))
				map_error(cub, NULL, "invalid map character");
			x++;
		}
		y++;
	}
	if (player_values(&cub->map, player, 0, 0) != 1)
		map_error(cub, NULL, "Invalid amount of players");
}
