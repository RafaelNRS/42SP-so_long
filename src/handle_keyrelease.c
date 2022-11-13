/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_keyrelease.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranascim <ranascim@42.student.42sp.org.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 07:27:00 by ranascim          #+#    #+#             */
/*   Updated: 2022/11/13 10:45:27 by ranascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	handle_keyrelease(int keysym, t_data *data)
{
	if (keysym == XK_Escape)
	{
		ft_message(1, data);
		ft_destroy_imgs(data);
		exit(0);
	}
	else if (keysym == UP)
		ft_movement(data, data->map.width * -1);
	else if (keysym == LEFT)
	{
		mlx_destroy_image(data->mlx_ptr, data->sprites.player.mlx_img);
		data->sprites.player = ft_create_img(data, GHOST_LEFT_PATH);
		ft_movement(data, -1);
	}
	else if (keysym == DOWN)
		ft_movement(data, data->map.width);
	else if (keysym == RIGHT)
	{
		mlx_destroy_image(data->mlx_ptr, data->sprites.player.mlx_img);
		data->sprites.player = ft_create_img(data, GHOST_RIGHT_PATH);
		ft_movement(data, 1);
	}
	return (0);
}
