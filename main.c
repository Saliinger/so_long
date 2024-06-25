/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 14:52:13 by anoukan           #+#    #+#             */
/*   Updated: 2024/02/22 09:41:43 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./include/so_long.h"

int	main(int argc, char **argv)
{
	t_map	*map;

	if (argc < 2)
		return (ft_printf("no map found"), 0);
    map = malloc(sizeof(t_map));
    if (!map)
        return (0);
	map->fd = open(argv[1], O_RDONLY);
	map->map = 0;
	map->e = 0;
	map->p = 0;
	map->w = 0;
	map->c = 0;
	map->notsquare = 0;
	map->y = open_fd(argv, map);
	map->x = ft_strlen(argv[1]);
	map->s = 0;
	ft_parsing(map, argv);
	ft_window(map);
	return (0);
}
