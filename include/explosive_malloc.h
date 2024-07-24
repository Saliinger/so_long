/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   explosive_malloc.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 13:16:00 by ekrebs            #+#    #+#             */
/*   Updated: 2024/07/24 15:15:37 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXPLOSIVE_MALLOC_H
# define EXPLOSIVE_MALLOC_H

#include <stdlib.h>
void    *ft_explosive_malloc(int size, const char * file, const char *func, int line);

#define malloc(x) ft_explosive_malloc(x, __FILE__, __FUNCTION__, __LINE__)
#endif