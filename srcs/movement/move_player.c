#include "../../include/so_long.h"

static void align_to_grid(int *x, int *y)
{
    *x = (*x / TILE_MOVE) * TILE_MOVE;
    *y = (*y / TILE_MOVE) * TILE_MOVE;
}

static void key_handler(mlx_key_data_t keydata, t_data *data)
{
    static int mouvement = 0;
    static int current = 0;
    int new_x = data->player->instances[0].x;
    int new_y = data->player->instances[0].y;

    if (keydata.key == MLX_KEY_ESCAPE && keydata.action == MLX_PRESS)
        clear_data(data);
    if (keydata.key == MLX_KEY_W && keydata.action == MLX_PRESS)
    {
        new_y -= TILE_MOVE;
        mouvement++;
    }
    if (keydata.key == MLX_KEY_S && keydata.action == MLX_PRESS)
    {
        new_y += TILE_MOVE;
        mouvement++;
    }
    if (keydata.key == MLX_KEY_A && keydata.action == MLX_PRESS)
    {
        new_x -= TILE_MOVE;
        mouvement++;
    }
    if (keydata.key == MLX_KEY_D && keydata.action == MLX_PRESS)
    {
        new_x += TILE_MOVE;
        mouvement++;
    }

    // Align the player to the grid to avoid misalignment
    align_to_grid(&new_x, &new_y);

    if (collision(data, new_x, new_y))
    {
        data->player->instances[0].x = new_x;
        data->player->instances[0].y = new_y;
    }
    else
    {
        mouvement--;  // Revert the movement counter if the move was not valid
    }

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