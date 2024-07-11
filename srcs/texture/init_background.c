#include "../../include/so_long.h"

void	init_bg(t_map *map, t_data *data)
{
	int	i;
	int	j;

	i = 0;
	while (map->map[i] != NULL)
	{
		j = 0;
		while (map->map[i][j] != '\0' && map->map[i][j] != '\n')
		{
			mlx_image_to_window(data->mlx, data->background, j * TILE_SIZE, i
				* TILE_SIZE);
			j++;
		}
		i++; // Increment i to avoid infinite loop
	}
}
