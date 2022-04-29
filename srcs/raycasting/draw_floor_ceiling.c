/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbindere <fbindere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 16:41:45 by fbindere          #+#    #+#             */
/*   Updated: 2022/04/28 20:29:47 by fbindere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	cast_floor_ceiling(t_cub *cub)
{
	unsigned int	color;
	int				y;
	int				x;

	y = 0;
	while (y < WIN_HEIGHT)
	{
		x = 0;
		while (x < WIN_WIDTH)
		{
			color = cub->map.f_color;
			color = (color >> 1) & 8355711;
			ft_mlx_pixel_put(&cub->img, x, y, color);
			color = cub->map.c_color;
			color = (color >> 1) & 8355711;
			ft_mlx_pixel_put(&cub->img, x, WIN_HEIGHT - y - 1, color);
			x++;
		}
		y++;
	}
}
