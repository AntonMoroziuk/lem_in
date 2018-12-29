/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoroziu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/24 16:22:17 by amoroziu          #+#    #+#             */
/*   Updated: 2018/12/29 14:02:55 by amoroziu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void			allign_links(t_map *map)
{
	t_link	*cur;
	t_room	*first;
	t_room	*second;
	char	*temp;

	cur = map->links;
	while (cur)
	{
		first = room_with_name(cur->first, map);
		second = room_with_name(cur->second, map);
		if (first->bfs_level > second->bfs_level)
		{
			temp = cur->first;
			cur->first = cur->second;
			cur->second = temp;
		}
		cur = cur->next;
	}
}

void			count_inputs_outputs(t_map *map)
{
	t_room	*cur;
	t_link	*link;

	cur = map->rooms;
	while (cur)
	{
		link = map->links;
		while (link)
		{
			if (ft_strequ(cur->name, link->first))
				cur->outputs++;
			else if (ft_strequ(cur->name, link->second))
				cur->inputs++;
			link = link->next;
		}
		cur = cur->next;
	}
}

void		delete_dead_ends(t_map *map)
{
	t_room	*cur_room;
	int		counter;

	counter = 1;
	while (counter)
	{
		cur_room = map->rooms;
		counter = 0;
		while (cur_room)
		{
			if ((cur_room->outputs == 0 || cur_room->inputs == 0) &&
				cur_room != map->start && cur_room != map->end)
			{
				remove_room_from_adj(map, cur_room);
				remove_links_with_room(map, cur_room);
				counter++;
			}
			cur_room = cur_room->next;
		}
	}
}
