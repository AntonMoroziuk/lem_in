/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_output_forks.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoroziu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 11:32:22 by amoroziu          #+#    #+#             */
/*   Updated: 2018/12/29 13:12:56 by amoroziu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	get_distanse_to_end(t_room	*room, t_map *map)
{
	t_node	*cur;
	int		min_dist;

	min_dist = 2147483647;
	cur = room->adj;
	while (cur)
	{
		if (cur->room == map->end)
			return (1);
		if (cur->room->bfs_level > room->bfs_level &&
			cur->room->dist_to_end < min_dist)
			min_dist = cur->room->dist_to_end + 1;
		cur = cur->next;
	}
	return (min_dist);
}

static void	delete_other_outputs(t_room *room, t_room *next, t_map *map)
{
	t_link	*cur;
	t_link	*prev;

	cur = map->links;
	prev = NULL;
	while (cur)
	{
		if (ft_strequ(room->name, cur->first) &&
			!ft_strequ(cur->second, next->name))
			remove_link(&cur, prev, map);
		else
		{
			prev = cur;
			cur = cur->next;
		}
	}
}

static void	delete_other_pathes(t_room *room, t_room *next, t_map *map)
{
	t_node	*cur;
	t_node	*prev;

	cur = room->adj;
	prev = NULL;
	while (cur)
	{
		if (cur->room->dist_to_end == room->dist_to_end - 1 && cur->room != next)
			remove_node(room, &cur, prev);
		else
		{
			prev = cur;
			cur = cur->next;
		}
	}
	delete_other_outputs(room, next, map);
}

void		delete_output_forks(t_map *map)
{
	int		i;
	t_room	*cur;
	t_node	*next;

	i = map->max_bfs + 1;
	while (--i > 0)
	{
		cur = map->rooms;
		while (cur)
		{
			if (cur->bfs_level == i)
			{
				cur->dist_to_end = get_distanse_to_end(cur, map);
				next = cur->adj;
				while (next->room->dist_to_end != cur->dist_to_end - 1)
					next = next->next;
				delete_other_pathes(cur, next->room, map);
			}
			cur = cur->next;
		}
	}
}
