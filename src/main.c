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

/*static void	print_map(t_map *map)
{
	int		i;

	i = -1;
	while (map->input[++i])
		ft_printf("%s\n", map->input[i]);
}
*/
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

/*static void	free_map(t_map *map)
{
	int		i;

	delete_rooms(map->rooms);
	delete_room(map->start);
	delete_room(map->end);
	delete_links(map->links);
	i = -1;
	while (++i < map->rooms_count)
		free(map->matrix[i]);
	if (map->matrix)
		free(map->matrix);
	i = -1;
	while (map->input[++i])
		free(map->input[i]);
	free(map->input);
}
*/
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
	map->input = NULL;
}

int			main(void)
{
	t_map	map;

	initialize(&map);
	if (!get_map(&map))
	{
	//	free_map(&map);
		return (0);
	}
	if (no_start_or_end(&map))
		return (0);
	work_with_map(&map);
	if (!get_pathes(&map))
		return (0);
//	print_map(&map);
	ft_putchar('\n');
	print_answer(&map);
//	free_map(&map);
	return (0);
}
