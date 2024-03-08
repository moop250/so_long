/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 18:05:56 by hlibine           #+#    #+#             */
/*   Updated: 2024/03/08 16:18:26 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	put_image(t_mlx *game, void *img, int x, int y)
{
	mlx_put_image_to_window(game->mlx , game->mlx_win, img, x * SCALE, y * SCALE);
}

int	render_game(t_mlx *game)
{
	int	x;
	int	y;
	int	dir;

	x = game->player->pos->x;
	y = game->player->pos->y;
	dir = game->player->direction;
	put_image(game, img.sprite, x, y);
	if (dir == UP)
		y += 1;
	else if (dir == LEFT)
		x += 1;
	else if (dir == DOWN)
		y -= 1;
	else
		x -= 1;
	put_image(game, img.floor, x, y);
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
			if (game->map->ent_map[y][x] == 'P')
				put_image(game, img.point, x, y);
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
				put_image(game, img.wall, x, y);
			else if (game->map->data[y][x] == 'E')
				put_image(game, img.exit, x, y);
			else
				put_image(game, img.floor, x, y);
		}
	}
	put_points(game);
}
