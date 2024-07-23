/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 10:51:58 by anoukan           #+#    #+#             */
/*   Updated: 2024/07/23 18:05:10 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static void	free_temp(char **temp)
{
	int	i;

	i = 0;
	while (temp[i])
	{
		free(temp[i]);
		i++;
	}
	free(temp);
}

static void	to_large(t_map *map)
{
	ft_printf("the map is too big\nx : %d > 60 || y : %d > 32\n", map->x,
		map->y);
	free_map(map);
}

static void	data_init(t_map *map, char **argv)
{
	ft_map_chequer(map, argv);
	map->w = ft_verify_wall(map);
	ft_verify_element(map);
	ft_not_square(map);
}

void	ft_parsing(t_map *map, char **argv)
{
	char	**temp;

	data_init(map, argv);
	temp = map_c(map);
	map->flood_fill_x = map->player_x;
	map->flood_fill_y = map->player_y;
	flood_fill(map, temp);
	free_temp(temp);
	ft_printf("1\n");
	if (map->x > 60)
		to_large(map);
	ft_printf("1\n");
	if (ft_valid(map) == 0)
		free_map(map);
	ft_printf("c+e %d\n cf %d\n", map->c + map->e, map->flood_fill_collectible);
	if (map->c + map->e != map->flood_fill_collectible)
		free_map(map);
	ft_printf("1\n");
}
