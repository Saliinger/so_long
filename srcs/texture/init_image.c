//#include "../../include/so_long.h"
//
//static mlx_image_t *load_img(t_data *data, char *path) {
//    mlx_texture_t *texture;
//    mlx_image_t *image;
//
//    texture = mlx_load_png(path);
//    if (!texture)
//        ft_error(data);
//    image = mlx_texture_to_image(data->mlx, texture);
//    if (!image)
//        ft_error(data);
//    mlx_delete_texture(texture);
//    return image;
//}
//
//void init_image(t_data *data) {
//    data->player = load_img(data, "./assets/character/character.png");
//    data->wall = load_img(data, "./assets/map/wall.png");
//    data->background = load_img(data, "./assets/map/background.png");
//    data->exit = load_img(data, "./assets/map/exit1.png");
//    data->collectible = load_img(data, "./assets/map/collectible.png");
//}

#include "../../include/so_long.h"
#include <stdlib.h>
#include <stdint.h>

typedef struct {
    int width;
    int height;
    uint32_t *pixels;
} Image;

// Load an image from a given path and return it as an Image struct
static Image load_image_data(char *path) {
    mlx_texture_t *texture = mlx_load_png(path);
    if (!texture)
        ft_error(NULL);

    Image img;
    img.width = texture->width;
    img.height = texture->height;
    img.pixels = (uint32_t *)texture->pixels;

    return img;
}

// Convert Image struct to mlx_image_t
static mlx_image_t *convert_to_mlx_image(t_data *data, const Image *img) {
    mlx_image_t *mlx_img = mlx_new_image(data->mlx, img->width, img->height);
    for (int y = 0; y < img->height; ++y) {
        for (int x = 0; x < img->width; ++x) {
            mlx_put_pixel(mlx_img, x, y, img->pixels[y * img->width + x]);
        }
    }
    return mlx_img;
}

// Function to scale the image
Image scale_image(const Image *src, int new_width, int new_height) {
    Image dst;
    dst.width = new_width;
    dst.height = new_height;
    dst.pixels = (uint32_t *)malloc(new_width * new_height * sizeof(uint32_t));

    float x_ratio = (float)src->width / new_width;
    float y_ratio = (float)src->height / new_height;

    for (int y = 0; y < new_height; ++y) {
        for (int x = 0; x < new_width; ++x) {
            int src_x = (int)(x * x_ratio);
            int src_y = (int)(y * y_ratio);
            dst.pixels[y * new_width + x] = src->pixels[src_y * src->width + src_x];
        }
    }

    return dst;
}

void init_image(t_data *data) {
    Image player_img = load_image_data("./assets/character/character.png");
    Image wall_img = load_image_data("./assets/map/wall.png");
    Image background_img = load_image_data("./assets/map/background.png");
    Image exit_img = load_image_data("./assets/map/exit1.png");
    Image collectible_img = load_image_data("./assets/map/collectible.png");

    // Scale images to tile size
    Image scaled_player = scale_image(&player_img, 64, 64);
    Image scaled_wall = scale_image(&wall_img, 64, 64);
    Image scaled_background = scale_image(&background_img, 64, 64);
    Image scaled_exit = scale_image(&exit_img, 64, 64);
    Image scaled_collectible = scale_image(&collectible_img, 64, 64);

    // Convert scaled images to mlx_image_t
    data->player = convert_to_mlx_image(data, &scaled_player);
    data->wall = convert_to_mlx_image(data, &scaled_wall);
    data->background = convert_to_mlx_image(data, &scaled_background);
    data->exit = convert_to_mlx_image(data, &scaled_exit);
    data->collectible = convert_to_mlx_image(data, &scaled_collectible);

    // Free allocated pixel data
    free(scaled_player.pixels);
    free(scaled_wall.pixels);
    free(scaled_background.pixels);
    free(scaled_exit.pixels);
    free(scaled_collectible.pixels);
}
