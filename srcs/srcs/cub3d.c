/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbindere <fbindere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 19:00:58 by eozben            #+#    #+#             */
/*   Updated: 2022/04/29 19:16:31 by fbindere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	set_starting_vectors(t_cub *cub)
{
	cub->player.dir.x = 0;
	cub->player.dir.y = 0;
	if (cub->map.p_dir == NORTH)
	{
		cub->player.dir.y = -1;
		cub->camera.plane.x = -0.66;
	}
	else if (cub->map.p_dir == EAST)
	{
		cub->player.dir.x = 1;
		cub->camera.plane.y = -0.66;
	}
	else if (cub->map.p_dir == SOUTH)
	{
		cub->player.dir.y = 1;
		cub->camera.plane.x = 0.66;
	}
	else if (cub->map.p_dir == WEST)
	{
		cub->player.dir.x = -1;
		cub->camera.plane.y = 0.66;
	}
}

void	set_minimap(t_cub *cub)
{
	cub->map.mmap.height = WIN_HEIGHT * MMAPSIZE;
	cub->map.mmap.width = WIN_WIDTH * MMAPSIZE;
}

int	cub3d(t_cub *cub)
{
	t_ray	ray;

	key_hooks(cub);
	foe_move(cub);
	cast_floor_ceiling(cub);
	cast_walls(cub, &ray);
	cast_sprites(cub, &ray);
	draw_minimap(cub);
	foe_death(cub);
	mlx_put_image_to_window(cub->win.mlx, cub->win.mlx_win, cub->img.img, 0, 0);
	return (0);
}

int	main(int argc, char *argv[])
{
	t_cub	cub;

	(void)argv;
	if (argc != 2)
		return (printf("Error \nInvalid amount of arguments\n"));
	ft_memset((void *)&cub, 0, sizeof(t_cub));
	init_win_img(&cub);
	parse_cub_file(&cub, argv);
	open_textures(&cub);
	set_starting_vectors(&cub);
	set_minimap(&cub);
	mlx_hooks(&cub);
	cub3d(&cub);
	mlx_loop_hook(cub.win.mlx, cub3d, &cub);
	mlx_loop(cub.win.mlx);
}
