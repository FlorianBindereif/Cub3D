/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_floor_ceiling.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbindere <fbindere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 16:41:45 by fbindere          #+#    #+#             */
/*   Updated: 2022/04/29 22:09:22 by fbindere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	cast_floor_ceiling(t_cub *cub)
{
	unsigned int	clr;
	t_coord			pixel;

	pixel.y = 0;
	while (pixel.y < WIN_HEIGHT)
	{
		pixel.x = 0;
		while (pixel.x < WIN_WIDTH)
		{
			clr = cub->map.f_color;
			clr = (clr >> 1) & 8355711;
			ft_mlx_pixel_put(&cub->img, pixel.x, pixel.y, clr);
			clr = cub->map.c_color;
			clr = (clr >> 1) & 8355711;
			ft_mlx_pixel_put(&cub->img, pixel.x, WIN_HEIGHT - pixel.y - 1, clr);
			pixel.x++;
		}
		pixel.y++;
	}
}
