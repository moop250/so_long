/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 17:13:07 by hlibine           #+#    #+#             */
/*   Updated: 2024/03/04 14:42:31 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_mlx	*sl_mlx_init(const char *av)
{
	t_mlx	*mlx;

	mlx = galloc(sizeof(t_mlx));
	mlx->map = map_init(av);
	mlx->player = mlx->map->spawn;
	mlx->moves = 0;
	mlx->mlx = mlx_init();
	mlx->mlx_win = mlx_new_window(mlx->mlx, mlx->map->width * 50,
			mlx->map->length * 50, "so_long");
	return (mlx);
}
