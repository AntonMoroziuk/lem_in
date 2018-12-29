/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoroziu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 09:45:44 by amoroziu          #+#    #+#             */
/*   Updated: 2018/12/28 16:36:41 by amoroziu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	create_rooms_array(t_map *map)
{
	int		i;
	t_room	*cur;

	cur = map->rooms;
	i = -1;
	map->rooms_array = (char**)malloc(sizeof(char*) * map->rooms_count);
	while (++i < map->rooms_count)
	{
		map->rooms_array[i] = ft_strdup(cur->name);
		cur = cur->next;
	}
}

static void	create_adjecency_matrix(t_map *map)
{
	int		i;
	int		j;
	t_link	*cur;

	i = 0;
	map->matrix = (int**)malloc(sizeof(int*) * map->rooms_count);
	map->matrix[0] = (int*)malloc(sizeof(int) * SQR(map->rooms_count));
	while (++i < map->rooms_count)
		map->matrix[i] = map->matrix[0] + i * map->rooms_count;
	i = -1;
	while (++i < map->rooms_count)
	{
		j = -1;
		while (++j < map->rooms_count)
			map->matrix[i][j] = 0;
	}
	cur = map->links;
	while (cur)
	{
		map->matrix[get_rooms_idx(cur->first, map)][get_rooms_idx(
				cur->second, map)] = 1;
		map->matrix[get_rooms_idx(cur->second, map)][get_rooms_idx(
				cur->first, map)] = 1;
		cur = cur->next;
	}
}

void		work_with_map(t_map *map)
{
	create_rooms_array(map);
	create_adjecency_matrix(map);
}
