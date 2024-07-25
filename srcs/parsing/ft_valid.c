/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 13:54:27 by anoukan           #+#    #+#             */
/*   Updated: 2024/07/25 15:54:39 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	ft_valid(t_map *map)
{
	if (map->e == 1 && map->p == 1 && map->c >= 1 && map->notsquare == 1
		&& map->x < 61 && map->y < 31 && map->unexpected == 0 && map->c
		+ map->e == map->flood_fill_collectible)
		return (1);
	else
		return (ft_printf("Error\nmap is not valid\n"), 0);
}

// debug
// ft_printf("cf %d\ne %d\np %d\nc %d\nnt %d\ns %d\nx %d\ny %d\nun %d\n",
//	map->flood_fill_collectible, map->e, map->p, map->c, map->notsquare,
//	map->s, map->x, map->y, map->unexpected);