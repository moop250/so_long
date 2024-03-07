/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   so_long.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/22 11:19:56 by hlibine           #+#    #+#             */
/*   Updated: 2024/03/07 13:28:37 by hlibine          ###   ########.fr       */
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
	int			mvs;
	t_player	*player;

	player = game->player;
	mvs = player->moves;
	if (keycode == 53 || keycode == 65307)
		sl_destroy(game);
	else if (keycode == 119)
		player->moves = sl_movedir(game->map->data, game->player, UP, mvs);
	else if (keycode == 97)
		player->moves = sl_movedir(game->map->data, game->player, LEFT, mvs);
	else if (keycode == 115)
		player->moves = sl_movedir(game->map->data, game->player, DOWN, mvs);
	else if (keycode == 100)
		player->moves = sl_movedir (game->map->data, game->player, RIGHT, mvs);
	sl_collect_point(game);
	ft_putendl_fd(ft_itoa(keycode), 2);
	ft_putendl_fd(ft_itoa(game->player->score), 2);
	ft_putstr_fd("moves: ", 1);
	ft_putendl_fd(ft_itoa(game->player->moves), 1);
	render_game(game);
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
	mlx_expose_hook(game->mlx_win, render_game, game);
	mlx_hook(game->mlx_win, ON_KEYDOWN, 1L << 0, sl_keypress, game);
	mlx_hook(game->mlx_win, ON_DESTROY, 0, sl_destroy, game);
	mlx_loop(game->mlx);
}
