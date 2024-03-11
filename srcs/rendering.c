/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 18:05:56 by hlibine           #+#    #+#             */
/*   Updated: 2024/03/11 15:31:55 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image(t_mlx *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx , game->mlx_win, img, x * SCALE, y * SCALE);
}

void	render_game(t_mlx *game)
{
	int	x;
	int	y;
	int	dir;

	x = game->player->pos->x;
	y = game->player->pos->y;
	dir = game->player->direction;
	put_image(game, game->map->floor.img, x, y);
	//put_image(game, img.sprite, x, y);
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
	int	x;
	int	y;

	y = -1;
	while (game->map->ent_map[++y])
	{
		x = -1;
		while (game->map->ent_map[y][++x])
		{
			if (game->map->ent_map[y][x] == 'C')
				put_image(game, game->map->point.img, x, y);
		}
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
	return (1);
}
