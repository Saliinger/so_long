/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   is_ber.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/18 14:26:16 by anoukan           #+#    #+#             */
/*   Updated: 2024/07/18 15:03:49 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/so_long.h"

bool	is_ber(char *str)
{
	size_t	i;
	size_t	j;
	char	ber[] = ".ber";

	i = 0;
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
