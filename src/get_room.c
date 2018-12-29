/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_room.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoroziu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 11:35:12 by amoroziu          #+#    #+#             */
/*   Updated: 2018/12/29 15:48:42 by amoroziu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static t_room	*new_room()
{
	t_room	*new;

	MALLOCCHECK_NULL((new = (t_room*)malloc(sizeof(t_room))));
	new->name = NULL;
	new->next = NULL;
	new->adj = NULL;
	new->inputs = 0;
	new->outputs = 0;
	new->bfs_level = -1;
	new->dist_to_end = 2147483647;
	return (new);
}

static int		pseudo_atoi(char *str, int *start, int *res)
{
	if (str[*start] == ' ')
		(*start)++;
	if (!ft_isdigit(str[*start]))
	{
		ft_putendl("ERROR: Invalid coordinates!");
		return (0);
	}
	*res = 0;
	while (ft_isdigit(str[*start]))
	{
		*res = *res * 10 + str[*start] - '0';
		(*start)++;
	}
	return (1);
}

t_room			*get_room(char *str, t_map *map)
{
	int		i;
	t_room	*new;

	new = new_room();
	if (!new)
		return (NULL);
	i = -1;
	while (str[++i] && str[i] != ' ')
		;
	new->name = ft_strsub(str, 0, i);
	if (!pseudo_atoi(str, &i, &new->x) || !pseudo_atoi(str, &i, &new->y) ||
		str[i] || incorrect_room(new, map))
	{
		//delete_room(new);
		return (NULL);
	}
	add_room(map, new);
	return (new);
}
