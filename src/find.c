/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoroziu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 11:04:14 by amoroziu          #+#    #+#             */
/*   Updated: 2019/01/08 14:34:56 by amoroziu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

char	*get_rooms_name(int rooms_idx, t_map *map)
{
	int		i;
	t_room	*cur;

	cur = map->rooms;
	i = -1;
	while (++i < rooms_idx)
		cur = cur->next;
	return (ft_strdup(cur->name));
}

int		get_rooms_idx(t_room *room, t_map *map)
{
	int		i;
	t_room	*cur;

	i = -1;
	cur = map->rooms;
	while (++i < map->rooms_count)
	{
		if (cur == room)
			break ;
		cur = cur->next;
	}
	return (i);
}
