/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   points.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/20 11:53:53 by hlibine           #+#    #+#             */
/*   Updated: 2024/03/20 11:59:54 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	enem_behave(t_mlx *game, int x, int y)
{
	t_enemyll	*enem;

	enem = game->map->enemies;
	while (enem)
	{
		if (enem->content->pos.x == x && enem->content->pos.y == y)
		{
			render_enemy(game, enem->content);
			put_image(game, game->map->point_frames->content->img, x, y);
			return (1);
		}
		enem = enem->next;
	}
	return (0);
}
