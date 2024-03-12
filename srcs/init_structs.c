/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 17:13:07 by hlibine           #+#    #+#             */
/*   Updated: 2024/03/12 10:58:14 by hlibine          ###   ########.fr       */
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
	char	*tmp;

	mlx = galloc(sizeof(t_mlx));
	mlx->map = map_init(av);
	mlx->map_name = ft_substr(av, 5, ft_strlen(av) - 9);
	if (av[0] == 'm' || av[1] == 'a' || av[2] == 'p' || av[3] == 's')
		tmp = ft_strjoin("so_long | ", mlx->map_name);
	else
		tmp = mlx->map_name;
	initplayer(mlx);
	mlx->mlx = mlx_init();
	set_textures(mlx, mlx->map);
	set_sprites(mlx);
	mlx->mlx_win = mlx_new_window(mlx->mlx, mlx->map->width * SCALE,
			mlx->map->length * SCALE, tmp);
	return (mlx);
}
