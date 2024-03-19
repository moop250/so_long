/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 15:36:20 by hlibine           #+#    #+#             */
/*   Updated: 2024/03/19 20:35:41 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

double	get_current_time(void)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return ((double)now.tv_sec + (double)now.tv_usec / 1000000.0);
}

void	enemies(t_mlx *game, double current_time)
{
	t_enemyll		*tmp;
	double			elapsed_time;

	tmp = game->map->enemies;
	
	while (tmp)
	{
		elapsed_time = current_time - tmp->content->last_frame_time;
		if (elapsed_time >= 1.0 / 2.0 && tmp != NULL)
		{
			if (tmp->content->waiting == 1)
			{
				if (elapsed_time >= 1.0)
					tmp->content->waiting = 0;
			}
			else
			{
				move_enemy(game, game->map->data, tmp->content, tmp->content->dir);
				tmp->content->last_frame_time = current_time;
			}
		}
		tmp = tmp->next;
	}
}

int	event(t_mlx *game)
{
	double			current_time;

	current_time = get_current_time();
	animate(game, current_time);
	enemies(game, current_time);
	return (1);
}