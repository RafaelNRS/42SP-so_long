/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranascim <ranascim@42.student.42sp.org.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/12 10:15:16 by ranascim          #+#    #+#             */
/*   Updated: 2022/11/13 10:54:33 by ranascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_start_game(const char *map_file)
{
	t_data	data;

	ft_create_map(&data, map_file);
	ft_create_window(&data);
	ft_create_imgs(&data);
	data.score = 0;
	data.movements = 0;
	ft_printf("Game Score: %d\n", data.score);
	ft_printf("Movements counter %d\n", data.movements);
	mlx_loop_hook(data.mlx_ptr, &render, &data);
	mlx_hook(
		data.win_ptr,
		KeyRelease, KeyReleaseMask,
		&handle_keyrelease,
		&data
		);
	mlx_hook(
		data.win_ptr,
		DestroyNotify,
		NoEventMask,
		&handle_destroy_window,
		&data
		);
	mlx_loop(data.mlx_ptr);
	ft_exit(&data);
}

int	main(int argc, const char *argv[])
{
	if (argc != 2)
		ft_printf(ERR_MSG_PARAMS);
	else
		ft_start_game(argv[1]);
	return (0);
}
