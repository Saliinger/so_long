#include "../../include/so_long.h"

// Verify wall && collectible
// Verify wall && collectible
bool collision(t_data *data, int new_x, int new_y)
{
    int i;

    // Check for boundaries
    if (new_x < 0 || new_x >= data->map->x * TILE_SIZE || new_y < 0 || new_y >= data->map->y * TILE_SIZE)
        return false;

    // Check for wall collision
    i = 0;
    while (i < (int)data->wall->count && data->wall->instances[i].enabled)
    {
        if (data->wall->instances[i].x == new_x && data->wall->instances[i].y == new_y)
            return false;
        i++;
    }

    // Check for collectible collision and update count
    i = 0;
    while (i < (int)data->collectible->count)
    {
        if (data->collectible->instances[i].x == new_x && data->collectible->instances[i].y == new_y && data->collectible->instances[i].enabled)
        {
            data->collectible->instances[i].enabled = false;
            data->collectible->count--;
            printf("Collectible count: %d\n", (int)data->collectible->count);
        }
        i++;
    }

    return true;
}