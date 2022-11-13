/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_message.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ranascim <ranascim@42.student.42sp.org.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/13 07:30:42 by ranascim          #+#    #+#             */
/*   Updated: 2022/11/13 07:30:48 by ranascim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	ft_end_msg(t_data *data)
{
	ft_printf("--------------------------------\n");
	ft_printf("End Game Score: %d\n", data->score);
	ft_printf("Movements counter %d\n", data->movements);
	ft_printf("--------------------------------\n");
}

void	ft_missing_coin_msg(t_data *data)
{
	int	missing_coins;

	missing_coins = data->collectibles - data->score;
	ft_printf("--------------------------------\n");
	ft_printf("Missing %d coins, can't exit game\n", missing_coins);
	ft_printf("--------------------------------\n");
}

void	ft_got_all_coins_msg(void)
{
	ft_printf("--------------------------------\n");
	ft_printf("Got all coins, go to exit\n");
	ft_printf("--------------------------------\n");
}

void	ft_message(int n, t_data *data)
{
	if (n == 1)
		ft_end_msg(data);
	if (n == 2)
		ft_printf("Game Score: %d\n", data->score);
	if (n == 3)
		ft_missing_coin_msg(data);
	if (n == 4)
		ft_got_all_coins_msg();
	if (n == 5)
		ft_printf("Movements counter %d\n", data->movements);
}
