#include "../../include/so_long.h"

static void	init_player(t_map *map, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i] != NULL)
	{
		j = 0;
		while (map->map[i][j] != '\0' && map->map[i][j] != '\n')
		{
			if (map->map[i][j] == 'P')
			{
				mlx_image_to_window(data->mlx, data->player, j * TILE_SIZE, i
					* TILE_SIZE);
				map->player_x = (int)i;
				map->player_y = (int)j;
				break ;
			}
			j++;
		}
		i++;
	}
}

// Function to initialize and draw the map elements
void	init_map(t_map *map, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	init_image(data);   // Initialize images
	init_bg(map, data); // Initialize and draw background
	while (map->map[i])
	{
		j = 0;
		while (map->map[i][j] && map->map[i][j] != '\n')
		{
			if (map->map[i][j] == '1')
				mlx_image_to_window(data->mlx, data->wall, j * TILE_SIZE, i
					* TILE_SIZE);
			else if (map->map[i][j] == 'E')
				mlx_image_to_window(data->mlx, data->exit, j * TILE_SIZE, i
					* TILE_SIZE);
			else if (map->map[i][j] == 'C')
				mlx_image_to_window(data->mlx, data->collectible, j * TILE_SIZE,
					i * TILE_SIZE);
			j++;
		}
		i++; // Increment i to avoid infinite loop
	}
	init_player(map, data);
}
