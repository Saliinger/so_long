#include "../../include/so_long.h"

// Verify wall && collectible
bool collision(t_data *data, int new_x, int new_y)
{
    static int collected = 0;
    int i;

    // Check for wall collision
    if (data->map->map[new_y / 64][new_x / 64] == '1')
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
    }
    return true;
}