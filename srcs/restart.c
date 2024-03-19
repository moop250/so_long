/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   restart.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/19 22:52:10 by hlibine           #+#    #+#             */
/*   Updated: 2024/03/19 23:33:06 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	restart(t_mlx *game)
{
	t_pointll	*tmp_c;
	t_enemyll	*tmp_e;

	tmp_c = game->map->points;
	while (tmp_c)
	{
		tmp_c->content->collected = 0;
		tmp_c = tmp_c->next;
	}
	tmp_e = game->map->enemies;
	while (tmp_e)
	{
		tmp_e->content->pos.x = tmp_e->content->start_pos.x;
		tmp_e->content->pos.y = tmp_e->content->start_pos.y;
		tmp_e = tmp_e->next;
	}
	game->player->pos.x = game->map->spawn->x;
	game->player->pos.y = game->map->spawn->y;
	game->player->moves = 0;
	game->player->score = 0;
	expose_render(game);
}