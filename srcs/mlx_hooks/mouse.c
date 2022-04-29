/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mouse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbindere <fbindere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 19:02:05 by fbindere          #+#    #+#             */
/*   Updated: 2022/04/28 19:02:48 by fbindere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

int	register_mouseclick(int button, int x, int y, t_cub *cub)
{
	(void)x;
	(void)y;
	if (button == 1)
		cub->camera.pressed_mb = 1;
	return (0);
}

int	unregister_mouseclick(int button, int x, int y, t_cub *cub)
{
	(void)x;
	(void)y;
	(void)cub;
	if (button == 1)
		cub->camera.pressed_mb = 0;
	return (0);
}
