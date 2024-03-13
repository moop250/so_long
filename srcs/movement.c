/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 10:22:39 by hlibine           #+#    #+#             */
/*   Updated: 2024/03/13 22:31:18 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_ent_interact(t_mlx *game)
{
	char		coord;
	t_pointll	*tmp;

	tmp = game->map->points;
	coord = game->map->ent_map[game->player->pos->y][game->player->pos->x];
	if (coord == 'C')
	{
		while (tmp)
		{
			if (tmp->content->pos.x == game->player->pos->x &&
					tmp->content->pos.y == game->player->pos->y &&
					tmp->content->collected != 1)
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
}

void	sl_movedir(t_mlx *game, char **data, t_player *player, int dir)
{
	int	canmove;
	
	canmove = 1;
	if (dir == UP && (data[player->pos->y - 1][player->pos->x] != '1'))
		player->pos->y--;
	else if (dir == LEFT && (data[player->pos->y][player->pos->x - 1] != '1'))
		player->pos->x--;
	else if (dir == DOWN && (data[player->pos->y + 1][player->pos->x] != '1'))
		player->pos->y++;
	else if (dir == RIGHT && (data[player->pos->y][player->pos->x + 1] != '1'))
		player->pos->x++;
	else
		canmove = 0;
	if (canmove)
	{
		player->direction = dir;
		++player->moves;
		ft_putstr_fd("moves: ", 1);
		ft_putendl_fd(ft_itoa(player->moves), 1);
		render_game(game);
	}
}