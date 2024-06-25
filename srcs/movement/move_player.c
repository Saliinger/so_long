#include "../../include/so_long.h"

static void key_handler(mlx_key_data_t keydata, t_data *data)
{
    static int	mouvement = 0;
    static int current = 0;

    if (keydata.key == MLX_KEY_ESCAPE)
		mlx_close_window(data->mlx);
	if (keydata.key ==MLX_KEY_W)
    {
        mouvement++;
        data->player->instances[0].y -= 32;
    }
	if (keydata.key == MLX_KEY_S)
    {
        mouvement++;
        data->player->instances[0].y += 32;
    }
	if (keydata.key == MLX_KEY_A)
    {
        mouvement++;
        data->player->instances[0].x -= 32;
    }
	if (keydata.key == MLX_KEY_D)
    {
        mouvement++;
        data->player->instances[0].x += 32;
    }
    if(current != mouvement)
    {
        ft_printf("%d\n", mouvement);
        current = mouvement;
    }
}


void	ft_hook(mlx_key_data_t keydata, void *param)
{
    t_data *data;

	data = (t_data *)param;
    key_handler(keydata, data);
}