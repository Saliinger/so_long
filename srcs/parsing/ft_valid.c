/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 13:54:27 by anoukan           #+#    #+#             */
/*   Updated: 2024/07/24 12:49:21 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	ft_valid(t_map *map)
{
	if (map->e == 1 && map->p == 1 && map->w == 1 && map->c >= 1
		&& map->notsquare == 1 && map->s >= 1 && map->x < 60 && map->y < 30
		&& map->unexpected == 0 && map->c
		+ map->e == map->flood_fill_collectible)
		return (1);
	else
		return (ft_printf("Error\nmap is not valid\n"), 0);
}
