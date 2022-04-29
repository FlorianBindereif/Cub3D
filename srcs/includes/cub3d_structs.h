/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d_structs.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbindere <fbindere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 17:53:29 by eozben            #+#    #+#             */
/*   Updated: 2022/04/29 22:04:20 by fbindere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_STRUCTS_H
# define CUB3D_STRUCTS_H

# include "cub3d.h"

typedef struct s_coord
{
	int	x;
	int	y;
}				t_coord;

typedef enum e_sprite_type
{
	BARREL,
	PILLAR,
	LAMP,
	FOE,
}			t_stype;

typedef enum e_dir
{
	NORTH,
	EAST,
	SOUTH,
	WEST,
	DOOR,
}			t_dir;

typedef enum e_side
{
	x_side,
	y_side,
}			t_side;

typedef struct s_point
{
	double		x;
	double		y;
}				t_point;

typedef struct s_ray
{
	t_point		dir;
	t_point		side_dist;
	t_point		delta_dist;
	t_side		hit;
	t_coord		map;
	t_coord		step;
	double		perp_wall_dist[WIN_WIDTH];
}				t_ray;

typedef struct s_camera
{
	t_point	plane;
	int		pressed_mb;
	int		pressed_keys[6];
}				t_camera;

typedef struct s_player
{
	t_point	pos;
	t_point	dir;
}				t_player;

typedef struct s_img
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
	int		height;
	int		width;
}			t_img;

typedef struct s_spr
{
	t_point	coord;
	t_point	transf;
	t_coord	direction;
	t_stype	type;
	t_img	*texture;
	double	distance;
	t_coord	screen;
	int		height;
	int		width;
	t_coord	start;
	t_coord	end;
}			t_spr;

typedef struct s_minimap
{
	int		height;
	int		width;
	double	tile_width;
	double	tile_height;
}				t_mm;

typedef struct s_map
{
	int		fd;
	int		map_height;
	int		map_length;
	char	*paths[4];
	t_img	texture[5];
	t_img	sprites[3];
	t_img	enemy[5];
	t_img	doors[1];
	t_spr	map_spr[150];
	t_point	map_doors[15];
	t_mm	mmap;
	int		spr_count;
	int		door_count;
	int		f_color;
	int		c_color;
	t_dir	p_dir;
	char	**map;
}			t_map;

typedef struct s_win
{
	void	*mlx;
	void	*mlx_win;
}			t_win;

typedef struct s_cub
{
	t_camera	camera;
	t_map		map;
	t_player	player;
	t_img		img;
	t_win		win;
}				t_cub;

typedef struct s_dline
{
	int			height;
	int			start;
	int			end;
}				t_dline;

typedef struct s_text
{
	t_dir		dir;
	int			x;
	int			y;
	double		pos;
	double		step;
}				t_text;

#endif 