#include "../../include/so_long.h"


void clear_data(t_data *data)
{
    mlx_terminate(data->mlx);
    free(data);
}