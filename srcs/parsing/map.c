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

void	ft_not_square(t_map *map)
{
	size_t	i;
	size_t	j;
    t_map *temp;

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
    size_t i;
	size_t 	j;
    t_map *temp;

	i = 0;
    temp = map;
	while (i < temp->y)
	{
		j = 0;
		while (j < temp->x)
		{
			if ((i == 0 || i == temp->x - 1
				|| j == temp->y - 1) && temp->map[i][j] != 1)
				return (0);
			j++;
		}
		i++;
	}
	return (1);
}
