/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   key_presses.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: eozben <eozben@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/27 21:34:55 by eozben            #+#    #+#             */
/*   Updated: 2022/04/29 18:46:12 by eozben           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	release_keys(int keycode, t_cub *cub)
{
	if (keycode == W_KEY)
		cub->camera.pressed_keys[0] = 0;
	else if (keycode == S_KEY)
		cub->camera.pressed_keys[1] = 0;
	else if (keycode == D_KEY)
		cub->camera.pressed_keys[2] = 0;
	else if (keycode == A_KEY)
		cub->camera.pressed_keys[3] = 0;
	else if (keycode == LEFT_KEY)
		cub->camera.pressed_keys[4] = 0;
	else if (keycode == RIGHT_KEY)
		cub->camera.pressed_keys[5] = 0;
	return (0);
}

int	press_keys(int keycode, t_cub *cub)
{
	if (keycode == ESC_KEY)
		close_win(cub);
	if (keycode == ENTER_KEY)
		door(cub);
	if (keycode == W_KEY)
		cub->camera.pressed_keys[0] = 1;
	else if (keycode == S_KEY)
		cub->camera.pressed_keys[1] = 1;
	else if (keycode == D_KEY)
		cub->camera.pressed_keys[2] = 1;
	else if (keycode == A_KEY)
		cub->camera.pressed_keys[3] = 1;
	else if (keycode == LEFT_KEY)
		cub->camera.pressed_keys[4] = 1;
	else if (keycode == RIGHT_KEY)
		cub->camera.pressed_keys[5] = 1;
	return (0);
}

int	key_hooks(t_cub *cub)
{
	if (cub->camera.pressed_keys[0])
		move_forward(cub);
	if (cub->camera.pressed_keys[1])
		move_backward(cub);
	if (cub->camera.pressed_keys[2])
		move_right(cub);
	if (cub->camera.pressed_keys[3])
		move_left(cub);
	if (cub->camera.pressed_keys[4])
		turn_left(cub);
	if (cub->camera.pressed_keys[5])
		turn_right(cub);
	return (0);
}
