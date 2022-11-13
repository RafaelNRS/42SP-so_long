/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranascim <ranascim@42.student.42sp.org.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 06:47:51 by ranascim          #+#    #+#             */
/*   Updated: 2022/11/13 07:07:22 by ranascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_create_map(t_data *data, const char *map_file)
{
	if (ft_validate_extension(map_file) != 0)
	{
		ft_printf(ERR_MSG_INVALID_EXT);
		exit(0);
	}
	ft_get_map_size(data, map_file);
	ft_set_map_matrix(data, map_file);
	ft_validate_map(data);
}
