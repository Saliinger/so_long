/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 13:55:44 by anoukan           #+#    #+#             */
/*   Updated: 2024/07/11 13:55:45 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ft_print(char **map)
{
	int	i;

	i = 0;
	while (map[i])
	{
		ft_printf("%s", map[i]);
		i++;
	}
	ft_printf("\n\n");
}

 void	free_map(t_map *map)
{
    int	i;

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
