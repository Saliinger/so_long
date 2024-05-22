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

// Exit the program as failure.
static void	ft_error(void)
{
	fprintf(stderr, "%s", mlx_strerror(mlx_errno));
	exit(EXIT_FAILURE);
}

int	ft_window(t_map map)
{
	mlx_t			*mlx;
	mlx_image_t		*image;
	unsigned char	*image_data;
	mlx_image_t		*image;

	mlx_set_setting(MLX_MAXIMIZED, true);
	mlx = mlx_init(WIDTH, HEIGHT, "Game", true);
	if (!mlx)
		ft_error();
	image_data = load_image_data("./assets/Sprout\ Lands\ -\ Sprites\ -\ Basic\ pack/Tilesets/Wooden\ House.png ", 50, 50, 32);
	if (image_data)
	{
		image = mlx_create_image(mlx, 50, 50, 32, image_data);
		mlx_put_image_to_window(mlx, mlx, image, 0, 0);
		free(image_data);
	}
	mlx_loop(mlx);
	mlx_terminate(mlx);
	return (EXIT_SUCCESS);
}
