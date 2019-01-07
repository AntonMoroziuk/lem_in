/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoroziu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/15 10:47:20 by amoroziu          #+#    #+#             */
/*   Updated: 2018/12/29 14:02:55 by amoroziu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	delete_room(t_room *room)
{
	t_node	*node;
	t_node	*temp;

	if (room->name)
		ft_strdel(&room->name);
	if (room->adj)
	{
		node = room->adj;
		while (node)
		{
			temp = node->next;
			free(node);
			node = temp;
		}
	}
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
		ft_strdel(&head->first);
		ft_strdel(&head->second);
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