/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbindere <fbindere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/28 20:14:57 by fbindere          #+#    #+#             */
/*   Updated: 2022/04/28 20:40:41 by fbindere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	open_xpm_file(int ident, char *path, t_img *img, t_cub *cub)
{
	t_img	*img_arr;

	img_arr = img;
	img_arr[ident].img = mlx_xpm_file_to_image(cub->win.mlx, path,
			&img_arr[ident].width, &img_arr[ident].height);
	if (!img_arr[ident].img)
		map_error(cub, NULL, "invalid texture path");
	img_arr[ident].addr = mlx_get_data_addr(img_arr[ident].img,
			&img_arr[ident].bits_per_pixel, &img_arr[ident].line_length,
			&img_arr[ident].endian);
	if (!img_arr[ident].addr)
		map_error(cub, NULL, "invalid texture address");
}
