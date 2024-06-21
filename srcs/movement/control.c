/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   control.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/06/20 13:27:00 by anoukan           #+#    #+#             */
/*   Updated: 2024/06/20 17:04:53 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ft_hook(void *param)
{
	static int	mouvement;
	mlx_t		*mlx;
	mlx_image_t	*image;
	t_data		*data;

	if (!mouvement)
		mouvement = 0;
	data = (t_data *)param;
	mlx = data->mlx;
	image = data->image;
	if (mlx_is_key_down(mlx, MLX_KEY_ESCAPE))
		mlx_close_window(mlx);
	if (mlx_is_key_down(mlx, MLX_KEY_UP))
	{
		image->instances[0].y -= 5;
		mouvement++;
        ft_printf("%d\n", mouvement);
	}
	if (mlx_is_key_down(mlx, MLX_KEY_DOWN))
	{
		image->instances[0].y += 5;
		mouvement++;
        ft_printf("%d\n", mouvement);
	}
	if (mlx_is_key_down(mlx, MLX_KEY_LEFT))
	{
		image->instances[0].x -= 5;
		mouvement++;
        ft_printf("%d\n", mouvement);
	}
	if (mlx_is_key_down(mlx, MLX_KEY_RIGHT))
	{
		image->instances[0].x += 5;
		mouvement++;
        ft_printf("%d\n", mouvement);
	}
}
