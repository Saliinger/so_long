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
# include "../libft/libft/libft.h"
# include "../libft/gnl/get_next_line.h"
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
	size_t 		y;
	size_t 		x;
	int		s;
}			t_map;

typedef struct s_data
{
    mlx_t  *mlx;
    mlx_image_t *image;
}           t_data;

// define
# define WIDTH 256
# define HEIGHT 256
# define BUFFER 42

// parsing
void		ft_parsing(t_map *map, char **argv);
void		ft_not_square(t_map *map);
int			ft_verify_wall(t_map *map);
int			ft_valid(t_map *map);
void 		ft_map_chequer(t_map *map, char **argv);
void		ft_verify_element(t_map *map);
size_t	open_fd(char **argv, t_map *map);

// window
int			ft_window(t_map *map);

// mouvement
void	ft_hook(void *param);

// utils
void ft_print(char **map);

#endif