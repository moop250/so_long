/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:58:59 by hlibine           #+#    #+#             */
/*   Updated: 2024/03/04 12:48:31 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

int	dfs(t_map *map, char **tmp_map, t_pos search, t_pos out)
{
	if (search.x < 0 || search.y < 0 ||
			search.x > map->width || search.y > map->length
			|| tmp_map[search.x][search.y] == 1)
		return (-1);
	if ((search.x == out.x && search.y == out.y)
			|| (search.x == out.x && search.y + 1 == out.y)
			|| (search.x == out.x && search.y - 1 == out.y)
			|| (search.x + 1 == out.x && search.y == out.y)
			|| (search.x - 1 == out.x && search.y == out.y))
		return (5);
	tmp_map[search.x][search.y] = 1;
	search.x++;
	if (dfs(map, tmp_map, search, out) >= 0)
		return (RIGHT);
	search.x -= 2;
	if (dfs(map, tmp_map, search, out) >= 0)
		return (LEFT);
	search.x++;
	search.y++;
	if(dfs(map, tmp_map, search, out) >= 0)
		return (UP);
	search.y -= 2;
	if (dfs(map, tmp_map, search, out) >= 0)
		return (DOWN);
	return (-1);
}

void	set_ents(t_map *map)
{
	t_pos	*spawn;
	t_pos	*exit;
	int		i[2];

	i[0] = 0;
	spawn = galloc(sizeof(t_pos));
	exit = galloc(sizeof(t_pos));
	while (map->data[++i[0]])
	{
		i[1] = -1;
		while (map->data[i[0]][++i[1]])
		{
			if (map->data[i[0]][i[1]] == 'P')
			{
				spawn->x = i[0];
				spawn->y = i[1];
			}
			else if (map->data[i[0]][i[1]] == 'E')
			{
				exit->x = i[0];
				exit->y = i[1];
			}
		}
	}
	map->spawn = spawn;
	map->exit = exit;
}

char	**mapdup(char **data)
{
	char	**map;
	int		i;
	int		a;
	int		len;

	i = 0;
	a = -1;
	len = ft_strlen(data[0]);
	while (data[i])
		++i;
	map = galloc(i * sizeof(char *));
	while (++a < i)
	{
		map[a] = galloc(len * sizeof(char));
		ft_strlcpy(map[a], data[a], len);
	}
	map[i] = NULL;
	return (map);
}

void	check_path(t_map *map)
{
	char	**map2;
	t_pos	spawn;
	t_pos	out;

	spawn = *map->spawn;
	out = *map->exit;
	set_ents(map);
	map2 = mapdup(map->data);
	if (dfs(map, map2, spawn, out) < 0)
		sl_error("pathing error: no path found");
}