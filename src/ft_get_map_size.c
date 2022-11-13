/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_get_map_size.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranascim <ranascim@42.student.42sp.org.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 06:54:10 by ranascim          #+#    #+#             */
/*   Updated: 2022/11/13 06:56:50 by ranascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_not_rec_error(void)
{
	ft_printf(ERR_MSG_MAP);
	exit(0);
}

void	ft_invalid_tile_error(void)
{
	ft_printf(ERR_MSG_INVALID_MAP);
	exit(0);
}

void	ft_read_file(int fd, t_data *data)
{
	char	buffer;
	int		columns;

	columns = 0;
	while (read(fd, &buffer, 1) != 0)
	{
		if (ft_valid_tiles(buffer) == 1)
			columns++;
		else if (buffer == '\n')
		{
			if (data->map.height == 1)
				data->map.width = columns;
			else if (columns != data->map.width)
				ft_not_rec_error();
			data->map.height++;
			columns = 0;
		}
		else
			ft_invalid_tile_error();
	}
}

void	ft_get_map_size(t_data *data, const char	*map_file)
{
	int		fd;

	data->map.height = 1;
	data->map.width = 0;
	fd = open(map_file, O_RDONLY);
	if (fd != -1)
	{
		ft_read_file(fd, data);
	}
	close(fd);
}
