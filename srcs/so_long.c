/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:19:56 by hlibine           #+#    #+#             */
/*   Updated: 2024/02/28 14:20:31 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	sl_error(char *msg)
{
	ft_putstr_fd("so_long error: ", 2);
	ft_putendl_fd(msg, 2);
	razegarbage();
	exit(EXIT_FAILURE);
}

void	mlx_mpp(t_data *data, int x, int y, int color)
{
	char	*out;

	out = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)out = color;
}

//int ac, char const **av
int	main(void)
{
	t_mlx	*mlx;
	t_data	*img;
	int		i;
	int		a;

	mlx = sl_mlx_init();
	img = sl_img_init(mlx->mlx);
	i = 10;
	a = 10;
	while (++i < 90)
	{
		mlx_mpp(img, i, a, 0x00FF0000);
	}
	while (++a < 90)
	{
		mlx_mpp(img, i, a, 0x00FF0000);
	}
	while (--i > 10)
	{
		mlx_mpp(img, i, a, 0x00FF0000);
	}
	while (--a > 10)
	{
		mlx_mpp(img, i, a, 0x00FF0000);
	}
	mlx_put_image_to_window(mlx->mlx, mlx->mlx_win, img->img, 0, 0);
	mlx_loop(mlx->mlx); //why tf error here???
	//ft_putendl_fd("im here", 2);
}