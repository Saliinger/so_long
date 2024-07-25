/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 13:11:19 by anoukan           #+#    #+#             */
/*   Updated: 2024/07/25 16:08:35 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

static void	data_fail(t_data *data, t_map *map)
{
	if (data)
	{
		clear_img(data);
		mlx_terminate(data->mlx);
		free(data);
	}
	free_map(map);
}

int	ft_window(t_map *map)
{
	t_data	*data;
	int		height;
	int		width;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		data_fail(data, map);
	data->map = map;
	height = map->y * TILE_SIZE;
	width = map->x * TILE_SIZE;
	data->current_move = 0;
	data->mouvement = 0;
	data->mlx = mlx_init(width, height, "so_long", true);
	if (!data->mlx)
		ft_error(data);
	init_map(map, data);
	mlx_key_hook(data->mlx, ft_hook, data);
	mlx_loop(data->mlx);
	clear_data(data);
	return (0);
}
