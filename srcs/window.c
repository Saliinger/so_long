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

static void ft_error(void)
{
    fprintf(stderr, "%s\n", mlx_strerror(mlx_errno));
    exit(EXIT_FAILURE);
}

int ft_window(t_map *map)
{
    t_data *data;

    (void)map;
    data = (t_data *)malloc(sizeof(t_data));
    if (!data)
        ft_error();
    mlx_set_setting(MLX_MAXIMIZED, true);
    data->mlx = mlx_init(WIDTH, HEIGHT, "Game", true);
    if (!data->mlx)
        ft_error();
    data->image = mlx_new_image(data->mlx, 64, 64);
    if (!data->image || (mlx_image_to_window(data->mlx, data->image, 0, 0) < 0))
        ft_error();
    mlx_image_to_window(data->mlx, data->image, 0, 0);
    mlx_loop_hook(data->mlx, ft_hook, data);
    mlx_loop(data->mlx);
    mlx_delete_image(data->mlx, data->image);
    mlx_terminate(data->mlx);
    free(data);
    return (EXIT_SUCCESS);
}
