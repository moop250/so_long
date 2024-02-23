/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 17:13:07 by hlibine           #+#    #+#             */
/*   Updated: 2024/02/23 17:31:56 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_mlx	*sl_mlx_init(void)
{
	t_mlx	*mlxlst;

	mlxlst = galloc(sizeof(t_mlx));
	mlxlst->mlx = mlx_init();
	mlxlst->mlx_win = mlx_new_window(mlxlst->mlx, WIDTH, HIGHT, "so_long");
	mlx_loop(mlxlst->mlx);
	return (mlxlst);
}

t_data	*sl_img_init(t_mlx *mlx)
{
	t_data *img;

	img = galloc(sizeof(t_data));
	img->img = mlx_new_image(mlx->mlx, WIDTH, HIGHT);
	img->addr - mlx_get_data_addr(img->img, &img->bits_per_pixel,
		&img->line_length, &img->endian);
	return (img);
}