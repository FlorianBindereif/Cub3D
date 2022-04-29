/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_walls.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbindere <fbindere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 20:27:10 by fbindere          #+#    #+#             */
/*   Updated: 2022/04/29 22:06:38 by fbindere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

static void	get_line_values(t_dline *line, t_ray *ray, int x)
{
	line->height = (int)(WIN_HEIGHT / ray->perp_wall_dist[x]);
	line->start = -line->height / 2 + WIN_HEIGHT / 2;
	if (line->start < 0)
		line->start = 0;
	line->end = line->height / 2 + WIN_HEIGHT / 2;
	if (line->end >= WIN_HEIGHT)
		line->end = WIN_HEIGHT - 1;
}

static void	get_texture_x(t_cub *cub, t_ray *ray, t_text *text, int x)
{
	double	wall_x;

	if (ray->hit == x_side)
		wall_x = cub->player.pos.y + ray->perp_wall_dist[x] * ray->dir.y;
	else
		wall_x = cub->player.pos.x + ray->perp_wall_dist[x] * ray->dir.x;
	wall_x -= floor(wall_x);
	text->x = (int)(wall_x * (double)cub->map.texture[text->dir].width);
	if (ray->hit == x_side && ray->dir.x > 0)
		text->x = cub->map.texture[text->dir].width - text->x - 1;
	if (ray->hit == y_side && ray->dir.y < 0)
		text->x = cub->map.texture[text->dir].width - text->x - 1;
}

static void	get_text_type(t_cub *cub, t_ray *ray, t_text *text)
{
	if (cub->map.map[ray->map.y][ray->map.x] == 'D')
		text->dir = DOOR;
	else if (ray->hit == y_side)
	{
		if (ray->dir.y >= 0)
			text->dir = NORTH;
		else
			text->dir = SOUTH;
	}
	else if (ray->hit == x_side)
	{
		if (ray->dir.x >= 0)
			text->dir = EAST;
		else
			text->dir = WEST;
	}
}

static void	get_text_values(t_cub *cub, t_dline *line, t_text *text)
{
	text->step = 1.0 * cub->map.texture[text->dir].height / line->height;
	text->pos = (line->start - WIN_HEIGHT / 2 + line->height / 2) * text->step;
}

void	draw_line(t_ray *ray, t_cub *cub, int x)
{
	t_dline			line;
	t_text			text;	
	unsigned int	color;
	int				y;

	get_line_values(&line, ray, x);
	get_text_type(cub, ray, &text);
	get_text_values(cub, &line, &text);
	get_texture_x(cub, ray, &text, x);
	y = line.start;
	while (y < line.end)
	{
		text.y = (int)text.pos & (cub->map.texture[text.dir].height - 1);
		text.pos += text.step;
		color = mlx_pixel_read(&cub->map.texture[text.dir], text.x, text.y);
		if (ray->hit == y_side)
			color = (color >> 1) & 8355711;
		ft_mlx_pixel_put(&cub->img, x, y, color);
		y++;
	}
}
