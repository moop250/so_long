/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 17:13:07 by hlibine           #+#    #+#             */
/*   Updated: 2024/03/08 13:57:52 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	initplayer(t_mlx *game)
{
	t_player	*player;
	
	player = galloc(sizeof(t_player));
	player->pos = game->map->spawn;
	player->score = 0;
	player->moves = 0;
	game->player = player;
}

t_mlx	*sl_mlx_init(const char *av)
{
	t_mlx	*mlx;

	mlx = galloc(sizeof(t_mlx));
	mlx->map = map_init(av);
	mlx->map_name = ft_strdup(av);
	initplayer(mlx);
	mlx->mlx = mlx_init();
	mlx->mlx_win = mlx_new_window(mlx->mlx, mlx->map->width * SCALE,
			mlx->map->length * SCALE, "so_long");
	return (mlx);
}
