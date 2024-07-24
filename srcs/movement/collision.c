/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   collision.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 13:57:51 by anoukan           #+#    #+#             */
/*   Updated: 2024/07/24 15:18:49 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

bool	collision(t_data *data, int new_x, int new_y)
{
	static int	collected = 0;
	int			i;

	if (data->map->map[new_y / TILE_MOVE][new_x / TILE_MOVE] == '1')
		return (false);
	i = 0;
	while (i < (int)data->collectible->count)
	{
		if (data->collectible->instances[i].x == new_x
			&& data->collectible->instances[i].y == new_y
			&& data->collectible->instances[i].enabled)
		{
			data->collectible->instances[i].enabled = false;
			collected++;
		}
		i++;
	}
	if (new_x == data->exit->instances[0].x
		&& new_y == data->exit->instances[0].y
		&& (int)data->collectible->count == collected)
	{
		ft_printf("you win");
		clear_data(data);
	}
	return (true);
}
