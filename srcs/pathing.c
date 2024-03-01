/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/01 15:58:59 by hlibine           #+#    #+#             */
/*   Updated: 2024/03/01 17:37:16 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

void	dfs(char *map, )
{
	 
}

set_ents(t_map *map)
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
				spawn->pos_x = i[0];
				spawn->pos_y = i[1];
			}
			else if (map->data[i[0]][i[1]] == 'E')
			{
				exit->pos_x = i[0];
				exit->pos_y = i[1];
			}
		}
	}
	map->spawn = spawn;
	map->exit = exit;
}

char	*mapdup(char **data)
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
		map[a] = ft_strlcpy(map[a], data[a], len);
	}
	map[i] = NULL;
	return (map);
}

void	check_path(t_map *map)
{
	char	*map2;

	set_ents(map);
	map2 = mapdup(map->data);
	dfs(map, map2, );
}