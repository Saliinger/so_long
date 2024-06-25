#include "../../include/so_long.h"


static void init_player(t_map *map, t_data *data)
{
    int i;
    int j;

    i = 0;
    while (map->map[i] != NULL)
    {
        j = 0;
        while (map->map[i][j] != '\0' && map->map[i][j] != '\n') {
            if (map->map[i][j] == 'P') {
                mlx_image_to_window(data->mlx, data->player, j * 64, i * 64);
                map->player_x = (int)i;
                map->player_y = (int)j;
                break;
            }
            j++;
        }
            i++;
    }
}

// Function to initialize and draw the map elements
void init_map(t_map *map, t_data *data) {
    int i = 0;
    int j;

    init_image(data); // Initialize images
    init_bg(map, data); // Initialize and draw background

    while (map->map[i]) {
        j = 0;
        while (map->map[i][j] && map->map[i][j] != '\n') {
            if (map->map[i][j] == '1')
                mlx_image_to_window(data->mlx, data->wall, j * 64, i * 64);
            else if (map->map[i][j] == 'E')
                mlx_image_to_window(data->mlx, data->exit, j * 64, i * 64);
            else if (map->map[i][j] == 'C')
                mlx_image_to_window(data->mlx, data->collectible, j * 64, i * 64);
            j++;
        }
        i++; // Increment i to avoid infinite loop
    }
    init_player(map, data);
}