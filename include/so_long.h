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
	int 		y;
	int 		x;
	int		s;
    int player_x;
    int player_y;
}			t_map;

typedef struct s_data
{
    mlx_t  *mlx;
    mlx_image_t *wall;
    mlx_image_t *background;
    mlx_image_t *player;
    mlx_image_t *exit;
    mlx_image_t *collectible;
    t_map       *map;
}           t_data;

// define
# define UP 0
# define DOWN 1
# define LEFT 2
# define RIGHT 3
# define TILE_SIZE 64

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
void	ft_hook(mlx_key_data_t keydata, void *param);
//void render_map(t_data *data);
bool collision(t_data *data, int x, int y);

// utils
void ft_print(char **map);
void ft_error(t_data *data);
void clear_data(t_data *data);


//image
void init_map(t_map *map, t_data *data);
void init_image(t_data *data);
void init_bg(t_map *map, t_data *data);

#endif