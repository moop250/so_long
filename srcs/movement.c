/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   movement.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/04 10:22:39 by hlibine           #+#    #+#             */
/*   Updated: 2024/03/04 15:16:20 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	sl_movedir(t_mlx *game, int direction, int count)
{
	if (direction == UP
			&& (game->map->data[game->player->y - 1][game->player->x] != '1'))
		game->player->y--;
	else if (direction == LEFT
			&& (game->map->data[game->player->y][game->player->x - 1] != '1'))
		game->player->x--;
	else if (direction == DOWN
			&& (game->map->data[game->player->y + 1][game->player->x] != '1'))
		game->player->y++;
	else if (direction == RIGHT
			&& (game->map->data[game->player->y][game->player->x + 1] != '1'))
		game->player->x++;
	else
		return (count);
	return (++count);
}