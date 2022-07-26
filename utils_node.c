/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_node.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyukim <jihyukim@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 16:03:04 by jihyukim          #+#    #+#             */
/*   Updated: 2022/07/26 22:05:17 by jihyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	init_dq(t_dq *dq)
{
	dq->head = 0;
	dq->tail = 0;
	dq->size = 0;
}

void	add_node(t_dq *a, int num)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	node->content = num;
	node->idx = 0;
	if (a->size == 0)
	{
		node->prev = 0;
		node->next = 0;
		a->head = node;
		a->tail = node;
	}
	else
	{
		node->prev = a->tail;
		node->next = 0;
		a->tail->next = node;
		a->tail = node;
	}
	a->size++;
}

void	free_node(t_dq *dq)
{
	t_node	*tmp;

	dq->tail = 0;
	dq->size = 0;
	while (dq->head)
	{
		tmp = dq->head;
		dq->head = dq->head->next;
		free(tmp);
	}
}
