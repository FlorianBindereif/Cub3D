/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub3d.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbindere <fbindere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/12 19:00:27 by eozben            #+#    #+#             */
/*   Updated: 2022/04/29 19:12:55 by fbindere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CUB3D_H
# define CUB3D_H

# include "../../libft/libft.h"
# include "../../mlx/mlx.h"
# include "cub3d_defines.h"
# include "cub3d_structs.h"
# include <stdio.h>
# include <fcntl.h>
# include <math.h>
# include <stdbool.h>

/* Error Functions */
void			map_error(t_cub *cub, char *str, char *error_msg);
void			free_map(t_cub *cub);
int				close_win(t_cub *cub);

/* Parser Functions */
int				ft_is_empty_line(char *s);
int				ft_is_whitespace(char c);
int				skip_whitespaces(char *str);
void			parse_cub_file(t_cub *cub, char **argv);
int				is_eof(int fd);
int				is_empty_tile(char tile);
void			check_valid_zero(t_cub *cub, int x, int y);
int				is_player(char tile);
int				is_sprite(char c);
int				read_colour(t_cub *cub, char *str, int i);
int				read_textures(t_cub *cub);
void			read_map(t_cub *cub);
void			check_map_validity(t_cub *cub, t_player *player);
char			*get_next_written_line(int fd);

/* Mlx Functions */
void			ft_mlx_pixel_put(t_img *data, int x, int y, int color);
unsigned int	mlx_pixel_read(t_img *data, int x, int y);
int				mlx_hooks(t_cub *cub);
int				key_hooks(t_cub *cub);
int				mouse_move(int x, int y, t_cub *cub);
int				press_keys(int keycode, t_cub *cub);
int				release_keys(int keycode, t_cub *cub);
int				unregister_mouseclick(int button, int x, int y, t_cub *cub);
int				register_mouseclick(int button, int x, int y, t_cub *cub);
void			open_xpm_file(int ident, char *path, t_img *img, t_cub *cub);
int				init_win_img(t_cub *cub);

/* Texture Functions */
void			open_textures(t_cub *cub);
int				read_textures(t_cub *cub);
void			get_sprite_texture(t_cub *cub, t_spr *sprite, int i);
void			draw_sprite(t_cub *cub, t_spr *sprite, t_ray *ray);
void			open_texture_files(t_cub *cub);

/* Movement */
void			move_right(t_cub *cub);
void			move_left(t_cub *cub);
void			move_forward(t_cub *cub);
void			move_backward(t_cub *cub);
void			turn_right(t_cub *cub);
void			turn_left(t_cub *cub);

/* Raycasting */
void			calculate_frame(t_cub *cub);
int				cub3d(t_cub *cub);
void			set_camera_vector(t_cub *cub);
void			cast_sprites(t_cub *cub, t_ray *ray);
void			door(t_cub *cub);
int				is_obstacle(char c);
void			draw_minimap(t_cub *cub);
void			door(t_cub *cub);
void			cast_floor_ceiling(t_cub *cub);
void			cast_walls(t_cub *cub, t_ray *ray);
void			draw_line(t_ray *ray, t_cub *cub, int x);

/* foe */
void			foe_move(t_cub *cub);
void			foe_death(t_cub *cub);

#endif
