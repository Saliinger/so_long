/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 13:58:04 by anoukan           #+#    #+#             */
/*   Updated: 2024/07/12 22:50:20 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static void	align_to_grid(int *x, int *y)
{
	*x = (*x / TILE_MOVE) * TILE_MOVE;
	*y = (*y / TILE_MOVE) * TILE_MOVE;
}

static void	calculate_new_position(mlx_key_data_t keydata, t_data *data)
{
	if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
	{
		data->new_y -= TILE_MOVE;
		data->mouvement++;
	}
	else if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
	{
		data->new_y += TILE_MOVE;
		data->mouvement++;
	}
	else if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
	{
		data->new_x -= TILE_MOVE;
		data->mouvement++;
	}
	else if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
	{
		data->new_x += TILE_MOVE;
		data->mouvement++;
	}
}

static void	handle_movement(t_data *data)
{
	align_to_grid(&data->new_x, &data->new_y);
	if (collision(data, data->new_x, data->new_y))
	{
		data->player->instances[0].x = data->new_x;
		data->player->instances[0].y = data->new_y;
	}
	else
	{
		data->mouvement--;
	}
	if (data->current_move != data->mouvement)
	{
		ft_printf("%d\n", data->mouvement);
		data->current_move = data->mouvement;
	}
}

static void	key_handler(mlx_key_data_t keydata, t_data *data)
{
	data->new_x = data->player->instances[0].x;
	data->new_y = data->player->instances[0].y;
	if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
	{
		clear_data(data);
		return ;
	}
	calculate_new_position(keydata, data);
	handle_movement(data);
}

void	ft_hook(mlx_key_data_t keydata, void *param)
{
	t_data	*data;

	data = (t_data *)param;
	key_handler(keydata, data);
}
