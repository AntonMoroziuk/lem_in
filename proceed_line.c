/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   proceed_line.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoroziu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 11:14:38 by amoroziu          #+#    #+#             */
/*   Updated: 2018/12/16 13:42:46 by amoroziu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

static int	get_edge(t_map *map, char *room, char *command)
{
	if (ft_strequ(command, "##start"))
	{
		if (!(map->start = get_room(room, map)))
			return (0);
	}
	else
		if (!(map->end = get_room(room, map)))
			return (0);
	return (1);
}

static int	execute_command(char *line, t_map *map)
{
	int		temp;
	char	*room;

	if (!ft_strequ(line, "##start") && !ft_strequ(line, "##end"))
		return (1);
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

static void	add_link(t_map *map, t_link *link)
{
	t_link	*cur;

	if (!map->links)
		map->links = link;
	else
	{
		cur = map->links;
		while (cur->next)
			cur = cur->next;
		cur->next = link;
	}
}

static int	get_link(char *str, t_map *map)
{
	int		i;
	t_link	*new;

	i = -1;
	new = (t_link*)malloc(sizeof(t_link));
	if (!new)
		return (0);
	new->next = NULL;
	new->first = NULL;
	new->second = NULL;
	while (str[++i] && str[i] != '-')
		;
	if (!str[i])
		return (0);
	new->first = ft_strsub(str, 0, i);
	while (str[++i] && str[i] != '-')
		;
	if (str[i])
		return (0);
	new->second = ft_strsub(ft_strchr(str, '-'), 1, ft_strlen(ft_strchr(str, '-')));
	if (incorrect_link(map, new))
		return (0);
	add_link(map, new);
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
	else if (ft_strchr(line, ' '))
	{
		if (map->links || !get_room(line, map))
			return (0);
	}
	else
		if (!get_link(line, map))
			return (0);
	return (1);
}
