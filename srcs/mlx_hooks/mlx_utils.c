/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mlx_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbindere <fbindere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 22:12:55 by fbindere          #+#    #+#             */
/*   Updated: 2022/04/29 22:12:57 by fbindere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	ft_mlx_pixel_put(t_img *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

unsigned int	mlx_pixel_read(t_img *data, int x, int y)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	return (*(unsigned int *)dst);
}

int	close_win(t_cub *cub)
{
	mlx_destroy_image(cub->win.mlx, cub->img.img);
	mlx_destroy_window(cub->win.mlx, cub->win.mlx_win);
	free_map(cub);
	exit(EXIT_SUCCESS);
	return (0);
}

int	init_win_img(t_cub *cub)
{
	cub->win.mlx = mlx_init();
	cub->win.mlx_win = mlx_new_window(cub->win.mlx, WIN_WIDTH, WIN_HEIGHT,
			"cub3d1337");
	cub->img.img = mlx_new_image(cub->win.mlx, WIN_WIDTH, WIN_HEIGHT);
	cub->img.addr = mlx_get_data_addr(cub->img.img, &cub->img.bits_per_pixel,
			&cub->img.line_length, &cub->img.endian);
	return (0);
}

int	mlx_hooks(t_cub *cub)
{
	mlx_hook(cub->win.mlx_win, 17, 0, close_win, cub);
	mlx_hook(cub->win.mlx_win, ON_KEYDOWN, 0, press_keys, cub);
	mlx_hook(cub->win.mlx_win, 3, 0, release_keys, cub);
	mlx_hook(cub->win.mlx_win, 4, 0, register_mouseclick, cub);
	mlx_hook(cub->win.mlx_win, 5, 0, unregister_mouseclick, cub);
	mlx_hook(cub->win.mlx_win, 6, 0, mouse_move, cub);
	return (0);
}
