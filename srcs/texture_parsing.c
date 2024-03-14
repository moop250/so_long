/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 11:57:49 by hlibine           #+#    #+#             */
/*   Updated: 2024/03/14 16:01:19 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	*xpm_address(char *path, int filenum)
{
	char	*tmp;
	char	*tmp2;
	tmp = ft_strjoin(path, ft_itoa(filenum));
	tmp2 = ft_strjoin(tmp, ".xpm");
	gfree(tmp);
	return (tmp2);
}

void	set_points(t_mlx *game)
{
	char	*tmp;
	t_sl	*point;
	int		i;
	t_xmp	*new;
	t_sl	*tmp2;

	i = 0;
	point = NULL;
	tmp = xpm_address(POINT_TEXTURES, i);
	while (access(tmp, F_OK) == 0)
	{
		new = galloc(sizeof(t_xmp));
		new->img = mlx_xpm_file_to_image(game->mlx, tmp, &new->width,
				&new->hight);
		if (!new->img)
			sl_error("xmp error");
		sl_lstadd_back(&point, sl_lstnew(new));
		gfree(tmp);
		tmp = xpm_address(POINT_TEXTURES, ++i);
	}
	gfree(tmp);
	tmp2 = sl_lstlast(point);
	tmp2->next = point;
	game->map->point_frames = point;
}

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
	tmp = ft_strjoin(MAP_TEXTURES, "exit.xpm");
	map->end.img = mlx_xpm_file_to_image(game->mlx, tmp, &map->end.width,
		&map->end.hight);
	if (!map->end.img)
		sl_error("xmp error");
	gfree(tmp);
	set_points(game);
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
	tmp = xpm_address(SPRITES, i);
	while (access(tmp, F_OK) == 0)
	{
		new = galloc(sizeof(t_xmp));
		new->img = mlx_xpm_file_to_image(game->mlx, tmp, &new->width,
				&new->hight);
		if (!new->img)
			sl_error("xmp error");
		sl_lstadd_back(&player, sl_lstnew(new));
		gfree(tmp);
		tmp = xpm_address(SPRITES, ++i);
	}
	gfree(tmp);
	tmp2 = sl_lstlast(player);
	tmp2->next = player;
	game->player->sprites = player;
	game->player->frame = game->player->sprites->content->img;
}
