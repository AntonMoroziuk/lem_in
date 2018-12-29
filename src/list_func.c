/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoroziu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 11:37:18 by amoroziu          #+#    #+#             */
/*   Updated: 2018/12/29 14:02:55 by amoroziu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_room	*room_with_name(char *name, t_map *map)
{
	t_room	*cur;

	cur = map->rooms;
	while (!ft_strequ(cur->name, name))
		cur = cur->next;
	return (cur);
}

void	add_room(t_map *map, t_room *room)
{
	t_room	*cur;

	map->rooms_count++;
	if (!map->rooms)
		map->rooms = room;
	else
	{
		cur = map->rooms;
		while (cur->next)
			cur = cur->next;
		cur->next = room;
	}
}
