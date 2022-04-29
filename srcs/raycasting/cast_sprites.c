/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbindere <fbindere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 20:51:14 by fbindere          #+#    #+#             */
/*   Updated: 2022/04/29 22:02:39 by fbindere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	get_sprite_measures(t_spr *sprite)
{
	sprite->height = abs((int)(WIN_HEIGHT / sprite->transf.y));
	sprite->start.y= -sprite->height / 2 + WIN_HEIGHT / 2;
	if (sprite->start.y < 0)
		sprite->start.y = 0;
	sprite->end.y = sprite->height / 2 + WIN_HEIGHT / 2;
	if (sprite->end.y >= WIN_HEIGHT)
		sprite->end.y = WIN_HEIGHT - 1;
	sprite->width = abs((int)(WIN_HEIGHT / sprite->transf.y));
	sprite->start.x = -sprite->width / 2 + sprite->screen.x;
	if (sprite->start.x < 0)
		sprite->start.x = 0;
	sprite->end.x = sprite->width / 2 + sprite->screen.x;
	if (sprite->end.x >= WIN_WIDTH)
		sprite->end.x = WIN_WIDTH - 1;
}

static void	get_sprite_pos(t_cub *cub, t_spr *sprite, int i)
{
	t_point	spr_pos;
	double	inv_det;

	spr_pos.x = cub->map.map_spr[i].coord.x - cub->player.pos.x;
	spr_pos.y = cub->map.map_spr[i].coord.y - cub->player.pos.y;
	inv_det = 1.0 / (cub->camera.plane.x * cub->player.dir.y
			- cub->player.dir.x * cub->camera.plane.y);
	sprite->transf.x = inv_det * (cub->player.dir.y * spr_pos.x
			- cub->player.dir.x * spr_pos.y);
	sprite->transf.y = inv_det * (-cub->camera.plane.y * spr_pos.x
			+ cub->camera.plane.x * spr_pos.y);
	sprite->screen.x = (int)((WIN_WIDTH / 2)
			* (1 + sprite->transf.x / sprite->transf.y));
}

static void	sort_sprites(t_cub *cub)
{
	int		x;
	int		y;
	t_spr	temp;

	x = 0;
	while (x < cub->map.spr_count - 1)
	{
		y = 0;
		while (y < cub->map.spr_count - x - 1)
		{
			if (cub->map.map_spr[y].distance < cub->map.map_spr[y + 1].distance)
			{
				temp = cub->map.map_spr[y];
				cub->map.map_spr[y] = cub->map.map_spr[y + 1];
				cub->map.map_spr[y + 1] = temp;
			}
			y++;
		}
		x++;
	}
}

static void	get_distance_sprites(t_cub *cub)
{
	int	i;

	i = 0;
	while (i < cub->map.spr_count)
	{
		cub->map.map_spr[i].distance
			= (cub->player.pos.x - cub->map.map_spr[i].coord.x)
			* (cub->player.pos.x - cub->map.map_spr[i].coord.x)
			+ (cub->player.pos.y - cub->map.map_spr[i].coord.y)
			* (cub->player.pos.y - cub->map.map_spr[i].coord.y);
		i++;
	}
}

void	cast_sprites(t_cub *cub, t_ray *ray)
{
	int		i;
	t_spr	sprite;

	get_distance_sprites(cub);
	sort_sprites(cub);
	i = 0;
	while (i < cub->map.spr_count)
	{
		get_sprite_pos(cub, &sprite, i);
		get_sprite_measures(&sprite);
		get_sprite_texture(cub, &sprite, i);
		draw_sprite(cub, &sprite, ray);
		i++;
	}
}
