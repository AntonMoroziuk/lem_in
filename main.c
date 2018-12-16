/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoroziu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 10:22:16 by amoroziu          #+#    #+#             */
/*   Updated: 2018/12/16 13:40:07 by amoroziu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static void	print_map(t_map *map)
{
	t_room	*cur;
	t_link	*link;

	ft_printf("%d\n", map->ants_count);
	cur = map->rooms;
	while (cur)
	{
		if (cur == map->start)
			ft_putendl("##start");
		else if (cur == map->end)
			ft_putendl("##end");
		ft_printf("%s %d %d\n", cur->name, cur->x, cur->y);
		cur = cur->next;
	}
	link = map->links;
	while (link)
	{
		ft_printf("%s-%s\n", link->first, link->second);
		link = link->next;
	}
}

static void	free_map(t_map *map)
{
	int		i;

	if (map->rooms_array)
		ft_strdel(&map->rooms_array);
	delete_rooms(map->rooms);
	delete_room(map->start);
	delete_room(map->end);
	delete_links(map->links);
	i = -1;
	while (++i < map->rooms_count)
		free(map->matrix[i]);
	if (map->matrix)
		free(map->matrix);
}

static void	initialize(t_map *map)
{
	map->rooms_count = 0;
	map->ants_count = 0;
	map->rooms_array = NULL;
	map->matrix = NULL;
	map->rooms = NULL;
	map->start = NULL;
	map->end = NULL;
	map->links = NULL;
}

int			main(void)
{
	t_map	map;

	initialize(&map);
	if (!get_map(&map))
	{
		free_map(&map);
		return (0);
	}
	//work_with_map(&map);
	//if (!get_pathes(&map))
//		return (0);
	print_map(&map);
	ft_putchar('\n');
//	print_answer(&map);
//	free_map(&map);
	return (0);
}
