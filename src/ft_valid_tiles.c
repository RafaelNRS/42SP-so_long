/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid_tiles.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranascim <ranascim@42.student.42sp.org.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 06:57:21 by ranascim          #+#    #+#             */
/*   Updated: 2022/11/13 06:57:55 by ranascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	ft_valid_tiles(char buffer)
{
	if (buffer == COLLECTIBLE || buffer == EXIT || buffer == PLAYER
		|| buffer == WALL || buffer == EMPTY_SPACE)
		return (1);
	return (0);
}
