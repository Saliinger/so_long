/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flood_fill.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 17:02:20 by anoukan           #+#    #+#             */
/*   Updated: 2024/07/23 18:08:02 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static void	extend_ff(t_map *map, char **temp)
{
	int	temp_x;
	int	temp_y;

	temp_x = map->flood_fill_x;
	temp_y = map->flood_fill_y;
	map->flood_fill_x = temp_x - 1;
	flood_fill(map, temp);
	map->flood_fill_x = temp_x;
	map->flood_fill_x = temp_x + 1;
	flood_fill(map, temp);
	map->flood_fill_x = temp_x;
	map->flood_fill_y = temp_y - 1;
	flood_fill(map, temp);
	map->flood_fill_y = temp_y;
	map->flood_fill_y = temp_y + 1;
	flood_fill(map, temp);
	map->flood_fill_y = temp_y;
}

void	flood_fill(t_map *map, char **temp)
{
	ft_print(temp);
	if (temp[map->flood_fill_x][map->flood_fill_y]
		&& temp[map->flood_fill_x][map->flood_fill_y] != 'F'
		&& temp[map->flood_fill_x][map->flood_fill_y] != '1')
	{
		if (temp[map->flood_fill_x][map->flood_fill_y] == 'C'
			|| temp[map->flood_fill_x][map->flood_fill_y] == 'E')
			map->flood_fill_collectible += 1;
		if (temp[map->flood_fill_x][map->flood_fill_y] != '1'
			&& temp[map->flood_fill_x][map->flood_fill_y] != '\0'
			&& temp[map->flood_fill_x][map->flood_fill_y] != '\n')
			temp[map->flood_fill_x][map->flood_fill_y] = 'F';
	}
	else
		return ;
	extend_ff(map, temp);
}
