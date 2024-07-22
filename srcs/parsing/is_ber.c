/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_ber.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 14:26:16 by anoukan           #+#    #+#             */
/*   Updated: 2024/07/22 11:08:07 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

bool	is_ber(char *str)
{
	size_t	i;
	size_t	j;
	char	*ber;

	i = 0;
	ber = ".ber";
	while (str[i] != '\0')
		i++;
	i -= 4;
	j = 0;
	while (str[i] == ber[j] && str[i] && ber[j])
	{
		i++;
		j++;
	}
	if (j == ft_strlen(ber))
		return (true);
	else
		return (false);
}
