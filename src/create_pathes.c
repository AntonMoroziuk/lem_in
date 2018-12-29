/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_pathes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoroziu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 13:38:41 by amoroziu          #+#    #+#             */
/*   Updated: 2018/12/29 13:10:56 by amoroziu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static t_path	*new_path(t_room *room)
{
	t_path	*path;

	path = (t_path*)malloc(sizeof(t_path));
	path->length = room->dist_to_end;
	path->vertixes = (char**)malloc(sizeof(char*) * path->length);
	path->vertixes[0] = ft_strdup(room->name);
	path->next = NULL;
	return (path);
}

static void		add_path(t_room *room, t_map *map)
{
	t_path	*path;
	t_node	*cur;
	int		i;

	path = new_path(room);
	i = 0;
	cur = room->adj;
	while (++i < path->length)
	{
		if (cur->room->dist_to_end < cur->next->room->dist_to_end)
		{
			path->vertixes[i] = ft_strdup(cur->room->name);
			cur = cur->room->adj;
		}
		else
		{
			path->vertixes[i] = ft_strdup(cur->next->room->name);
			cur = cur->next->room->adj;
		}
	}
	path->next = map->pathes;
	map->pathes = path;
}

static void		sort_arr(t_room **arr)
{
	int		i;
	int		counter;
	t_room	*temp;

	counter = 1;
	while (counter)
	{
		i = -1;
		counter = 0;
		while (arr[++i + 1])
			if (arr[i]->dist_to_end < arr[i + 1]->dist_to_end)
			{
				temp = arr[i];
				arr[i] = arr[i + 1];
				arr[i + 1] = temp;
				counter++;
			}
	}
}

void			create_pathes(t_map *map)
{
	int		i;
	t_room	**arr;
	t_node	*cur;

	arr = (t_room**)malloc(sizeof(t_room*) * map->start->outputs + 1);
	i = -1;
	cur = map->start->adj;
	while (cur)
	{
		arr[++i] = cur->room;
		cur = cur->next;
	}
	arr[++i] = NULL;
	sort_arr(arr);
	i = -1;
	while (arr[++i])
		add_path(arr[i], map);
}
