#include "../../include/so_long.h"

void flood_fill(t_map *map)
{
    int temp_x;
    int temp_y;

    if (map->map[map->flood_fill_x][map->flood_fill_y] && map->map[map->flood_fill_x][map->flood_fill_y] != 'F' && map->map[map->flood_fill_x][map->flood_fill_y] != '1')
    {
        if (map->map[map->flood_fill_x][map->flood_fill_y] == 'C' || map->map[map->flood_fill_x][map->flood_fill_y] == 'E')
            map->flood_fill_collectible +=1;
        if (map->map[map->flood_fill_x][map->flood_fill_y] != '1' && map->map[map->flood_fill_x][map->flood_fill_y] != '\0' && map->map[map->flood_fill_x][map->flood_fill_y] != '\n')
            map->map[map->flood_fill_x][map->flood_fill_y] = 'F';
    }
    else
        return;
    temp_x = map->flood_fill_x;
    temp_y = map->flood_fill_y;
    map->flood_fill_x = temp_x - 1;
    flood_fill(map);
    map->flood_fill_x = temp_x;
    map->flood_fill_x = temp_x + 1;
    flood_fill(map);
    map->flood_fill_x = temp_x;
    map->flood_fill_y = temp_y - 1;
    flood_fill(map);
    map->flood_fill_y = temp_y;
    map->flood_fill_y = temp_y + 1;
    flood_fill(map);
    map->flood_fill_y = temp_y;
}