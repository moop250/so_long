/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:19:52 by hlibine           #+#    #+#             */
/*   Updated: 2024/02/29 18:55:01 by hlibine          ###   ########.fr       */
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

// Resolution defaults

# define WIDTH 1920
# define HIGHT 1080

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
	int	pos_x;
	int	pos_y;
}		t_pos;

typedef struct	s_map
{
	char	**data;
	int		score_needed;
	int		length;
	int		width;
	t_pos	spawn;
	t_pos	exit;
}			t_map;

typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;

typedef struct	s_mlx
{
	void	*mlx;
	void	*mlx_win;
	t_map	*map;
}			t_mlx;

// Custom functions

t_mlx	*sl_mlx_init(const char *av);
t_data	*sl_img_init(void *mlx);
void	sl_error(char *msg);
int		render_game(t_mlx *game);
t_map	*map_init(const char *av);

#endif
