#include "../../include/so_long.h"

void init_bg(t_map *map, t_data *data)
{
    int i = 0;
    int j;

    while (map->map[i] != NULL) {
        j = 0;
        while (map->map[i][j] != '\0' && map->map[i][j] != '\n') {
            mlx_image_to_window(data->mlx, data->background, j * 64, i * 64);
            j++;
        }
        i++; // Increment i to avoid infinite loop
    }
}