/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algorithm.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoroziu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 12:11:14 by amoroziu          #+#    #+#             */
/*   Updated: 2019/01/08 14:29:32 by amoroziu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static int		work_with_vertix(t_room *pred, t_bfs *bfs, t_map *map)
{
	t_link	*cur;
	int		pred_idx;
	int		cur_idx;

	cur = map->links;
	pred_idx = get_rooms_idx(pred, map);
	while (cur)
	{
		cur_idx = -1;
		if (cur->first == pred && !bfs->visited[cur->second->idx])
			cur_idx = cur->second->idx;
		else if (cur->second == pred && !bfs->visited[cur->first->idx])
			cur_idx = cur->first->idx;
		if (cur_idx != -1)
		{
			bfs->dist[cur_idx] = bfs->dist[pred_idx] + 1;
			bfs->pred[cur_idx] = pred;
			bfs->visited[cur_idx] = 1;
			queue_pushback(cur, pred, bfs->queue);
			if (cur->first == map->end || cur->second == map->end)
				return (1);
		}
		cur = cur->next;
	}
	return (0);
}

static void		initialize_bfs(t_bfs *bfs, t_map *map, int *used_rooms)
{
	int			i;

	bfs->visited = (int*)malloc(sizeof(int) * map->rooms_count);
	bfs->dist = (int*)malloc(sizeof(int) * map->rooms_count);
	bfs->pred = (t_room**)malloc(sizeof(t_room*) * map->rooms_count);
	i = -1;
	while (++i < map->rooms_count)
	{
		bfs->visited[i] = used_rooms[i];
		bfs->dist[i] = 2147483647;
		bfs->pred[i] = NULL;
	}
	bfs->visited[map->start->idx] = 1;
	bfs->dist[map->start->idx] = 0;
	bfs->queue = (t_queue*)malloc(sizeof(t_queue));
	bfs->queue->head = NULL;
	bfs->queue->tail = NULL;
	bfs->queue->head = (t_node*)malloc(sizeof(t_node));
	bfs->queue->tail = bfs->queue->head;
	bfs->queue->head->room = map->start;
	bfs->queue->head->next = NULL;
}

static void		add_path(t_map *map, t_bfs *bfs, int *used_rooms, t_path *new)
{
	t_path		*cur;
	int			i;
	int			cur_idx;

	cur = map->pathes;
	if (!cur)
		map->pathes = new;
	else
	{
		while (cur->next)
			cur = cur->next;
		cur->next = new;
	}
	i = new->length;
	cur_idx = map->end->idx;
	while (bfs->pred[cur_idx])
	{
		new->vertixes[--i] = get_rooms_name(cur_idx, map);
		if (cur_idx != map->end->idx)
			used_rooms[cur_idx] = 1;
		cur_idx = bfs->pred[cur_idx]->idx;
	}
}

static int		bfs(t_map *map, int *used_rooms)
{
	t_bfs		bfs;
	t_path		*new;
	t_room		*cur;

	initialize_bfs(&bfs, map, used_rooms);
	while (bfs.queue->head)
	{
		cur = queue_popfront(bfs.queue);
		if (work_with_vertix(cur, &bfs, map))
		{
			new = (t_path*)malloc(sizeof(t_path));
			new->ants = NULL;
			new->length = bfs.dist[map->end->idx];
			new->next = NULL;
			new->vertixes = (char**)malloc(sizeof(char*) * (new->length + 1));
			new->vertixes[new->length] = NULL;
			add_path(map, &bfs, used_rooms, new);
			delete_bfs(&bfs);
			return (1);
		}
	}
	delete_bfs(&bfs);
	return (0);
}

int				get_pathes(t_map *map)
{
	int		*used_rooms;
	int		i;

	used_rooms = (int*)malloc(sizeof(int) * map->rooms_count);
	i = -1;
	while (++i < map->rooms_count)
		used_rooms[i] = 0;
	while (bfs(map, used_rooms))
		;
	free(used_rooms);
	if (!map->pathes)
	{
		ft_putendl("ERROR: Start and end are not connected!");
		return (0);
	}
	return (1);
}
