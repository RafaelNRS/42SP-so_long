/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_map.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranascim <ranascim@42.student.42sp.org.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 07:02:53 by ranascim          #+#    #+#             */
/*   Updated: 2022/11/13 07:03:33 by ranascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_validate_map(t_data *data)
{
	int		width;
	int		height;
	char	*matrix;

	width = data->map.width;
	height = data->map.height;
	matrix = data->map.matrix;
	if (ft_check_map_tiles(width, height, matrix, data) != 0)
	{
		ft_printf(ERR_MSG_INVALID_MAP);
		ft_destroy_matrix(data);
	}
}
