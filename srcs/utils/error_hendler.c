#include "../../include/so_long.h"

void ft_error(t_data *data)
{
    clear_data(data);
    fprintf(stderr, "%s\n", mlx_strerror(mlx_errno));
    exit(EXIT_FAILURE);
}
