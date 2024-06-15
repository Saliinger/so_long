/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 10:49:48 by anoukan           #+#    #+#             */
/*   Updated: 2024/02/15 15:00:46 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ft_not_square(t_map map)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (map.map[i][j])
	{
		while (map.map[i][j])
			j++;
		i++;
	}
	if (i > j)
		map.notsquare = 1;
	else if (j > i)
		map.notsquare = 1;
	else
		map.notsquare = 0;
}

int	ft_verify_wall(t_map map)
{
    size_t i;
	size_t 	j;

	i = 0;
	while (i < map.y)
	{
		j = 0;
		while (j < map.x)
		{
			if ((i == 0 || i == map.x - 1
				|| j == map.y - 1) && map.map[i][j] != 1)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
