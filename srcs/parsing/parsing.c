/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 10:51:58 by anoukan           #+#    #+#             */
/*   Updated: 2024/07/23 12:02:53 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"



static void	to_large(t_map *map)
{
	ft_printf("the map is too big\nx : %d > 60 || y : %d > 32\n", map->x,
		map->y);
	free_map(map);
}

void	ft_parsing(t_map *map, char **argv)
{
	ft_map_chequer(map, argv);
	if (map->x > 60)
		to_large(map);
	map->w = ft_verify_wall(map);
	ft_verify_element(map);
	ft_not_square(map);
	if (ft_valid(map) == 0)
		free_map(map);
    flood_fill(map);
}
