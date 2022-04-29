/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cast_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozben <eozben@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 20:19:42 by fbindere          #+#    #+#             */
/*   Updated: 2022/04/29 18:46:34 by eozben           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	set_side_dist(t_ray *ray, t_player *player)
{
	if (ray->dir.x < 0)
	{
		ray->side_dist.x = (player->pos.x - ray->map_x) * ray->delta_dist.x;
		ray->step_x = -1;
	}
	else
	{
		ray->side_dist.x = (ray->map_x + 1 - player->pos.x) * ray->delta_dist.x;
		ray->step_x = 1;
	}
	if (ray->dir.y < 0)
	{
		ray->side_dist.y = (player->pos.y - ray->map_y) * ray->delta_dist.y;
		ray->step_y = -1;
	}
	else
	{
		ray->side_dist.y = (ray->map_y + 1 - player->pos.y) * ray->delta_dist.y;
		ray->step_y = 1;
	}
}

static void	set_delta_dist(t_ray *ray)
{
	if (ray->dir.x == 0)
		ray->delta_dist.x = INFINITY;
	else
		ray->delta_dist.x = fabs(1 / ray->dir.x);
	if (ray->dir.y == 0)
		ray->delta_dist.y = INFINITY;
	else
		ray->delta_dist.y = fabs(1 / ray->dir.y);
}

static void	set_ray_dir_vector(t_cub *cub, t_ray *ray, int x)
{
	double	camera_x;

	camera_x = 2 * x / (double)WIN_WIDTH - 1;
	ray->dir.x = cub->player.dir.x + cub->camera.plane.x * camera_x;
	ray->dir.y = cub->player.dir.y + cub->camera.plane.y * camera_x;
}

static void	perform_dda(t_ray *ray, t_cub *cub, int x)
{
	int	hit;

	hit = 0;
	while (hit == 0)
	{
		if (ray->side_dist.x < ray->side_dist.y)
		{
			ray->side_dist.x += ray->delta_dist.x;
			ray->map_x += ray->step_x;
			ray->hit = x_side;
		}
		else
		{
			ray->side_dist.y += ray->delta_dist.y;
			ray->map_y += ray->step_y;
			ray->hit = y_side;
		}
		if (is_obstacle(cub->map.map[ray->map_y][ray->map_x]))
			hit = 1;
	}
	if (ray->hit == x_side)
		ray->perp_wall_dist[x] = ray->side_dist.x - ray->delta_dist.x;
	else
		ray->perp_wall_dist[x] = ray->side_dist.y - ray->delta_dist.y;
}

void	cast_walls(t_cub *cub, t_ray *ray)
{
	int		x;

	x = 0;
	while (x < WIN_WIDTH)
	{
		set_ray_dir_vector(cub, ray, x);
		ray->map_x = (int)cub->player.pos.x;
		ray->map_y = (int)cub->player.pos.y;
		set_delta_dist(ray);
		set_side_dist(ray, &cub->player);
		perform_dda(ray, cub, x);
		draw_line(ray, cub, x);
		x++;
	}
}
