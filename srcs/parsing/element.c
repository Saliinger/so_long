/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 10:49:51 by anoukan           #+#    #+#             */
/*   Updated: 2024/07/23 18:02:32 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ft_verify_element(t_map *map)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i] != NULL)
	{
		j = 0;
		while (map->map[i][j] != '\n' && map->map[i][j] != '\0')
		{
			if (map->map[i][j] != 'E' && map->map[i][j] != 'P'
				&& map->map[i][j] != 'C' && map->map[i][j] != '0')
				map->unexpected += 1;
			if (map->map[i][j] == 'E')
				map->e += 1;
			if (map->map[i][j] == 'P')
				map->p += 1;
			if (map->map[i][j] == 'C')
				map->c += 1;
			if (map->map[i][j] == '0')
				map->s += 1;
			j++;
		}
		i++;
	}
}
