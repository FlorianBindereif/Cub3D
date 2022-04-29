/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   camera_move.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbindere <fbindere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 21:31:36 by eozben            #+#    #+#             */
/*   Updated: 2022/04/28 19:02:18 by fbindere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	turn_left(t_cub *cub)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = cub->player.dir.x;
	old_plane_x = cub->camera.plane.x;
	cub->player.dir.x = cub->player.dir.x * cos(ROTSPEED)
		- cub->player.dir.y * sin(ROTSPEED);
	cub->player.dir.y = old_dir_x * sin(ROTSPEED)
		+ cub->player.dir.y * cos(ROTSPEED);
	cub->camera.plane.x = cub->camera.plane.x * cos(ROTSPEED)
		- cub->camera.plane.y * sin(ROTSPEED);
	cub->camera.plane.y = old_plane_x * sin(ROTSPEED)
		+ cub->camera.plane.y * cos(ROTSPEED);
}

void	turn_right(t_cub *cub)
{
	double	old_dir_x;
	double	old_plane_x;

	old_dir_x = cub->player.dir.x;
	old_plane_x = cub->camera.plane.x;
	cub->player.dir.x = cub->player.dir.x * cos(-ROTSPEED)
		- cub->player.dir.y * sin(-ROTSPEED);
	cub->player.dir.y = old_dir_x * sin(-ROTSPEED)
		+ cub->player.dir.y * cos(-ROTSPEED);
	cub->camera.plane.x = cub->camera.plane.x * cos(-ROTSPEED)
		- cub->camera.plane.y * sin(-ROTSPEED);
	cub->camera.plane.y = old_plane_x * sin(-ROTSPEED)
		+ cub->camera.plane.y * cos(-ROTSPEED);
}

int	mouse_move(int x, int y, t_cub *cub)
{
	static int	old_x;

	if (cub->camera.pressed_mb)
	{
		if (x <= WIN_WIDTH && x >= 0 && y <= WIN_HEIGHT && y >= 0)
		{
			if (x < old_x)
				turn_left(cub);
			else if (x > old_x)
				turn_right(cub);
		}
	}
	old_x = x;
	return (0);
}
