/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_check_map_tiles.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranascim <ranascim@42.student.42sp.org.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 07:04:14 by ranascim          #+#    #+#             */
/*   Updated: 2022/11/13 11:00:49 by ranascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_check_map_tiles(int width, int height, char *matrix, t_data *data)
{
	int	i;
	int	has_e;
	int	has_p;

	i = 0;
	data->collectibles = 0;
	has_e = 0;
	has_p = 0;
	while (matrix[i])
	{
		if ((i < width || i % width == 0 || i % width == (width - 1)
				|| i >= ((width * height) - width)) && matrix[i] != WALL)
			return (1);
		if (matrix[i] == COLLECTIBLE)
			data->collectibles++;
		if (matrix[i] == EXIT)
			has_e++;
		if (matrix[i] == PLAYER)
			has_p++;
		i++;
	}
	if (data->collectibles == 0 || has_e != 1 || has_p != 1)
		return (1);
	return (0);
}
