/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proceed_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoroziu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 11:14:38 by amoroziu          #+#    #+#             */
/*   Updated: 2019/01/10 12:27:01 by amoroziu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static int	get_edge(t_map *map, char *room, char *command)
{
	add_to_input(map, room);
	if (ft_strequ(command, "##start"))
	{
		if (!(map->start = get_room(room, map)))
			return (0);
	}
	else if (!(map->end = get_room(room, map)))
		return (0);
	return (1);
}

static int	execute_command(char *line, t_map *map)
{
	int		temp;
	char	*room;

	if (!ft_strequ(line, "##start") && !ft_strequ(line, "##end"))
		return (1);
	if ((ft_strequ(line, "##start") && map->start) ||
		(ft_strequ(line, "##end") && map->end))
	{
		ft_putendl("ERROR: Duplicate start or end!");
		return (0);
	}
	temp = get_next_line(0, &room);
	if (temp == 0)
	{
		ft_putendl("ERROR: No room given after command!");
		return (0);
	}
	if (temp == -1)
	{
		perror("ERROR");
		return (0);
	}
	if (!get_edge(map, room, line))
		return (0);
	return (1);
}

int			proceed_line(char *line, t_map *map)
{
	if (line[0] == '#' && line[1] != '#')
		return (1);
	if (line[0] == '#')
	{
		if (!execute_command(line, map))
			return (0);
	}
	else if ((ft_strchr(line, ' ') && ft_strchr(line, '-')) ||
			(!ft_strchr(line, ' ') && !ft_strchr(line, '-')))
	{
		ft_putendl("ERROR: Incorrect format!");
		return (0);
	}
	else if (ft_strchr(line, ' '))
	{
		if (map->links || !get_room(line, map))
			return (0);
	}
	else if (!get_link(line, map) || no_start_or_end(map))
		return (0);
	return (1);
}
