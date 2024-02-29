/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_parsing.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hlibine <hlibine@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/29 14:58:18 by hlibine           #+#    #+#             */
/*   Updated: 2024/02/29 15:14:18 by hlibine          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "so_long.h"

char	**map_parser(const char *av)
{
	int	fd;

	fd = open(av, O_RDONLY);
	read(fd, , 1);
}

t_map	*map_init(char *av)
{
	t_map	*map;

	map = galloc(sizeof(t_map));
	map->data = 
	return (map);
}
