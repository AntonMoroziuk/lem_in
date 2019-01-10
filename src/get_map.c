/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoroziu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 10:53:51 by amoroziu          #+#    #+#             */
/*   Updated: 2019/01/10 12:26:34 by amoroziu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void		add_to_input(t_map *map, char *str)
{
	t_input		*new;
	t_input		*cur;

	new = (t_input*)malloc(sizeof(t_input));
	new->line = str;
	new->next = NULL;
	if (!map->input)
		map->input = new;
	else
	{
		cur = map->input;
		while (cur->next)
			cur = cur->next;
		cur->next = new;
	}
}

static int	get_ants_number(t_map *map, char *line)
{
	int		res;

	add_to_input(map, line);
	while (line[0] == '#' && !ft_strequ(line, "##start") &&
			!ft_strequ(line, "##end"))
	{
		get_next_line(0, &line);
		add_to_input(map, line);
	}
	res = 0;
	while (*line)
	{
		if (!ft_isdigit(*line))
			return (0);
		res = res * 10 + *line - '0';
		line++;
	}
	if (res <= 0)
		return (0);
	map->ants_count = res;
	return (1);
}

int			get_map(t_map *map)
{
	char	*line;

	if (get_next_line(0, &line) <= 0)
	{
		ft_putendl("ERROR: problem with file!");
		return (0);
	}
	if (!get_ants_number(map, line))
	{
		ft_putendl("ERROR: Ants number is incorrect or missing!");
		return (0);
	}
	while (get_next_line(0, &line) > 0)
	{
		add_to_input(map, line);
		if (!proceed_line(line, map))
			return (0);
	}
	if (get_next_line(0, &line) == -1)
		perror("ERROR");
	return (1);
}
