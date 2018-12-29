/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoroziu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/18 11:04:14 by amoroziu          #+#    #+#             */
/*   Updated: 2018/12/29 13:38:54 by amoroziu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

int		get_rooms_idx(char *name, t_map *map)
{
	int		i;

	i = -1;
	while (++i < map->rooms_count)
		if (ft_strequ(name, map->rooms_array[i]))
			break ;
	return (i);
}
