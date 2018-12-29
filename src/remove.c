/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   remove.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoroziu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 11:54:19 by amoroziu          #+#    #+#             */
/*   Updated: 2018/12/29 14:02:55 by amoroziu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		remove_link(t_link **to_delete, t_link *prev, t_map *map)
{
	t_link	*temp;

	temp = *to_delete;
	if (!prev)
		map->links = temp->next;
	else
		prev->next = temp->next;
	*to_delete = temp->next;
	free(temp->first);
	free(temp->second);
	free(temp);
}

void		remove_node(t_room *room, t_node **to_remove, t_node *prev)
{
	t_node	*temp;

	if (room->bfs_level < (*to_remove)->room->bfs_level)
		room->outputs--;
	else
		room->inputs--;
	if (prev == NULL)
		room->adj = (*to_remove)->next;
	else
		prev->next = (*to_remove)->next;
	temp = *to_remove;
	(*to_remove) = temp->next;
	free(temp);
}

void		remove_room_from_adj(t_map *map, t_room *room)
{
	t_room	*cur;
	t_node	*node;
	t_node	*prev;

	cur = map->rooms;
	while (cur)
	{
		node = cur->adj;
		prev = NULL;
		while (node)
		{
			if (node->room == room)
				remove_node(cur, &node, prev);
			else
			{
				prev = node;
				node = node->next;
			}
		}
		cur = cur->next;
	}
}

void		remove_links_with_room(t_map *map, t_room *room)
{
	t_link	*cur;
	t_link	*prev;

	cur = map->links;
	prev = NULL;
	while (cur)
	{
		if (ft_strequ(cur->first, room->name) || ft_strequ(cur->second, room->name))
			remove_link(&cur, prev, map);
		else
		{
			prev = cur;
			cur = cur->next;
		}
	}
}
