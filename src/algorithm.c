/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoroziu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 12:11:14 by amoroziu          #+#    #+#             */
/*   Updated: 2018/12/29 13:35:30 by amoroziu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void		delete_useless_links(t_map *map)
{
	t_link	*cur;
	t_link	*prev;
	t_room	*first;
	t_room	*second;

	cur = map->links;
	prev = NULL;
	while (cur)
	{
		first = get_room(cur->first, map);
		second = get_room(cur->second, map);
		if (first->bfs_level == -1 || second->bfs_level == -1 ||
			first->bfs_level == second->bfs_level)
			remove_link(&cur, prev, map);
		else
		{
			prev = cur;
			cur = cur->next;
		}
	}
}

static void		work_with_vertix(int *visited, t_room *pred, t_queue *queue, t_map *map)
{
	t_node	*cur;

	cur = pred->adj;
	while (cur)
	{
		if (!visited[get_rooms_idx(cur->room->name, map)])
		{
			visited[get_rooms_idx(cur->room->name, map)] = 1;
			if (cur->room == map->end)
				map->end->bfs_level = 2147483647;
			else
				cur->room->bfs_level = pred->bfs_level + 1;
			if (cur->room->bfs_level != 2147483647)
				queue_pushback(cur, queue);
		}
		cur = cur->next;
	}
}

static int		get_max_bfs_level(t_map *map)
{
	int		i;
	t_room	*cur;

	i = 0;
	cur = map->rooms;
	while (cur)
	{
		if (cur->bfs_level > i && cur->bfs_level != 2147483647)
			i = cur->bfs_level;
		cur = cur->next;
	}
	return (i);
}

static int		assign_bfs_level(t_map *map)
{
	int		*visited;
	t_queue	queue;
	int		i;
	t_node	*cur;

	i = -1;
	visited = (int*)malloc(sizeof(int) * map->rooms_count);
	while (++i < map->rooms_count)
		visited[i] = 0;
	cur = (t_node*)malloc(sizeof(t_node));
	cur->room = map->start;
	cur->next = NULL;
	queue.head = cur;
	queue.tail = cur;
	while (queue.head)
	{
		cur = queue_popfront(&queue);
		work_with_vertix(visited, cur->room, &queue, map);
	}
	if (map->end->bfs_level != 2147483647)
		return (0);
	map->max_bfs = get_max_bfs_level(map);
	return (1);
}

int				get_pathes(t_map *map)
{
	if (!assign_bfs_level(map))
	{
		ft_putendl("ERROR: start and end are not connected!");
		return (0);
	}
	delete_useless_links(map);
	allign_links(map);
	count_inputs_outputs(map);
	delete_dead_ends(map);
	delete_input_forks(map);
	delete_output_forks(map);
	get_pathes(map);
	return (1);
}
