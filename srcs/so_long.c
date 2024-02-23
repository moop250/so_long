/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:19:56 by hlibine           #+#    #+#             */
/*   Updated: 2024/02/23 15:41:05 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_mlx	*struct_init(void)
{
	t_mlx	*mlxlst;

	mlxlst = galloc(sizeof(t_mlx));
	mlxlst->mlx = mlx_init();
	mlxlst->mlx_win = mlx_new_window(mlxlst->mlx, 1920, 1080, "so_long");
	mlx_loop(mlxlst->mlx);
	return (mlxlst);
}

//int ac, char const **av
int	main(void)
{
	t_mlx	*mlxlst;

	mlxlst = struct_init();
	return (0);
}
