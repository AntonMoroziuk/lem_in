/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   incorrect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoroziu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 13:44:49 by amoroziu          #+#    #+#             */
/*   Updated: 2019/01/08 15:09:53 by amoroziu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int			incorrect_link(t_map *map, t_link *link)
{
	t_link	*cur;

	cur = map->links;
	while (cur)
	{
		if ((cur->first == link->first &&
			cur->second == link->second) ||
			(cur->second == link->first &&
			cur->first == link->second))
		{
			free(link);
			ft_putendl("ERROR: Link already exists!");
			return (1);
		}
		cur = cur->next;
	}
	return (0);
}

int			incorrect_room(t_room *room, t_map *map)
{
	t_room	*cur;

	cur = map->rooms;
	while (cur)
	{
		if (ft_strequ(cur->name, room->name))
		{
			ft_putendl("ERROR: Room with this name already exists!");
			return (1);
		}
		else if (room->x == cur->x && room->y == cur->y)
		{
			ft_putendl("ERROR: Two rooms with same coordinates!");
			return (1);
		}
		cur = cur->next;
	}
	return (0);
}
