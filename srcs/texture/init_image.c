/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_image.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 13:55:20 by anoukan           #+#    #+#             */
/*   Updated: 2024/07/25 08:00:23 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

static mlx_image_t	*load_img(t_data *data, char *path)
{
	mlx_texture_t	*texture;
	mlx_image_t		*image;

	texture = mlx_load_png(path);
	if (!texture)
	{
		ft_printf("Error\npng didn't load\n");
		ft_error(data);
	}
	image = mlx_texture_to_image(data->mlx, texture);
	if (!image)
		ft_error(data);
	mlx_resize_image(image, TILE_SIZE, TILE_SIZE);
	mlx_delete_texture(texture);
	return (image);
}

void	init_image(t_data *data)
{
	data->player = load_img(data, "./assets/character/character.png");
	data->wall = load_img(data, "./assets/map/wall.png");
	data->background = load_img(data, "./assets/map/background.png");
	data->exit = load_img(data, "./assets/map/exit1.png");
	data->collectible = load_img(data, "./assets/map/collectible.png");
}
