#include "../../include/so_long.h"

static void free_map(t_data *data)
{
    int i;

    i = 0;
    while (data->map->map[i])
    {
        free(data->map->map[i]);
        i++;
    }
    free(data->map->map);
    free(data->map);
}


void clear_data(t_data *data)
{
    free_map(data);
    mlx_terminate(data->mlx);
    free(data);
}