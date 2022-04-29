/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minimap.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbindere <fbindere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 20:21:16 by fbindere          #+#    #+#             */
/*   Updated: 2022/04/28 20:36:07 by fbindere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	colour_pixel(t_cub *cub, int x, int y)
{
	int	map_y;
	int	map_x;

	map_y = (int)((y / cub->map.mmap.tile_height)
			+ cub->player.pos.y - MMAPZOOM);
	map_x = (int)((x / cub->map.mmap.tile_width)
			+ cub->player.pos.x - MMAPZOOM);
	if (map_x >= 0 && map_x <= cub->map.map_length - 1
		&& map_y >= 0 && map_y <= cub->map.map_height - 1
		&& cub->map.map[map_y][map_x] == '1')
		ft_mlx_pixel_put(&cub->img, x, y, 0);
	else if (map_x == (int)cub->player.pos.x
		&& map_y == (int)cub->player.pos.y)
		ft_mlx_pixel_put(&cub->img, x, y, 25600);
}

void	draw_minimap(t_cub *cub)
{
	int	x;
	int	y;

	cub->map.mmap.tile_width = cub->map.mmap.width / (2 * MMAPZOOM + 1);
	cub->map.mmap.tile_height = cub->map.mmap.height / (2 * MMAPZOOM + 1);
	y = 0;
	while (y < cub->map.mmap.height)
	{
		x = 0;
		while (x < cub->map.mmap.width)
		{
			colour_pixel(cub, x, y);
			x++;
		}
		y++;
	}
}
