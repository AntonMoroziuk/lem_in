/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoroziu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 12:11:14 by amoroziu          #+#    #+#             */
/*   Updated: 2018/12/29 15:44:37 by amoroziu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

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
		first = room_with_name(cur->first, map);
		second = room_with_name(cur->second, map);
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
	t_node	*to_del;

	i = -1;
	visited = (int*)malloc(sizeof(int) * map->rooms_count);
	while (++i < map->rooms_count)
		visited[i] = 0;
	visited[0] = 1;
	to_del = initialize_queue(&queue, map);
	while (queue.head)
	{
		cur = queue_popfront(&queue);
		work_with_vertix(visited, cur->room, &queue, map);
	}
	free(visited);
	free(to_del);
	if (map->end->bfs_level != 2147483647)
		return (0);
	return (1);
}

int				get_pathes(t_map *map)
{
	map->start->bfs_level = 0;
	if (!assign_bfs_level(map))
	{
		ft_putendl("ERROR: start and end are not connected!");
		return (0);
	}
	map->max_bfs = get_max_bfs_level(map);
//	delete_useless_links(map);
	allign_links(map);
	count_inputs_outputs(map);
	t_room *cur;
	cur = map->rooms;
	while (cur)
	{
		ft_printf("%s %d %d %d\n", cur->name, cur->inputs, cur->outputs, cur->bfs_level);
		cur = cur->next;
	}
//	ft_printf("!!!%d\n\n\n\n", map->start->outputs);
	delete_dead_ends(map);
	ft_printf("!!!%d\n\n\n\n", map->start->outputs);
	int i = 0;
	t_node *temp;
	temp = map->start->adj;
	while (temp)
	{
		i++;
		temp = temp->next;
	}
	ft_printf("%d\n", i);
	delete_input_forks(map);
//	ft_printf("!!!%d\n\n\n\n", map->start->outputs);
	delete_output_forks(map);
//	ft_printf("!!!%d\n\n\n\n", map->start->outputs);
	create_pathes(map);
	return (1);
}
