/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_valid.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 13:54:27 by anoukan           #+#    #+#             */
/*   Updated: 2024/07/11 13:54:29 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

int	ft_valid(t_map *map)
{
	if (map->e == 1 && map->p == 1 && map->w == 1 && map->c >= 1 \
        && map->notsquare == 1 && map->s >= 1)
		return (1);
    else
	    return (ft_printf("parsing error\n map->e %d\n map->p %d\n map->w %d\n map->c %d\n map->notsquarre %d\n map->s %d\n",map->e, map->p, map->w, map->c, map->notsquare, map->s), 0);
}
