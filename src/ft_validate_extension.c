/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_validate_extension.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranascim <ranascim@42.student.42sp.org.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 06:51:27 by ranascim          #+#    #+#             */
/*   Updated: 2022/11/13 06:52:15 by ranascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_validate_extension(const char *map_file)
{
	int		extension_size;
	size_t	path_size;
	size_t	index;

	extension_size = 4;
	path_size = ft_strlen(map_file);
	index = path_size - extension_size;
	return (ft_memcmp(&map_file[index], ".ber", extension_size));
}
