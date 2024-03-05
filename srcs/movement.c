/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 10:22:39 by hlibine           #+#    #+#             */
/*   Updated: 2024/03/05 10:36:38 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_collect_point(t_mlx *game)
{
	if (game->map->ent_map[game->player->pos->y][game->player->pos->x] == 'C')
	{
		game->map->ent_map[game->player->pos->y][game->player->pos->x] = '0';
		game->player->score++;
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