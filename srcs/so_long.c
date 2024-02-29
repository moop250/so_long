/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:19:56 by hlibine           #+#    #+#             */
/*   Updated: 2024/02/29 14:59:28 by hlibine          ###   ########.fr       */
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

int	sl_destroy(t_mlx *game)
{
	if (game)
	{
		if (game->mlx_win)
			mlx_destroy_window(game->mlx, game->mlx_win);
	}
	exit(1);
	return (1);
}

int	sl_keypress(int keycode, t_mlx *game)
{
	if(keycode == 53)
		sl_destroy(game);
	ft_putendl_fd(ft_itoa(keycode), 1);
	return (1);
}

int	mousepos(int x, int y, t_mlx *game)
{
	if (game)
		ft_putendl_fd("", 1);
	ft_putendl_fd(ft_itoa(x), 1);
	ft_putendl_fd(ft_itoa(y), 1);
	return (1);
}

void	mlx_mpp(t_data *data, int x, int y, int color)
{
	char	*out;

	out = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)out = color;
}


int	main(int ac, char const **av)
{
	t_mlx	*game;
	const char *tmp;

	if (ac > 2)
		sl_error("too many args");
	else if (ac != 2)
		sl_error("not enough args");
	game = sl_mlx_init(av[1]);
	mlx_expose_hook(game->mlx_win, render_game, game);
	mlx_hook(game->mlx_win, ON_KEYDOWN, 1L << 0, sl_keypress, game);
	mlx_hook(game->mlx_win, ON_DESTROY, 0, sl_destroy, game);
	mlx_loop(game->mlx);
}