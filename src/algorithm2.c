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

static void	remove_room(t_map *map, t_room **cur, t_room *prev)
{
	t_room	*temp;

	if (!prev)
	{
		temp = *cur;
		*cur = (*cur)->next;
		delete_room(temp);
	}
	else
	{
		prev->next = (*cur)->next;
		delete_room(*cur);
		*cur = prev->next;
	}
}

static void	delete_unvisited(t_map *map)
{
	t_room	*cur;
	t_room	*prev;

	cur = map->rooms;
	prev = NULL;
	while (cur)
	{
		if (cur->bfs_level == -1)
		{
			remove_room_from_adj(map, cur);
			remove_links_with_room(map, cur);
			remove_room(map, &cur, prev);
		}
		else
		{
			prev = cur;
			cur = cur->next;
		}

	}
}

void		delete_dead_ends(t_map *map)
{
	t_room	*cur;
	t_room	*prev;
	int		depth;

	depth = map->max_bfs + 1;
	while (--depth > 0)
	{
		cur = map->rooms;
		prev = NULL;
		while (cur)
		{
			if (cur->bfs_level == depth && cur->outputs == 0)
			{
				remove_room_from_adj(map, cur);
				remove_links_with_room(map, cur);
				remove_room(map, &cur, prev);
			}
			else
			{
				prev = cur;
				cur = cur->next;
			}
		}
	}
}
