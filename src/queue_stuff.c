/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   queue_stuff.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: amoroziu <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 12:31:35 by amoroziu          #+#    #+#             */
/*   Updated: 2018/12/29 14:02:55 by amoroziu         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/lem_in.h"

t_node	*initialize_queue(t_queue *queue, t_map *map)
{
	t_node			*node;
	t_queue_node	*first;

	node = (t_node*)malloc(sizeof(t_node));
	node->room = map->start;
	node->next = NULL;
	first = (t_queue_node*)malloc(sizeof(t_queue_node));
	first->node = node;
	first->next = NULL;
	queue->head = first;
	queue->tail = first;
	return (node);
}

void	queue_pushback(t_node *node, t_queue *queue)
{
	t_queue_node	*new;

	new = (t_queue_node*)malloc(sizeof(t_queue_node));
	new->next = NULL;
	new->node = node;
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

t_node	*queue_popfront(t_queue *queue)
{
	t_queue_node	*temp;
	t_node			*node;

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
	node = temp->node;
	free(temp);
	return (node);
}
