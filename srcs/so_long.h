/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:19:52 by hlibine           #+#    #+#             */
/*   Updated: 2024/03/07 13:18:33 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SO_LONG_H
# define SO_LONG_H

# include <math.h>
# include "../libs/extended_ft/srcs/extended_ft.h"
# include <fcntl.h>
# include <stdio.h>

// Compatibilty stuff
# ifdef __APPLE__
#  include "../libs/minilibx_opengl/mlx.h"
# endif

# ifndef __APPLE__
#  include "../libs/minilibx-linux/mlx.h"
# endif

// Directions

# define LEFT 0
# define DOWN 1
# define RIGHT 2
# define UP 3

// X11 events

enum {
	ON_KEYDOWN = 2,
	ON_KEYUP = 3,
	ON_MOUSEDOWN = 4,
	ON_MOUSEUP = 5,
	ON_MOUSEMOVE = 6,
	ON_EXPOSE = 12,
	ON_DESTROY = 17
};

// Structs

typedef struct s_pos
{
	int	x;
	int	y;
}		t_pos;

typedef struct s_player
{
	t_pos	*pos;
	int		moves;
	int		score;
	int		direction;
}			t_player;

typedef struct s_map
{
	char	**data;
	char	**ent_map;
	int		score_needed;
	int		length;
	int		width;
	t_pos	*spawn;
	t_pos	*exit;
}			t_map;

typedef struct s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

typedef struct s_mlx
{
	void		*mlx;
	void		*mlx_win;
	t_map		*map;
	t_player	*player;
}			t_mlx;

// Custom functions

t_mlx	*sl_mlx_init(const char *av);
void	sl_error(char *msg);
int		render_game(t_mlx *game);
t_map	*map_init(const char *av);
void	check_path(t_map *map);
int		sl_movedir(char **data, t_player *player, int direction, int count);
void	sl_collect_point(t_mlx *game);
char	**mapdup(char **data);
void	sl_collect_point(t_mlx *game);

#endif
