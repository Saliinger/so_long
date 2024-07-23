#include "../../include/so_long.h"

void flood_fill(t_map *map)
{
    if (map->map[map->flood_fill_x][map->flood_fill_y] != 'F')
    {
        if (map->map[map->flood_fill_x][map->flood_fill_y] == 'C' || map->map[map->flood_fill_x][map->flood_fill_y] == 'E')
            map->flood_fill_collectible +=1;
        if (map->map[map->flood_fill_x][map->flood_fill_y] != '1' && map->map[map->flood_fill_x][map->flood_fill_y] != '\0' && map->map[map->flood_fill_x][map->flood_fill_y] != '\n')
            map->map[map->flood_fill_x][map->flood_fill_y] = 'F';
    }

    flood_fill(map);
}