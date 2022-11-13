/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_set_map_matrix.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranascim <ranascim@42.student.42sp.org.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 07:00:21 by ranascim          #+#    #+#             */
/*   Updated: 2022/11/13 07:02:27 by ranascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_set_map_matrix(t_data *data, const char *map_file)
{
	size_t	matrix_size;
	char	buffer;
	int		fd;
	int		index;

	matrix_size = (data->map.height * data->map.width) + 1;
	data->map.matrix = ft_calloc(matrix_size, sizeof(char));
	index = 0;
	fd = open(map_file, O_RDONLY);
	if (fd != -1)
	{
		while (read(fd, &buffer, 1) != 0)
		{
			if (buffer != '\n')
			{
				data->map.matrix[index] = buffer;
				if (buffer == PLAYER)
					data->map.player_position = index;
				index++;
			}
		}
	}
	data->map.matrix[index] = '\0';
	close(fd);
}
