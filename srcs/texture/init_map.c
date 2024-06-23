#include "../../include/so_long.h"

void init_map(t_map *map, t_data *data)
{
    int i;
    int j;
    mlx_image_t *img;

    init_image(data);
    i = 0;
    while (map->map[i] != NULL)
    {
        j = 0;
        while (map->map[i][j] != '\0')
        {
            if (map->map[i][j] == '1')
                img = data->wall;
            else if (map->map[i][j] == '0')
                img = data->floor;
            else if (map->map[i][j] == 'P')
                img = data->player;
            else if (map->map[i][j] == 'E')
                img = data->exit;
            else if (map->map[i][j] == 'C')
                img = data->collectible;
            mlx_image_to_window(data->mlx, img, j * 64, i * 64);
            j++;
        }
    }
}