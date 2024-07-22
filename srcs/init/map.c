/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 13:58:54 by anoukan           #+#    #+#             */
/*   Updated: 2024/07/22 14:25:16 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static void	clear_map(t_map *map)
{
	free(map);
	ft_printf("the map is empty\n");
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

void	ft_map_chequer(t_map *map, char **argv)
{
	int		i;
	char	*line;
	t_map	*temp;

	i = 0;
	init(map);
	temp = map;
	temp->y = open_fd(argv, map);
	temp->map = (char **)malloc(sizeof(char *) * (temp->y + 1));
	if (temp->map == NULL)
		clear_map(map);
	line = get_next_line(temp->fd);
	if (line == NULL)
		clear_map(map);
	temp->x = width(line);
	while (line)
	{
		temp->map[i] = ft_strdup(line);
		free(line);
		line = get_next_line(temp->fd);
		i++;
	}
	temp->map[i] = NULL;
	free(line);
}
