/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 10:51:58 by anoukan           #+#    #+#             */
/*   Updated: 2024/07/24 13:03:46 by anoukan          ###   ########.fr       */
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
	if (map->w != 1)
		wall(map);
	temp = map_c(map);
	flood_fill(map, temp);
	free_temp(temp);
	if (map->x > 60)
		to_large(map);
	if (ft_valid(map) == 0)
		free_map(map);
}
