/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_window.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranascim <ranascim@42.student.42sp.org.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 07:08:59 by ranascim          #+#    #+#             */
/*   Updated: 2022/11/13 07:44:22 by ranascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_create_window(t_data	*data)
{
	int		width;
	int		height;

	data->mlx_ptr = mlx_init();
	if (data->mlx_ptr == NULL)
	{
		ft_printf(ERR_MSG_GENERIC);
		ft_destroy_matrix(data);
	}
	width = data->map.width * IMG_SIZE;
	height = data->map.height * IMG_SIZE;
	data->win_ptr = mlx_new_window(data->mlx_ptr, width, height, "so_long");
	if (data->win_ptr == NULL)
	{
		ft_printf(ERR_MSG_GENERIC);
		ft_destroy_display(data);
	}
	return (0);
}
