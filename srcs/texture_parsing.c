/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   texture_parsing.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/11 11:57:49 by hlibine           #+#    #+#             */
/*   Updated: 2024/03/11 15:09:11 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	set_textures(t_mlx *game, t_map *map)
{
	char	*tmp;

	tmp = ft_strjoin(MAP_TEXTURES, "floor.xpm");
	map->floor.img = mlx_xpm_file_to_image(game->mlx, tmp, &map->floor.width,
		&map->floor.hight);
	gfree(tmp);
	tmp = ft_strjoin(MAP_TEXTURES, "wall.xpm");
	map->wall.img = mlx_xpm_file_to_image(game->mlx, tmp, &map->wall.width,
		&map->wall.hight);
	gfree(tmp);
	tmp = ft_strjoin(MAP_TEXTURES, "point.xpm");
	map->point.img = mlx_xpm_file_to_image(game->mlx, tmp, &map->point.width,
		&map->point.hight);
	gfree(tmp);
	tmp = ft_strjoin(MAP_TEXTURES, "exit.xpm");
	map->end.img = mlx_xpm_file_to_image(game->mlx, tmp, &map->end.width,
		&map->end.hight);
	gfree(tmp);
}

/* void	set_sprites(t_mlx *game)
{
	//
} */