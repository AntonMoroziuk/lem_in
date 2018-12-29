/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_stuff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoroziu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 12:31:35 by amoroziu          #+#    #+#             */
/*   Updated: 2018/12/29 13:16:31 by amoroziu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "lem_in.h"

void	queue_pushback(t_node *node, t_queue *queue)
{
	if (!queue->head)
	{
		queue->head = node;
		queue->tail = node;
	}
	else
	{
		queue->tail->next = node;
		queue->tail = node;
	}
}

t_node	*queue_popfront(t_queue *queue)
{
	t_node	*temp;

	temp = queue->head;
	if (queue->tail == queue->head)
	{
		queue->tail = NULL;
		queue->head = NULL;
	}
	else
	{
		queue->head = temp->next;
		temp->next = NULL;
	}
	return (temp);
}
