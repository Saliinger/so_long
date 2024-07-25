/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 13:55:31 by anoukan           #+#    #+#             */
/*   Updated: 2024/07/25 11:58:27 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static void	clear_img(t_data *data)
{
	if (data->background)
		mlx_delete_image(data->mlx, data->background);
	if (data->player)
		mlx_delete_image(data->mlx, data->player);
	if (data->collectible)
		mlx_delete_image(data->mlx, data->collectible);
	if (data->wall)
		mlx_delete_image(data->mlx, data->wall);
	if (data->exit)
		mlx_delete_image(data->mlx, data->exit);
}

static void	clear_map(t_data *data)
{
	int	i;

	i = 0;
	while (data->map->map[i])
	{
		free(data->map->map[i]);
		i++;
	}
	free(data->map->map);
	free(data->map);
}

void	clear_data(t_data *data)
{
	clear_img(data);
	clear_map(data);
	mlx_terminate(data->mlx);
	free(data);
	exit(EXIT_SUCCESS);
}
