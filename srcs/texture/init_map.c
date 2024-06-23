#include "../../include/so_long.h"

static void init_bg(t_map *map, t_data *data)
{
    int i;
    int j;

    i = 0;
    while (map->map[i] != NULL)
    {
        j = 0;
        while (map->map[i][j] != '\0' && map->map[i][j] != '\n')
        {
            mlx_image_to_window(data->mlx, data->background, j * 64, i * 64);
            j++;
        }
    }
}

void init_map(t_map *map, t_data *data)
{
    int i;
    int j;

    init_image(data);
    init_bg(map, data);
    i = 0;
    while (map->map[i] != NULL)
    {
        j = 0;
        while (map->map[i][j] != '\0')
        {
            if (map->map[i][j] == '1')
                mlx_image_to_window(data->mlx, data->wall, j * 64, i * 64);
            else if (map->map[i][j] == 'P')
                mlx_image_to_window(data->mlx, data->player, j * 64, i * 64);
            else if (map->map[i][j] == 'E')
                mlx_image_to_window(data->mlx, data->exit, j * 64, i * 64);
            else if (map->map[i][j] == 'C')
                mlx_image_to_window(data->mlx, data->collectible, j * 64, i * 64);
            j++;
        }
    }
}