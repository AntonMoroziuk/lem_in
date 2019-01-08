/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoroziu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 10:47:20 by amoroziu          #+#    #+#             */
/*   Updated: 2019/01/08 14:35:10 by amoroziu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	delete_bfs(t_bfs *bfs)
{
	t_node	*temp;
	t_node	*to_del;

	free(bfs->visited);
	free(bfs->dist);
	free(bfs->pred);
	to_del = bfs->queue->head;
	while (to_del)
	{
		temp = to_del->next;
		free(to_del);
		to_del = temp;
	}
	free(bfs->queue);
}

void	delete_room(t_room *room)
{
	if (room->name)
		ft_strdel(&room->name);
	free(room);
}

void	delete_rooms(t_room *head)
{
	t_room	*temp;
	t_room	*room;

	room = head;
	while (room)
	{
		temp = room->next;
		delete_room(room);
		room = temp;
	}
}

void	delete_links(t_link *head)
{
	t_link	*temp;

	temp = head;
	while (temp)
	{
		temp = temp->next;
		free(head);
		head = temp;
	}
}

void	delete_pathes(t_path *head)
{
	t_path	*temp;

	temp = head;
	while (temp)
	{
		head = temp->next;
		arrdel(temp->vertixes);
		free(temp);
		temp = head;
	}
}
