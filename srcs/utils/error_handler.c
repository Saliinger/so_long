/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handler.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 13:55:36 by anoukan           #+#    #+#             */
/*   Updated: 2024/07/24 13:03:59 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	to_large(t_map *map)
{
	ft_printf("Error\nthe map is too big\nx : %d > 60 || y : %d > 32\n", map->x,
		map->y);
	free_map(map);
}

void	ft_error(t_data *data)
{
	clear_data(data);
	ft_printf("Error\n%s\n", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

void	wall(t_map *map)
{
	ft_printf("Error\nwall is not complete\n");
	free_map(map);
}
