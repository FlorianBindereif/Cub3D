/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_sprites.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbindere <fbindere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 20:53:00 by fbindere          #+#    #+#             */
/*   Updated: 2022/04/29 22:03:06 by fbindere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	draw_stripe(t_cub *cub, t_spr *sprite, t_ray *ray, int stripe)
{
	t_coord			tex;
	int				d;
	int				y;
	unsigned int	color;

	tex.x = (int)(256 * (stripe - (-sprite->width / 2 + sprite->screen.x))
			* sprite->texture->width / sprite->width) / 256;
	if (sprite->transf.y > 0 && stripe > 0 && stripe < WIN_WIDTH
		&& sprite->transf.y < ray->perp_wall_dist[stripe])
	{
		y = sprite->start.y;
		while (y < sprite->end.y)
		{
			d = y * 256 - WIN_HEIGHT * 128 + sprite->height * 128;
			tex.y = ((d * sprite->texture->height) / sprite->height) / 256;
			color = mlx_pixel_read(sprite->texture, tex.x, tex.y);
			if ((sprite->type == FOE && color != 9961608)
				|| (sprite->type != FOE && color != 0))
				ft_mlx_pixel_put(&cub->img, stripe, y, color);
			y++;
		}
	}
}

void	get_sprite_texture(t_cub *cub, t_spr *sprite, int i)
{
	static unsigned int	enemy_frame;

	sprite->type = cub->map.map_spr[i].type;
	if (sprite->type == FOE)
	{
		sprite->texture = &(cub->map.enemy[enemy_frame / 10]);
		enemy_frame++;
		if (enemy_frame == 50)
			enemy_frame = 0;
	}
	else
		sprite->texture = &cub->map.sprites[sprite->type];
}

void	draw_sprite(t_cub *cub, t_spr *sprite, t_ray *ray)
{
	int					stripe;

	stripe = sprite->start.x;
	while (stripe < sprite->end.x)
	{	
		draw_stripe(cub, sprite, ray, stripe);
		stripe++;
	}
}
