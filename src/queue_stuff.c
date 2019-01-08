/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_stuff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoroziu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 12:31:35 by amoroziu          #+#    #+#             */
/*   Updated: 2019/01/08 14:32:32 by amoroziu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

void	queue_pushback(t_link *link, t_room *pred, t_queue *queue)
{
	t_node	*new;

	new = (t_node*)malloc(sizeof(t_node));
	new->next = NULL;
	if (link->first == pred)
		new->room = link->second;
	else
		new->room = link->first;
	if (!queue->head)
	{
		queue->head = new;
		queue->tail = new;
	}
	else
	{
		queue->tail->next = new;
		queue->tail = new;
	}
}

t_room	*queue_popfront(t_queue *queue)
{
	t_node	*temp;
	t_room	*room;

	temp = queue->head;
	if (queue->head == queue->tail)
		queue->tail = NULL;
	queue->head = temp->next;
	room = temp->room;
	free(temp);
	return (room);
}
