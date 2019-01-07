/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete_input_forks.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoroziu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 10:43:25 by amoroziu          #+#    #+#             */
/*   Updated: 2018/12/29 14:02:55 by amoroziu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static int		good_input(t_room *room)
{
	t_node	*cur;
	int		childs_bfs;

	cur = room->adj;
	childs_bfs = room->bfs_level;
	while (childs_bfs > 1)
	{
		while (cur->room->bfs_level != childs_bfs - 1)
			cur = cur->next;
		if (cur->room->outputs != 1)
			return (0);
		cur = cur->room->adj;
		childs_bfs--;
	}
	return (1);
}

static t_room	*choose_best_input(t_room *room)
{
	t_node	*cur;
	t_room	*best;

	cur = room->adj;
	while (cur)
	{
		if (cur->room->bfs_level == room->bfs_level - 1)
		{
			if (good_input(cur->room))
			{
				best = cur->room;
				break;
			}
			best = cur->room;
		}
		cur = cur->next;
	}
	return (best);
}

static void		remove_other_adj(t_room *child, t_room *parent)
{
	t_node	*cur;
	t_node	*prev;

	cur = child->adj;
	prev = NULL;
	while (cur)
	{
		if (cur->room->bfs_level == child->bfs_level - 1 && cur->room != parent)
			remove_node(child, &cur, prev);
		else
		{
			prev = cur;
			cur = cur->next;
		}
	}
}

static void		remove_other_links(t_room *child, t_room *parent, t_map *map)
{
	t_link	*cur;
	t_link	*prev;

	remove_other_adj(child, parent);
	cur = map->links;
	prev = NULL;
	while (cur)
	{
		if (ft_strequ(cur->second, child->name) &&
			!ft_strequ(cur->first, parent->name))
			remove_link(&cur, prev, map);
		else
		{
			prev = cur;
			cur = cur->next;
		}
	}
}

void			delete_input_forks(t_map *map)
{
	t_room	*cur;
	t_room	*best_pred;
	int		i;

	i = 0;
	while (++i < map->max_bfs)
	{
		cur = map->rooms;
		while (cur)
		{
			if (cur->bfs_level == i)
			{
				best_pred = choose_best_input(cur);
				remove_other_links(cur, best_pred, map);
			}
			cur = cur->next;
		}
	}
}