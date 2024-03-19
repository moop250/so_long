/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ent_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/18 13:58:23 by hlibine           #+#    #+#             */
/*   Updated: 2024/03/19 23:24:22 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	enemy_parser(t_map *map, int x, int y, char dir)
{
	t_enemy	*new;

	new = galloc(sizeof(t_enemy));
	new->pos.x = x;
	new->pos.y = y;
	new->start_pos.x = x;
	new->start_pos.y = y;
	if (dir == 'V')
		new->dir = UP;
	else
		new->dir = LEFT;
	new->waiting = 0;
	sl_addenemy_front(&map->enemies, sl_lstnewenemy(new));
}

void	point_parser(t_map *map, int x, int y)
{
	t_point	*new;

	++map->score_needed;
	new = galloc(sizeof(t_point));
	new->pos.x = x;
	new->pos.y = y;
	new->collected = 0;
	sl_lstadd_front(&map->points, sl_lstnewpoint(new));
}

void	ent_parser(t_map *map, int x, int y, char pos)
{
	if (pos == 'C')
		point_parser(map, x, y);
	else if (pos == 'V' || pos == 'H')
		enemy_parser(map, x, y, pos);
}

void	ent_checker(char in)
{
	if (in != '1' && in != '0' && in != 'C' && in != 'V' && in != 'H'
			&& in != 'E' && in != 'P')
		sl_error("invalid map object");
}

void	object_parser(t_map *map)
{
	int		y;
	int		x;
	int		ents[2];
	char	pos;

	y = 0;
	ents[0] = 0;
	ents[1] = 0;
	map->enemies = NULL;
	while (map->data[++y])
	{
		x = -1;
		while (map->data[y][++x])
		{
			pos = map->data[y][x];
			if (pos == 'C' || pos == 'V' || pos == 'H')
				ent_parser(map, x, y, pos);
			else if (pos == 'E')
				++ents[0];
			else if (pos == 'P')
				++ents[1];
			ent_checker(pos);
		}
	}
	if (map->score_needed < 1 || ents[0] != 1 || ents[1] != 1)
		sl_error("invalid map");
}