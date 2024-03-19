/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 10:22:39 by hlibine           #+#    #+#             */
/*   Updated: 2024/03/20 00:01:28 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"
#include <limits.h>

void	put_moves(t_mlx *game)
{
	char	*tmp;

	put_image(game, game->map->wall.img, 0, 0);
	put_image(game, game->map->wall.img, 1, 0);
	put_image(game, game->map->wall.img, 2, 0);
	tmp = ft_strjoin("moves: ", ft_itoa(game->player->moves));
	mlx_string_put(game->mlx, game->mlx_win,
		SCALE / 10, SCALE / 2, 0xFFFFFF, tmp);
}

void	enem_interact(t_mlx *game, int x, int y)
{
	t_enemyll	*tmp;

	tmp = game->map->enemies;
	while (tmp)
	{
		if (tmp->content->pos.x == x && tmp->content->pos.y == y)
		{
			mlx_destroy_window(game->mlx, game->mlx_win);
			exit(EXIT_SUCCESS);
		}
		tmp = tmp->next;
	}
}

void	sl_ent_interact(t_mlx *game)
{
	char		coord;
	t_pointll	*tmp;

	tmp = game->map->points;
	coord = game->map->data[game->player->pos.y][game->player->pos.x];
	if (coord == 'C')
	{
		while (tmp)
		{
			if (tmp->content->pos.x == game->player->pos.x
				&& tmp->content->pos.y == game->player->pos.y
				&& tmp->content->collected != 1)
			{
				++game->player->score;
				tmp->content->collected = 1;
			}
			tmp = tmp->next;
		}
	}
	else if (coord == 'E' && game->player->score == game->map->score_needed)
	{
		mlx_destroy_window(game->mlx, game->mlx_win);
		exit(1);
	}
	enem_interact(game, game->player->pos.x, game->player->pos.y);
}

void	sl_movedir(t_mlx *game, char **data, t_player *player, int dir)
{
	int	canmove;

	canmove = 1;
	if (dir == UP && (data[player->pos.y - 1][player->pos.x] != '1'))
		player->pos.y--;
	else if (dir == LEFT && (data[player->pos.y][player->pos.x - 1] != '1'))
		player->pos.x--;
	else if (dir == DOWN && (data[player->pos.y + 1][player->pos.x] != '1'))
		player->pos.y++;
	else if (dir == RIGHT && (data[player->pos.y][player->pos.x + 1] != '1'))
		player->pos.x++;
	else
		canmove = 0;
	if (canmove)
	{
		player->direction = dir;
		++player->moves;
		put_moves(game);
		render_game(game);
	}
}
