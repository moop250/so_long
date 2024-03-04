/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 10:22:39 by hlibine           #+#    #+#             */
/*   Updated: 2024/03/04 15:45:39 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

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