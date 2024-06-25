//#include "../../include/so_long.h"
//
//static void render_player(t_data *data)
//{
//    if (data->player != NULL) {
//       if ((mlx_image_to_window(data->mlx, data->player, data->map->player_x * 64, data->map->player_y * 64)) != 0)
//            ft_error(data);
//    }
//    else
//        ft_error(data);
//}
//
//void render_map(t_data *data)
//{
//    mlx_delete_image(data->mlx, data->player);
//    render_player(data);
//}