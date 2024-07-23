/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_tmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/23 17:01:04 by anoukan           #+#    #+#             */
/*   Updated: 2024/07/23 17:01:25 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

char	**map_c(t_map *map)
{
	char	**temp;
	int		i;

	temp = (char **)malloc(sizeof(char *) * (map->y + 1));
	if (!temp)
		free_map(map);
	i = 0;
	while (map->map[i])
	{
		temp[i] = ft_strdup(map->map[i]);
		if (!temp[i])
			free_map(map);
		i++;
	}
	temp[i] = NULL;
	return (temp);
}
