/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 13:11:19 by anoukan           #+#    #+#             */
/*   Updated: 2024/07/12 22:50:36 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../include/so_long.h"

int	ft_window(t_map *map)
{
	t_data	*data;
	int		height;
	int		width;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		ft_error(data, map);
	data->map = map;
	height = map->y * TILE_SIZE;
	width = map->x * TILE_SIZE;
	data->current_move = 0;
	data->mouvement = 0;
	data->mlx = mlx_init(width, height, "so_long", true);
	if (!data->mlx)
		ft_error(data, map);
	init_map(map, data);
	mlx_key_hook(data->mlx, ft_hook, data);
	mlx_loop(data->mlx);
	return (EXIT_SUCCESS);
}
