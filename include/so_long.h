/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: anoukan <anoukan@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/22 11:45:33 by anoukan           #+#    #+#             */
/*   Updated: 2024/07/25 16:08:01 by anoukan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

// include
# include "../MLX42/include/MLX42/MLX42.h"
# include "../libft/gnl/get_next_line.h"
# include "../libft/libft/libft.h"
# include "../libft/printf/ft_printf.h"
# include <fcntl.h>
# include <stdbool.h>
# include <stdlib.h>

// structure

typedef struct s_map
{
	int			fd;
	char		**map;
	int			e;
	int			p;
	int			w;
	int			c;
	int			notsquare;
	int			y;
	int			x;
	int			s;
	int			player_x;
	int			player_y;
	int			flood_fill_collectible;
	int			flood_fill_x;
	int			flood_fill_y;
	int			unexpected;
}				t_map;

typedef struct s_data
{
	mlx_t		*mlx;
	mlx_image_t	*wall;
	mlx_image_t	*background;
	mlx_image_t	*player;
	mlx_image_t	*exit;
	mlx_image_t	*collectible;
	t_map		*map;
	int			mouvement;
	int			current_move;
	int			new_x;
	int			new_y;
}				t_data;

// define
# define UP 0
# define DOWN 1
# define LEFT 2
# define RIGHT 3
# define TILE_SIZE 64
# define TILE_MOVE 64
//# define malloc(x) NULL

// parsing
void			ft_parsing(t_map *map, char **argv);
void			ft_not_square(t_map *map);
int				ft_verify_wall(t_map *map);
int				ft_valid(t_map *map);
void			ft_map_chequer(t_map *map, char **argv);
void			ft_verify_element(t_map *map);
size_t			open_fd(char **argv, t_map *map);
bool			is_ber(char *str);
void			flood_fill(t_map *map, char **temp);
bool			border_are_straight(t_map *map);

// window
int				ft_window(t_map *map);

// movement
void			ft_hook(mlx_key_data_t keydata, void *param);
bool			collision(t_data *data, int x, int y);

// utils
void			ft_print(char **map);
void			clear_data(t_data *data);
void			free_map(t_map *map);
char			**map_c(t_map *map);
void			clear_img(t_data *data);

// error
void			ft_error(t_data *data);
void			to_large(t_map *map);
void			wall(t_map *map);
void			map_empty(t_map *map);
void			border_not_straight(t_map *map);

// image
void			init_map(t_map *map, t_data *data);
void			init_image(t_data *data);
void			init_bg(t_map *map, t_data *data);

#endif
