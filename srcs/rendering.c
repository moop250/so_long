/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 18:05:56 by hlibine           #+#    #+#             */
/*   Updated: 2024/03/20 14:14:05 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image(t_mlx *game, void *img, int x, int y)
{
	if (x == game->map->exit.x && y == game->map->exit.y)
		mlx_put_image_to_window(game->mlx, game->mlx_win, game->map->end.img,
			x * SCALE, y * SCALE);
	else
		mlx_put_image_to_window(game->mlx, game->mlx_win, img,
			x * SCALE, y * SCALE);
}

void	put_player(t_mlx *game, t_player *player)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win, player->frame,
		player->pos.x * SCALE, player->pos.y * SCALE);
}

void	render_game(t_mlx *game)
{
	int	x;
	int	y;
	int	dir;

	x = game->player->pos.x;
	y = game->player->pos.y;
	dir = game->player->direction;
	put_image(game, game->map->floor.img, x, y);
	put_player(game, game->player);
	if (dir == UP)
		y += 1;
	else if (dir == LEFT)
		x += 1;
	else if (dir == DOWN)
		y -= 1;
	else
		x -= 1;
	put_image(game, game->map->floor.img, x, y);
}

void	put_points(t_mlx *game)
{
	int			i;
	t_pointll	*tmp;
	int			x;
	int			y;

	tmp = game->map->points;
	i = -1;
	while (++i < game->map->score_needed)
	{
		x = tmp->content->pos.x;
		y = tmp->content->pos.y;
		if (tmp->content->collected == 0)
		{
			if (enem_behave(game, x, y) == 1)
				return ;
			put_image(game, game->map->floor.img, x, y);
			put_image(game, game->map->point_frames->content->img, x, y);
		}
		tmp = tmp->next;
	}
}

int	expose_render(t_mlx *game)
{
	int	x;
	int	y;

	y = -1;
	while (game->map->data[++y])
	{
		x = -1;
		while (game->map->data[y][++x])
		{
			if (game->map->data[y][x] == '1')
				put_image(game, game->map->wall.img, x, y);
			else if (game->map->data[y][x] == 'E')
				put_image(game, game->map->end.img, x, y);
			else
				put_image(game, game->map->floor.img, x, y);
		}
	}
	put_points(game);
	put_player(game, game->player);
	put_enemies(game);
	put_moves(game);
	return (1);
}
