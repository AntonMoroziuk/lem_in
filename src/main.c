/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoroziu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 10:22:16 by amoroziu          #+#    #+#             */
/*   Updated: 2019/01/08 15:31:07 by amoroziu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

int			no_start_or_end(t_map *map)
{
	if (!map->start)
	{
		ft_putendl("ERROR: No start given!");
		return (1);
	}
	if (!map->end)
	{
		ft_putendl("ERROR: No end given!");
		return (1);
	}
	return (0);
}

static void	free_map(t_map *map)
{
	t_input	*input;

	input = map->input;
	while (input)
	{
		map->input = input->next;
		ft_strdel(&input->line);
		free(input);
		input = map->input;
	}
	delete_rooms(map->rooms);
	delete_links(map->links);
	delete_pathes(map->pathes);
}

static void	initialize(t_map *map)
{
	map->rooms_count = 0;
	map->ants_count = 0;
	map->rooms = NULL;
	map->start = NULL;
	map->end = NULL;
	map->links = NULL;
	map->input = NULL;
	map->pathes = NULL;
}

static int	simple(t_map *map)
{
	t_link	*cur;
	t_path	*new;

	cur = map->links;
	while (cur)
	{
		if ((cur->first == map->start && cur->second == map->end) ||
			(cur->first == map->end && cur->second == map->start))
		{
			new = (t_path*)malloc(sizeof(t_path));
			new->length = 1;
			new->ants = NULL;
			new->next = NULL;
			new->vertixes = (char**)malloc(sizeof(char*) * 2);
			new->vertixes[1] = NULL;
			new->vertixes[0] = ft_strdup(map->end->name);
			map->pathes = new;
			return (1);
		}
		cur = cur->next;
	}
	return (0);
}

int			main(int argc, char **argv)
{
	t_map	map;

	initialize(&map);
	if (!get_map(&map))
	{
		free_map(&map);
		return (0);
	}
	if (no_start_or_end(&map))
		return (0);
	if (simple(&map))
		;
	else if (!get_pathes(&map))
		return (0);
	format_output(argc, argv, &map);
	free_map(&map);
	return (0);
}
