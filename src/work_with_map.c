/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   work_with_map.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoroziu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 09:45:44 by amoroziu          #+#    #+#             */
/*   Updated: 2018/12/29 15:44:49 by amoroziu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		work_with_map(t_map *map)
{
	int		i;
	t_room	*cur;

	cur = map->rooms;
	i = -1;
	map->rooms_array = (char**)malloc(sizeof(char*) * (map->rooms_count + 1));
	while (++i < map->rooms_count)
	{
		map->rooms_array[i] = ft_strdup(cur->name);
		cur = cur->next;
	}
	map->rooms_array[i] = NULL;
}
