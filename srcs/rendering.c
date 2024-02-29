/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 18:05:56 by hlibine           #+#    #+#             */
/*   Updated: 2024/02/29 14:30:41 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_put_pixel(t_data *data, int x, int y, int color)
{
	char *pxl;

	if	(x >= 0 && x < WIDTH && y >= 0 && y < HIGHT)
	{
		pxl = data->addr + (y * data->line_length + x
			* (data->bits_per_pixel / 8));
		*(unsigned int *)pxl = color;
	}
}

// void	render_next(t_mlx, )
// {
	
// }

int	render_game(t_mlx *game)
{
	t_data	*img;

	img = sl_img_init(game->mlx);
	sl_put_pixel(img, 10, 10, 0x00FF0000);
	mlx_put_image_to_window(game->mlx, game->mlx_win, img->img, 0, 0);
	return (1);
}
