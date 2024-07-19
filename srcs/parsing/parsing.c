/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 10:51:58 by anoukan           #+#    #+#             */
/*   Updated: 2024/07/11 13:51:22 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static void free_map(t_map *map)
{
    int i;

    i = 0;
    while (map->map[i])
    {
        free(map->map[i]);
        i++;
    }
    free(map->map);
    free(map);
    exit(EXIT_FAILURE);
}

void	ft_parsing(t_map *map, char **argv)
{
	ft_map_chequer(map, argv);
	map->w = ft_verify_wall(map);
	ft_verify_element(map);
	ft_not_square(map);
    if (ft_valid(map) == 0)
        free_map(map);
}
