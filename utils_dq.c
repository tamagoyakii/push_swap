/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_dq.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyukim <jihyukim@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 16:38:54 by jihyukim          #+#    #+#             */
/*   Updated: 2022/07/22 16:52:05 by jihyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	add_list(t_dq *a, int num)
{
	t_node	*node;

	node = malloc(sizeof(t_node));
	node->content = num;
	node->idx = 0;
	if (a->size == 0)
	{
		a->head = node;
		a->tail = node;
	}
	else
	{
		node->prev = a->tail;
		node->next = NULL;
		a->tail->next = node;
		a->tail = node;
	}
	a->size++;
}