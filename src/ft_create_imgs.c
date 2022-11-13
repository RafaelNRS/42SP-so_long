/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_imgs.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranascim <ranascim@42.student.42sp.org.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 07:13:45 by ranascim          #+#    #+#             */
/*   Updated: 2022/11/13 10:45:32 by ranascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_img	ft_create_img(t_data *data, char *imgPath)
{
	t_img	new_img;

	new_img.mlx_img = mlx_xpm_file_to_image(
			data->mlx_ptr, imgPath, &new_img.width, &new_img.height
			);
	new_img.addr = mlx_get_data_addr(
			new_img.mlx_img, &new_img.bpp, &new_img.line_len, &new_img.endian
			);
	return (new_img);
}

void	ft_create_imgs(t_data *data)
{
	data->sprites.player = ft_create_img(data, GHOST_RIGHT_PATH);
	data->sprites.wall = ft_create_img(data, WALL_PATH);
	data->sprites.empty_space = ft_create_img(data, EMPTY_SPACE_PATH);
	data->sprites.exit = ft_create_img(data, CLOSED_DOOR_PATH);
	data->sprites.collectible = ft_create_img(data, COLLECTIBLE_PATH);
}
