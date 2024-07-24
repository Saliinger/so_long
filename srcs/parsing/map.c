/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 13:53:47 by anoukan           #+#    #+#             */
/*   Updated: 2024/07/24 17:43:02 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ft_not_square(t_map *map)
{
	int		i;
	int		j;
	t_map	*temp;

	i = 0;
	j = 0;
	temp = map;
	while (temp->map[i][j])
	{
		while (temp->map[i][j])
			j++;
		i++;
	}
	if (i > j || j > i)
		temp->notsquare = 1;
	else
		temp->notsquare = 0;
}

int	ft_verify_wall(t_map *map)
{
	int	i;
	int	j;

	j = 0;
	while (j < map->x)
	{
		if (map->map[0][j] != '1' || map->map[map->y - 1][j] != '1')
			return (0);
		j++;
	}
	i = 0;
	while (i < map->y)
	{
		if (map->map[i][0] != '1' || map->map[i][map->x - 1] != '1')
			return (0);
		i++;
	}
	return (1);
}
