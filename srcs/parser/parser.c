/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fbindere <fbindere@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/29 22:13:09 by fbindere          #+#    #+#             */
/*   Updated: 2022/04/29 22:13:11 by fbindere         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/cub3d.h"

void	parse_cub_file(t_cub *cub, char **argv)
{	
	cub->map.fd = open(argv[1], O_RDWR);
	if (cub->map.fd == ERROR)
		map_error(cub, NULL, "Bad .cub img_arr");
	read_textures(cub);
	read_map(cub);
	check_map_validity(cub, &cub->player);
	close(cub->map.fd);
}
