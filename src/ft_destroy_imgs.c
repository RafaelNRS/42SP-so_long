/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_destroy_imgs.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranascim <ranascim@42.student.42sp.org.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 07:33:01 by ranascim          #+#    #+#             */
/*   Updated: 2022/11/13 07:33:03 by ranascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_destroy_imgs(t_data *data)
{
	mlx_destroy_image(data->mlx_ptr, data->sprites.player.mlx_img);
	mlx_destroy_image(data->mlx_ptr, data->sprites.wall.mlx_img);
	mlx_destroy_image(data->mlx_ptr, data->sprites.empty_space.mlx_img);
	mlx_destroy_image(data->mlx_ptr, data->sprites.exit.mlx_img);
	mlx_destroy_image(data->mlx_ptr, data->sprites.collectible.mlx_img);
	mlx_destroy_window(data->mlx_ptr, data->win_ptr);
	ft_destroy_display(data);
}
