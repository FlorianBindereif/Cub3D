/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   foe.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbindere <fbindere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 17:02:27 by fbindere          #+#    #+#             */
/*   Updated: 2022/04/29 21:19:47 by fbindere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	foe_death(t_cub *cub)
{
	int	i;

	i = 0;
	while (i < cub->map.spr_count)
	{
		if (cub->map.map_spr[i].type == FOE)
		{
			if ((int)cub->map.map_spr[i].coord.x == (int)(cub->player.pos.x) &&
			(int)cub->map.map_spr[i].coord.y == (int)(cub->player.pos.y))
			{
				printf("\n__________________Cub3d________________________");
				printf("\n-----------------------------------------------\n");
				printf("		You died!\n");
				printf(" Try again or consider lowering difficulty, noob");
				printf("\n ----------------------------------------------\n");
				close_win(cub);
			}
		}
	i++;
	}
}

static int	check_valid_move(t_cub *cub, double new_x, double new_y)
{
	if (is_obstacle(cub->map.map[(int)(new_y + 0.5)][(int)(new_x + 0.5)]))
		return (1);
	if (is_obstacle(cub->map.map[(int)(new_y - 0.5)][(int)(new_x - 0.5)]))
		return (1);
	if (is_obstacle(cub->map.map[(int)(new_y - 0.5)][(int)(new_x + 0.5)]))
		return (1);
	if (is_obstacle(cub->map.map[(int)(new_y + 0.5)][(int)(new_x - 0.5)]))
		return (1);
	return (0);
}

static void	get_new_pos(t_cub *cub, int i)
{
	double		new_x;
	double		new_y;

	while (1)
	{
		new_x = cub->map.map_spr[i].coord.x
			+ (DIFFICULTY * cub->map.map_spr[i].direction.x);
		new_y = cub->map.map_spr[i].coord.y
			+ (DIFFICULTY * cub->map.map_spr[i].direction.y);
		if (check_valid_move(cub, new_x, new_y))
		{
			if (rand() % 2 == 0)
				cub->map.map_spr[i].direction.x *= -1;
			else
				cub->map.map_spr[i].direction.y *= -1;
			continue ;
		}
		else
		{
			cub->map.map_spr[i].coord.x = new_x;
			cub->map.map_spr[i].coord.y = new_y;
			return ;
		}
	}
}

static int	check_moveability(t_cub *cub, int i)
{
	t_coord	pos;

	pos.x = (int)cub->map.map_spr[i].coord.x;
	pos.y = (int)cub->map.map_spr[i].coord.y;
	if (!is_obstacle(cub->map.map[pos.y - 1][(pos.x)]))
		return (1);
	if (!is_obstacle(cub->map.map[pos.y - 1][(pos.x - 1)]))
		return (1);
	if (!is_obstacle(cub->map.map[pos.y - 1][(pos.x - 1)]))
		return (1);
	if (!is_obstacle(cub->map.map[pos.y + 1][(pos.x - 1)]))
		return (1);
	if (!is_obstacle(cub->map.map[pos.y + 1][(pos.x)]))
		return (1);
	if (!is_obstacle(cub->map.map[pos.y + 1][(pos.x + 1)]))
		return (1);
	if (!is_obstacle(cub->map.map[pos.y][(pos.x + 1)]))
		return (1);
	if (!is_obstacle(cub->map.map[pos.y][(pos.x + 1)]))
		return (1);
	return (0);
}

void	foe_move(t_cub *cub)
{
	int	i;

	i = 0;
	while (i < cub->map.spr_count)
	{
		if (cub->map.map_spr[i].type == FOE)
		{
			if (cub->map.map_spr[i].direction.x == 0)
			{
				cub->map.map_spr[i].direction.x = 1;
				cub->map.map_spr[i].direction.y = 1;
			}
			if (check_moveability(cub, i))
				get_new_pos(cub, i);
		}
		i++;
	}
}
