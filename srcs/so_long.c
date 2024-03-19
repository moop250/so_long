/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:19:56 by hlibine           #+#    #+#             */
/*   Updated: 2024/03/19 23:02:01 by hlibine          ###   ########.fr       */
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
	exit(EXIT_SUCCESS);
	return (1);
}

int	sl_keypress(int keycode, t_mlx *game)
{
	t_player	*player;

	player = game->player;
	if (keycode == 53 || keycode == 65307)
		sl_destroy(game);
	else if (keycode == 114)
	{
		restart(game);
		return (1);
	}
	else if (keycode == 13 || keycode == 119)
		player->direction = UP;
	else if (keycode == 0 || keycode == 97)
		player->direction = LEFT;
	else if (keycode == 1 || keycode == 115)
		player->direction = DOWN;
	else if (keycode == 2 || keycode == 100)
		player->direction = RIGHT;
	sl_movedir (game, game->map->data, game->player, player->direction);
	sl_ent_interact(game);
	ft_putendl_fd(ft_itoa(keycode), 2);
	return (1);
}

int	main(int ac, char const **av)
{
	t_mlx	*game;

	if (ac > 2)
		sl_error("too many args");
	else if (ac != 2)
		sl_error("not enough args");
	game = sl_mlx_init(av[1]);
	mlx_expose_hook(game->mlx_win, expose_render, game);
	mlx_hook(game->mlx_win, ON_KEYDOWN, 1L << 0, sl_keypress, game);
	mlx_hook(game->mlx_win, ON_DESTROY, 0, sl_destroy, game);
	mlx_loop_hook(game->mlx, event, game);
	mlx_loop(game->mlx);
}
