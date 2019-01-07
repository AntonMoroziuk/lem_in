/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   incorrect.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoroziu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/16 13:44:49 by amoroziu          #+#    #+#             */
/*   Updated: 2018/12/29 14:03:35 by amoroziu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static int	room_exists(t_map *map, char *name)
{
	t_room	*cur;

	cur = map->rooms;
	while (cur)
	{
		if (ft_strequ(cur->name, name))
			return (1);
		cur = cur->next;
	}
	return (0);
}

static int	check_rooms(t_map *map, t_link *link)
{
	if (!room_exists(map, link->first) ||
		!room_exists(map, link->second))
	{
		ft_putendl("ERROR: Room does not exist!");
		return (1);
	}
	return (0);
}

int			incorrect_link(t_map *map, t_link *link)
{
	t_link	*cur;

	cur = map->links;
	if (check_rooms(map, link))
				return (1);
	while (cur)
	{
		if ((ft_strequ(cur->first, link->first) &&
			ft_strequ(cur->second, link->second)) ||
			(ft_strequ(cur->second, link->first) &&
			ft_strequ(cur->first, link->second)))
		{
			ft_putendl("ERROR: Link already exists!");
			return (1);
		}
		cur = cur->next;
	}
	return (0);
}

int 		incorrect_room(t_room *room, t_map *map)
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
