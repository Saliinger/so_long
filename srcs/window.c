/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 13:11:19 by anoukan           #+#    #+#             */
/*   Updated: 2024/02/22 18:18:24 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */
#include "../include/so_long.h"

int ft_window(t_map *map)
{
    t_data *data;
    int height;
    int width;

    (void)map;
    data = (t_data *)malloc(sizeof(t_data));
    if (!data)
        ft_error(data);
    mlx_set_setting(MLX_MAXIMIZED, true);
    height = (int)map->y * 64;
    width = (int)map->x * 64;
    data->mlx = mlx_init(width, height, "so_long", true);
    if (!data->mlx)
        ft_error(data);
    init_map(map, data);
    //mlx_loop_hook(data->mlx, ft_hook, &data);
    mlx_loop(data->mlx);
    return (EXIT_SUCCESS);
}
