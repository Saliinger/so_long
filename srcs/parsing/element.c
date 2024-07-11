/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   element.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/08 10:49:51 by anoukan           #+#    #+#             */
/*   Updated: 2024/07/11 13:51:12 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

void	ft_verify_element(t_map *map)
{
	int		i;
	int		j;
	t_map	*temp;

	i = 0;
	temp = map;
	while (temp->map[i] != NULL)
	{
		j = 0;
		while (temp->map[i][j] != '\n' && temp->map[i][j] != '\0')
		{
			if (temp->map[i][j] == 'E')
				temp->e += 1;
			if (temp->map[i][j] == 'P')
				temp->p += 1;
			if (temp->map[i][j] == 'C')
				temp->c += 1;
			if (temp->map[i][j] == '0')
				temp->s += 1;
			j++;
		}
		i++;
	}
}
