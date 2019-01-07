/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoroziu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 10:22:16 by amoroziu          #+#    #+#             */
/*   Updated: 2018/12/29 15:49:05 by amoroziu         ###   ########.fr       */
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
	if (map->rooms_array)
		arrdel(map->rooms_array);
}

static void	initialize(t_map *map)
{
	map->rooms_count = 0;
	map->ants_count = 0;
	map->rooms_array = NULL;
	map->rooms = NULL;
	map->start = NULL;
	map->end = NULL;
	map->links = NULL;
	map->input = NULL;
	map->pathes = NULL;
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
	work_with_map(&map);
	if (!get_pathes(&map))
		return (0);
	format_output(argc, argv, &map);
	free_map(&map);
	return (0);
}
