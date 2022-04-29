/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_textures.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbindere <fbindere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 19:09:21 by fbindere          #+#    #+#             */
/*   Updated: 2022/04/28 20:45:29 by fbindere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	open_texture_sprites(t_cub *cub)
{
	open_xpm_file(BARREL, "textures/barrel.xpm", cub->map.sprites, cub);
	open_xpm_file(PILLAR, "textures/pillar.xpm", cub->map.sprites, cub);
	open_xpm_file(LAMP, "textures/greenlight.xpm", cub->map.sprites, cub);
}

static void	open_texture_enemy(t_cub *cub)
{
	open_xpm_file(0, "textures/enemy_0.xpm", cub->map.enemy, cub);
	open_xpm_file(1, "textures/enemy_1.xpm", cub->map.enemy, cub);
	open_xpm_file(2, "textures/enemy_2.xpm", cub->map.enemy, cub);
	open_xpm_file(3, "textures/enemy_3.xpm", cub->map.enemy, cub);
	open_xpm_file(4, "textures/enemy_4.xpm", cub->map.enemy, cub);
}

static void	open_texture_door(t_cub *cub)
{
	t_img	*tex;

	tex = &cub->map.texture[DOOR];
	tex->img = mlx_xpm_file_to_image(
			cub->win.mlx, "textures/door.xpm", &tex->width, &tex->height);
	if (!tex->img)
		map_error(cub, NULL, "invalid texture path");
	tex->addr = mlx_get_data_addr(tex->img, &tex->bits_per_pixel,
			&tex->line_length, &tex->endian);
}

static void	open_texture_wall(t_cub *cub)
{
	int		i;
	t_img	*tex;

	i = 0;
	while (i < 4)
	{
		tex = &cub->map.texture[i];
		tex->img = mlx_xpm_file_to_image(
				cub->win.mlx, cub->map.paths[i], &tex->width, &tex->height);
		if (!tex->img)
			map_error(cub, NULL, "invalid texture path");
		tex->addr = mlx_get_data_addr(tex->img, &tex->bits_per_pixel,
				&tex->line_length, &tex->endian);
		i++;
	}
}

void	open_textures(t_cub *cub)
{
	open_texture_wall(cub);
	open_texture_door(cub);
	open_texture_sprites(cub);
	open_texture_enemy(cub);
}
