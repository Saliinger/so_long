#include "../../include/so_long.h"

static void align_to_grid(int *x, int *y)
{
    *x = (*x / TILE_SIZE) * TILE_SIZE;
    *y = (*y / TILE_SIZE) * TILE_SIZE;
}

static void key_handler(mlx_key_data_t keydata, t_data *data)
{
    static int mouvement = 0;
    static int current = 0;
    int new_x = data->player->instances[0].x;
    int new_y = data->player->instances[0].y;

    if (keydata.key == MLX_KEY_ESCAPE)
        mlx_close_window(data->mlx);
    if (keydata.key == MLX_KEY_W)
    {
        new_y -= TILE_SIZE;
        mouvement++;
    }
    if (keydata.key == MLX_KEY_S)
    {
        new_y += TILE_SIZE;
        mouvement++;
    }
    if (keydata.key == MLX_KEY_A)
    {
        new_x -= TILE_SIZE;
        mouvement++;
    }
    if (keydata.key == MLX_KEY_D)
    {
        new_x += TILE_SIZE;
        mouvement++;
    }

    if (collision(data, new_x, new_y))
    {
        data->player->instances[0].x = new_x;
        data->player->instances[0].y = new_y;
    }
    else
    {
        mouvement--;  // Revert the movement counter if the move was not valid
    }

    // Align the player to the grid to avoid misalignment
    align_to_grid(&data->player->instances[0].x, &data->player->instances[0].y);

    if (current != mouvement)
    {
        ft_printf("%d\n", mouvement);
        current = mouvement;
    }
}

void ft_hook(mlx_key_data_t keydata, void *param)
{
    t_data *data;

    data = (t_data *)param;
    key_handler(keydata, data);
}