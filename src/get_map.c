/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_map.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoroziu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 10:53:51 by amoroziu          #+#    #+#             */
/*   Updated: 2018/12/24 15:43:00 by amoroziu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void		add_to_arr(char **arr, char *str)
{
	int		i;
	char	**new;

	if (!arr)
	{
		arr = (char**)malloc(sizeof(char*) * 2);
		arr[0] = str;
		arr[1] = NULL;
		return ;
	}
	i = -1;
	while (arr[++i])
		;
	new = (char**)malloc(sizeof(char*) * (i + 1));
	i = -1;
	while (arr[++i])
		new[i] = arr[i];
	new[i] = str;
	new[i + 1] = NULL;
	arrdel(arr);
	arr = new;
}

static int	get_ants_number(t_map *map)
{
	int		res;
	char	*line;

	if (get_next_line(0, &line) > 0)
	{
		res = 0;
		while (*line)
		{
			if (!ft_isdigit(*line))
				return (0);
			res = res * 10 + *line - '0';
			line++;
		}
		if (res< 0)
			return (0);
		map->ants_count = res;
		return (1);
	}
	return (0);
}

int			get_map(t_map *map)
{
	char	*line;

	if (!get_ants_number(map))
	{
		ft_putendl("ERROR: Ants number is incorrect or missing!");
		return (0);
	}
	while (get_next_line(0, &line) > 0)
	{
		if (!proceed_line(line, map))
			return (0);
		add_to_arr(map->input, line);
	}
	if (get_next_line(1, &line) == -1)
		perror("ERROR");
//	if (!correct_map(map))
//	{
//		show_error(map);
//		return (0);
//	}
	return (1);
}
