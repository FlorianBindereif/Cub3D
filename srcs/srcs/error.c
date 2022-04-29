/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbindere <fbindere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/15 22:41:17 by eozben            #+#    #+#             */
/*   Updated: 2022/04/29 21:33:28 by fbindere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	free_map(t_cub *cub)
{
	int	i;

	if (cub->map.fd)
		close(cub->map.fd);
	i = 0;
	while (i < 4)
		free(cub->map.paths[i++]);
	i = 0;
	while (i < 4 && cub->map.texture[i].img)
		mlx_destroy_image(cub->win.mlx, cub->map.texture[i++].img);
	while (i < 5 && cub->map.texture[i].img)
		mlx_destroy_image(cub->win.mlx, cub->map.texture[i++].img);
	i = 0;
	while (i < 3 && cub->map.sprites[i].img)
		mlx_destroy_image(cub->win.mlx, cub->map.sprites[i++].img);
	while (i < 5 && cub->map.enemy[i].img)
		mlx_destroy_image(cub->win.mlx, cub->map.enemy[i++].img);
	if (cub->map.doors->img)
		mlx_destroy_image(cub->win.mlx, cub->map.doors->img);
	i = 0;
	while (cub->map.map && cub->map.map[i])
		free(cub->map.map[i++]);
	free(cub->map.map);
}

void	map_error(t_cub *cub, char *str, char *error_msg)
{
	free_map(cub);
	if (str)
		free(str);
	printf("Error\n%s\n", error_msg);
	exit(EXIT_FAILURE);
}
