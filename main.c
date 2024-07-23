/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:52:13 by anoukan           #+#    #+#             */
/*   Updated: 2024/07/23 17:18:03 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

int	main(int argc, char **argv)
{
	t_map	*map;

	if (argc < 2)
		return (ft_printf("Error\nno map found\n"), 0);
	if (is_ber(argv[1]) == false)
		return (ft_printf("Error\nmap is not .ber\n"), 0);
	map = malloc(sizeof(t_map));
	if (!map)
		return (ft_printf("Error\nmap error main\n"), 0);
	map->fd = open(argv[1], O_RDONLY);
	if (map->fd == -1)
		return (ft_printf("Error\nmap doesn't exist\n", 0));
	map->y = open_fd(argv, map);
	map->x = ft_strlen(argv[1]);
	ft_parsing(map, argv);
	ft_window(map);
	return (0);
}
