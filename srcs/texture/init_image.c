#include "../../include/so_long.h"

static mlx_image_t *load_img(t_data *data, char *path) {
    mlx_texture_t *texture;
    mlx_image_t *image;

    texture = mlx_load_png(path);
    if (!texture)
        ft_error(data);
    image = mlx_texture_to_image(data->mlx, texture);
    if (!image)
        ft_error(data);
    mlx_delete_texture(texture);
    return image;
}

void init_image(t_data *data) {
    data->player = load_img(data, "./assets/character/character.png");
    data->wall = load_img(data, "./assets/map/wall.png");
    data->background = load_img(data, "./assets/map/background.png");
    data->exit = load_img(data, "./assets/map/exit1.png");
    data->collectible = load_img(data, "./assets/map/collectible.png");
}
