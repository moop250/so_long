/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   enemies.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 17:28:41 by hlibine           #+#    #+#             */
/*   Updated: 2024/03/20 10:48:15 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	checkback(t_mlx *game, int x, int y)
{
	t_pointll	*point;
	t_enemyll	*enemies;

	point = game->map->points;
	enemies = game->map->enemies;
	while (point)
	{
		if (point->content->pos.x == x && point->content->pos.y == y
			&& point->content->collected == 0)
			return (1);
		point = point->next;
	}
	while (enemies)
	{
		if (enemies->content->pos.x == x && enemies->content->pos.y == y)
			return (1);
		enemies = enemies->next;
	}
	return (0);
}

void	put_enemy(t_mlx *game, t_enemy *enemy)
{
	mlx_put_image_to_window(game->mlx, game->mlx_win,
		game->map->enemy_texture->content->img,
		enemy->pos.x * SCALE, enemy->pos.y * SCALE);
}

void	render_enemy(t_mlx *game, t_enemy *enemy)
{
	int	x;
	int	y;
	int	dir;

	x = enemy->pos.x;
	y = enemy->pos.y;
	dir = enemy->dir;
	put_enemy(game, enemy);
	if (dir == UP)
		y += 1;
	else if (dir == LEFT)
		x += 1;
	else if (dir == DOWN)
		y -= 1;
	else
		x -= 1;
	if (checkback(game, x, y) == 0)
		put_image(game, game->map->floor.img, x, y);
}

int	new_dir(int canmove, int dir)
{
	if (canmove == 0)
	{
		if (dir == UP)
			dir = DOWN;
		else if (dir == DOWN)
			dir = UP;
		else if (dir == LEFT)
			dir = RIGHT;
		else if (dir == RIGHT)
			dir = LEFT;
	}
	return (dir);
}

void	move_enemy(t_mlx *game, char **data, t_enemy *enemy, int dir)
{
	int	canmove;

	canmove = 1;
	if (dir == UP && (data[enemy->pos.y - 1][enemy->pos.x] != '1'))
		enemy->pos.y--;
	else if (dir == LEFT && (data[enemy->pos.y][enemy->pos.x - 1] != '1'))
		enemy->pos.x--;
	else if (dir == DOWN && (data[enemy->pos.y + 1][enemy->pos.x] != '1'))
		enemy->pos.y++;
	else if (dir == RIGHT && (data[enemy->pos.y][enemy->pos.x + 1] != '1'))
		enemy->pos.x++;
	else
		canmove = 0;
	if (canmove)
	{
		render_enemy(game, enemy);
		enem_interact(game, game->player->pos.x, game->player->pos.y);
	}
	else
		enemy->waiting = 1;
	enemy->dir = new_dir(canmove, dir);
}
