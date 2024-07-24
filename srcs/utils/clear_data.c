/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   clear_data.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 13:55:31 by anoukan           #+#    #+#             */
/*   Updated: 2024/07/24 15:21:27 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

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
	clear_map(data);
	mlx_terminate(data->mlx);
	free(data);
	exit(EXIT_SUCCESS);
}
