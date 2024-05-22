/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/23 10:51:58 by anoukan           #+#    #+#             */
/*   Updated: 2024/02/22 09:26:30 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ft_parsing(t_map map, char **argv)
{
	ft_map_chequer(map, argv);
	// ft_verify_element(map);
	// ft_not_square(map);
	if (ft_valid(map) != 1)
		return ;
}

int	open_fd(char **argv, t_map map)
{
	size_t	i;
	char	*line;

	map.fd = open(argv[1], O_RDONLY);
	i = 1;
	line = get_next_line(map.fd);
	while (line)
	{
		free(line);
		line = get_next_line(map.fd);
		i++;
	}
	free(line);
	close(map.fd);
	map.fd = open(argv[1], O_RDONLY);
	return (i);
}

int	ft_valid(t_map map)
{
	map.w = ft_verify_wall(map);
	if (map.e == 1 && map.p == 1 && map.w == 1 && map.c <= 1
		&& map.notsquare == 1 && map.s <= 1)
		return (1);
	return (0);
}

void	ft_map_chequer(t_map map, char **argv)
{
	size_t	i;
	char	*line;

	i = 0;
	map.y = open_fd(argv, map);
	map.map = (char **)malloc(sizeof(char *) * (map.y + 100));
	if (map.map == NULL)
		return ;
	line = get_next_line(map.fd);
	while (line)
	{
		map.map[i] = ft_strdup(line);
		free(line);
		line = get_next_line(map.fd);
		i++;
	}
	free(line);
}
