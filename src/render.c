/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   render.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranascim <ranascim@42.student.42sp.org.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 07:23:37 by ranascim          #+#    #+#             */
/*   Updated: 2022/11/13 07:27:19 by ranascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "so_long.h"

void	ft_put_img(t_data *data, char position, int x, int y)
{
	if (position == WALL)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->sprites.wall.mlx_img, x, y);
	if (position == PLAYER)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->sprites.player.mlx_img, x, y);
	if (position == EMPTY_SPACE)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->sprites.empty_space.mlx_img, x, y);
	if (position == COLLECTIBLE)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->sprites.collectible.mlx_img, x, y);
	if (position == EXIT)
		mlx_put_image_to_window(data->mlx_ptr, data->win_ptr,
			data->sprites.exit.mlx_img, x, y);
}

int	render(t_data *data)
{
	int	index;
	int	x;
	int	y;

	index = 0;
	x = 0;
	y = 0;
	while (y < (data->map.height * IMG_SIZE))
	{
		while (x < (data->map.width * IMG_SIZE))
		{
			ft_put_img(data, data->map.matrix[index], x, y);
			x = x + IMG_SIZE;
			index++;
		}
		y = y + IMG_SIZE;
		x = 0;
	}
	return (0);
}
