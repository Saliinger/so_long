#include "../../include/so_long.h"

// Verify wall && collectible
bool collision(t_data *data, int new_x, int new_y)
{
    static int collected = 0;
    int i;
    int x;
    int y;

    x = new_x / 64;
    y = new_y / 64;

    // Check for wall collision
    if (data->map->map[y][x] == '1')
        return false;

    // Check for collectible collision and update count
    i = 0;
    while (i < (int)data->collectible->count)
    {
        if (data->collectible->instances[i].x == new_x && data->collectible->instances[i].y == new_y && data->collectible->instances[i].enabled)
        {
            data->collectible->instances[i].enabled = false;
            collected++;
            printf("Collectible count: %d\n", (int)data->collectible->count);
        }
        i++;
    }

    if (new_x == data->exit->instances[0].x && new_y == data->exit->instances[0].y && (int)data->collectible->count == collected)
    {
        ft_printf("you win");
        clear_data(data);
        return (EXIT_SUCCESS);
    }
    return true;
}