/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   window.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 13:11:19 by anoukan           #+#    #+#             */
/*   Updated: 2024/07/11 13:52:07 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int	ft_window(t_map *map)
{
	t_data	*data;
	int		height;
	int		width;

	data = (t_data *)malloc(sizeof(t_data));
	if (!data)
		ft_error(data);
	data->map = map;
	height = map->y * TILE_SIZE;
	width = map->x * TILE_SIZE;
	data->mlx = mlx_init(width, height, "so_long", true);
	if (!data->mlx)
		ft_error(data);
	init_map(map, data);
	mlx_key_hook(data->mlx, ft_hook, data);
	mlx_loop(data->mlx);
	return (EXIT_SUCCESS);
}
