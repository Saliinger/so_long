/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   border_are_straight.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 20:11:50 by anoukan           #+#    #+#             */
/*   Updated: 2024/07/24 20:11:51 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static size_t	len(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] && str[i] != '\n')
		i++;
	return (i);
}

bool	border_are_straight(t_map *map)
{
	int		i;
	size_t	j;

	i = 0;
	j = len(map->map[i]);
	while (map->map[i])
	{
		if (len(map->map[i]) != j)
			return (false);
		i++;
	}
	return (true);
}
