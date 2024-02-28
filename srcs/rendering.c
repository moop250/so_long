/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rendering.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/28 18:05:56 by hlibine           #+#    #+#             */
/*   Updated: 2024/02/28 18:28:08 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	render_next(t_mlx, )
{

}

// im gonna be honest, i dont quite get how im supposed to do this
int	render_game(t_mlx *game)
{
	t_data	img;

	img = sl_img_init(game->mlx);
	mlx_put_image_to_window(game->mlx, game->mlx_win, img->img, 0, 0);
}