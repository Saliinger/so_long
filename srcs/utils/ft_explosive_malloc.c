/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_explosive_malloc.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekrebs <ekrebs@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/24 13:33:10 by ekrebs            #+#    #+#             */
/*   Updated: 2024/07/24 14:05:17 by ekrebs           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <stdio.h>
#define BOOM 4
void    *ft_explosive_malloc(int size,const char * file, const char *func, int line)
{
    int static tic_tac = 0;

    tic_tac++;
    if (tic_tac != BOOM)
        return (printf("\tmalloc %d...:bomb:\n", tic_tac), malloc(size));

    printf("\n\tmalloc %d : KABLEEWIE :boom:\n", tic_tac);
    printf("\t  in %s\n\t   in function `%s` at line %d\n", file, func, line);
    return (NULL);
}