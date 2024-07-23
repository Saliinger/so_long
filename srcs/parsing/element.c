/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 10:49:51 by anoukan           #+#    #+#             */
/*   Updated: 2024/07/23 22:32:24 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static void	define_player(t_map *map, int i, int j)
{
	map->p += 1;
	map->flood_fill_x = i;
	map->flood_fill_y = j;
}

static void	element(t_map *map, int i, int j)
{
	if (map->map[i][j] != 'E' && map->map[i][j] != 'P' && map->map[i][j] != 'C'
		&& map->map[i][j] != '0' && map->map[i][j] != '1')
		map->unexpected += 1;
	if (map->map[i][j] == 'E')
		map->e += 1;
	if (map->map[i][j] == 'P')
		define_player(map, i, j);
	if (map->map[i][j] == 'C')
		map->c += 1;
	if (map->map[i][j] == '0')
		map->s += 1;
}

void	ft_verify_element(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	map->unexpected = 0;
	while (map->map[i] != NULL)
	{
		j = 0;
		while (map->map[i][j] != '\n' && map->map[i][j] != '\0')
		{
			element(map, i, j);
			j++;
		}
		i++;
	}
}
