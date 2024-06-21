#include "../../include/so_long.h"

void ft_print(char **map)
{
    int i = 0;
    while (map[i])
    {
        ft_printf("%s", map[i]);
        i++;
    }
    ft_printf("\n\n");
}