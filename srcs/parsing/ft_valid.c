#include "../../include/so_long.h"

int	ft_valid(t_map *map)
{
    t_map *temp;

    temp = map;
	if (temp->e == 1 && temp->p == 1 && temp->w == 1 && temp->c <= 1
		&& temp->notsquare == 1 && temp->s <= 1)
		return (1);
	return (0);
}