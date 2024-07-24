/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 13:58:54 by anoukan           #+#    #+#             */
/*   Updated: 2024/07/24 17:48:29 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static void	clear_map(t_map *map)
{
	free(map);
	ft_printf("Error\nthe map is empty\n");
	exit(EXIT_FAILURE);
}

static void	init(t_map *map)
{
	map->map = 0;
	map->e = 0;
	map->p = 0;
	map->w = 0;
	map->c = 0;
	map->notsquare = 0;
	map->s = 0;
}

static int	width(char *line)
{
	int	i;

	i = 0;
	while (line[i] != '\0' && line[i] != '\n')
		i++;
	return (i);
}

static void	extend_mapc(t_map *map)
{
	char	*line;
	int		i;

	line = get_next_line(map->fd);
	if (line == NULL)
		clear_map(map);
	i = 0;
	map->x = width(line);
	while (line != NULL)
	{
		map->map[i] = ft_strdup(line);
		free(line);
		if (!map->map[i])
			map_empty(map);
		line = get_next_line(map->fd);
		i++;
	}
	map->map[i] = NULL;
	free(line);
}

void	ft_map_chequer(t_map *map, char **argv)
{
	init(map);
	map->y = open_fd(argv, map);
	map->map = (char **)malloc(sizeof(char *) * (map->y + 1));
	if (map->map == NULL)
		clear_map(map);
	extend_mapc(map);
}
