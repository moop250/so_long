/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 11:57:49 by hlibine           #+#    #+#             */
/*   Updated: 2024/03/13 11:23:24 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_textures(t_mlx *game, t_map *map)
{
	char	*tmp;

	tmp = ft_strjoin(MAP_TEXTURES, "floor.xpm");
	map->floor.img = mlx_xpm_file_to_image(game->mlx, tmp, &map->floor.width,
		&map->floor.hight);
	if (!map->floor.img)
		sl_error("xmp error");
	gfree(tmp);
	tmp = ft_strjoin(MAP_TEXTURES, "wall.xpm");
	map->wall.img = mlx_xpm_file_to_image(game->mlx, tmp, &map->wall.width,
		&map->wall.hight);
	gfree(tmp);
	if (!map->wall.img)
		sl_error("xmp error");
	tmp = ft_strjoin(MAP_TEXTURES, "point.xpm");
	map->point.img = mlx_xpm_file_to_image(game->mlx, tmp, &map->point.width,
		&map->point.hight);
	if (!map->point.img)
		sl_error("xmp error");
	gfree(tmp);
	tmp = ft_strjoin(MAP_TEXTURES, "exit.xpm");
	map->end.img = mlx_xpm_file_to_image(game->mlx, tmp, &map->end.width,
		&map->end.hight);
	if (!map->end.img)
		sl_error("xmp error");
	gfree(tmp);
}

void	set_sprites(t_mlx *game)
{
	char	*tmp;
	t_sl	*player;
	int		i;
	t_xmp	*new;
	t_sl	*tmp2;

	i = 0;
	player = NULL;
	tmp = ft_strjoin("player_sprites/player_", ft_itoa(i));
	tmp = ft_strjoin(tmp, ".xpm");
	while (access(tmp, F_OK) == 0)
	{
		new = galloc(sizeof(t_xmp));
		new->img = mlx_xpm_file_to_image(game->mlx, tmp, &new->width,
				&new->hight);
		sl_lstadd_back(&player, sl_lstnew(new));
		gfree(tmp);
		tmp = ft_strjoin("player_sprites/player_", ft_itoa(++i));
		tmp = ft_strjoin(tmp, ".xpm");
	}
	gfree(tmp);
	tmp2 = sl_lstlast(player);
	tmp2->next = player;
	game->player->sprites = player;
	game->player->frame = game->player->sprites->content->img;
}

/* void	set_sprites(t_mlx *game)
{
	char		*tmp;
	t_player	*player;
	
	player = game->player;
	tmp = ft_strjoin(SPRITES, "player_1.xpm");
	player->sprite.img = mlx_xpm_file_to_image(game->mlx, tmp,
		&player->sprite.width, &player->sprite.hight);
	gfree(tmp);
} */
