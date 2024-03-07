/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 10:22:39 by hlibine           #+#    #+#             */
/*   Updated: 2024/03/05 12:23:01 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_ent_interact(t_mlx *game)
{
	char	coord;

	coord = game->map->ent_map[game->player->pos->y][game->player->pos->x];
	if (coord == 'C')
	{
		game->map->ent_map[game->player->pos->y][game->player->pos->x] = '0';
		game->player->score++;
	}
	else if (coord == 'E' && game->player->score == game->map->score_needed)
	{
		mlx_destroy_window(game->mlx, game->mlx_win);
		exit(1);
	}
}

int	sl_movedir(char **data, t_player *player, int direction, int count)
{
	if (direction == UP
			&& (data[player->pos->y - 1][player->pos->x] != '1'))
		player->pos->y--;
	else if (direction == LEFT
			&& (data[player->pos->y][player->pos->x - 1] != '1'))
		player->pos->x--;
	else if (direction == DOWN
			&& (data[player->pos->y + 1][player->pos->x] != '1'))
		player->pos->y++;
	else if (direction == RIGHT
			&& (data[player->pos->y][player->pos->x + 1] != '1'))
		player->pos->x++;
	else
		return (count);
	return (++count);
}