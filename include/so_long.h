/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:45:33 by anoukan           #+#    #+#             */
/*   Updated: 2024/06/14 15:15:34 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// include
# include "../libft/gnl/get_next_line.h"
# include "../libft/libft/libft.h"
# include "../libft/printf/ft_printf.h"
# include "../MLX42/include/MLX42/MLX42.h"
# include <fcntl.h>
# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

// structure

typedef struct s_map
{
	int		fd;
	char	**map;
	int		e;
	int		p;
	int		w;
	int		c;
	int		notsquare;
	int		y;
	int		x;
	int		s;
}			t_map;

// define
# define WIDTH 256
# define HEIGHT 256

// parsing
void		ft_parsing(t_map map, char **argv);
void		ft_not_square(t_map map);
int			ft_verify_wall(t_map map);
int			ft_valid(t_map map);
void		ft_map_chequer(t_map map, char **argv);
void		ft_verify_element(t_map map);

// window
int			ft_window(t_map map);

#endif