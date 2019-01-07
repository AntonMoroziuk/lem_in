/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_link.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoroziu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 11:48:24 by amoroziu          #+#    #+#             */
/*   Updated: 2018/12/29 14:02:55 by amoroziu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static void	add_adj(t_room *room, char *name, t_map *map)
{
	t_node	*new;
	t_room	*temp;

	new = (t_node*)malloc(sizeof(t_node));
	temp = map->start;
	while (!ft_strequ(temp->name, name))
		temp = temp->next;
	new->room = temp;
	new->next = room->adj;
	room->adj = new;
}

void		add_link_to_rooms(t_map *map, t_link *link)
{
	t_room	*cur;

	cur = map->rooms;
	while (cur)
	{
		if (ft_strequ(cur->name, link->first))
			add_adj(cur, link->second, map);
		else if (ft_strequ(cur->name, link->second))
			add_adj(cur, link->first, map);
		cur = cur->next;
	}
}
