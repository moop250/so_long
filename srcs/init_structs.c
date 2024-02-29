/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_structs.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/23 17:13:07 by hlibine           #+#    #+#             */
/*   Updated: 2024/02/29 16:18:22 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

t_mlx	*sl_mlx_init(const char *av)
{
	t_mlx	*mlx;

	mlx = galloc(sizeof(t_mlx));
	mlx->mlx = mlx_init();
	mlx->mlx_win = mlx_new_window(mlx->mlx, WIDTH, HIGHT, "so_long");
	mlx->map = map_init(av);
	return (mlx);
}

t_data	*sl_img_init(void *mlx)
{
	t_data *img;

	img = galloc(sizeof(t_data));
	img->img = mlx_new_image(mlx, WIDTH, HIGHT);
	img->addr = mlx_get_data_addr(img->img, &img->bits_per_pixel,
		&img->line_length, &img->endian);
	return (img);
}