/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.h                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/29 12:20:36 by anoukan           #+#    #+#             */
/*   Updated: 2024/01/22 18:06:12 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include "../libft/libft.h"

// Buffer
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

// base function
char	*get_next_line(int fd);

// utils function
char	*ft_strncpy(char *dest, char *src, unsigned int n);
int		ft_verify(char *stash);
char	*ft_clean(char *stash);

#endif
