/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:52:13 by anoukan           #+#    #+#             */
/*   Updated: 2024/07/25 13:08:10 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

static void	init_tmap(t_map *map)
{
	map->e = 0;
	map->p = 0;
	map->c = 0;
	map->notsquare = 0;
	map->s = 0;
	map->x = 0;
	map->y = 0;
	map->unexpected = 0;
	map->flood_fill_collectible = 0;
}

int	main(int argc, char **argv)
{
	t_map	*map;

	if (argc < 2)
		return (ft_printf("Error\nno map found\n"), 0);
	if (argc > 2)
		return (ft_printf("Error\ntoo many argument\n"), 0);
	if (is_ber(argv[1]) == false)
		return (ft_printf("Error\nmap is not .ber\n"), 0);
	map = malloc(sizeof(t_map));
	if (!map)
		return (ft_printf("Error\nmap error main\n"), 0);
	init_tmap(map);
	map->fd = open(argv[1], O_RDONLY);
	if (map->fd == -1)
		return (free(map), ft_printf("Error\nmap doesn't exist\n", 0));
	map->y = open_fd(argv, map);
	map->x = ft_strlen(argv[1]);
	ft_parsing(map, argv);
	ft_window(map);
	return (0);
}
