/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   list_func.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoroziu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 11:37:18 by amoroziu          #+#    #+#             */
/*   Updated: 2018/12/24 15:44:33 by amoroziu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

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
