/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   add_ant.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoroziu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 15:19:10 by amoroziu          #+#    #+#             */
/*   Updated: 2018/12/29 14:02:55 by amoroziu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

static t_ant	*create_ant(int ant_idx)
{
	t_ant	*new;

	new = (t_ant*)malloc(sizeof(t_ant));
	new->pos = 0;
	new->idx = ant_idx;
	new->next = NULL;
	return (new);
}

void	add_ant(t_path *path, int ant_idx)
{
	t_ant	*new;
	t_ant	*cur;

	new = create_ant(ant_idx);
	if (!path->ants)
		path->ants = new;
	else
	{
		cur = path->ants;
		while (cur)
			cur = cur->next;
		cur->next = new;
	}
}
