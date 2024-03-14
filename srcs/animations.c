/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   animations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/12 11:39:30 by hlibine           #+#    #+#             */
/*   Updated: 2024/03/14 15:41:34 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	mini_render(t_mlx *game)
{
	int	x;
	int	y;

	x = game->player->pos->x;
	y = game->player->pos->y;
	put_image(game, game->map->floor.img, x, y);
	put_player(game, game->player);
}

double	get_current_time(void)
{
	struct timeval	now;

	gettimeofday(&now, NULL);
	return ((double)now.tv_sec + (double)now.tv_usec / 1000000.0);
}

void	animate_player(t_mlx *game, double current_time)
{
	static double	last_frame_time = 0;
	double			elapsed_time;

	elapsed_time = current_time - last_frame_time;
	if (elapsed_time >= 1.0 / 7.0)
	{
		game->player->sprites = game->player->sprites->next;
		game->player->frame = game->player->sprites->content->img;
		mini_render(game);
		last_frame_time = current_time;
	}
}

void	animate_collectables(t_mlx *game, double current_time)
{
	static double	last_frame_time = 0;
	double			elapsed_time;

	elapsed_time = current_time - last_frame_time;
	if (elapsed_time >= 1.0 / 26.0)
	{
		game->map->point_frames = game->map->point_frames->next;
		put_points(game);
		last_frame_time = current_time;
	}
}

int	animate(t_mlx *game)
{
	double			current_time;

	current_time = get_current_time();
	animate_player(game, current_time);
	animate_collectables(game, current_time);
	return (1);
}
