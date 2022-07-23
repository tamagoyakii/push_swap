/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyukim <jihyukim@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 12:59:06 by jihyukim          #+#    #+#             */
/*   Updated: 2022/07/23 16:35:00 by jihyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	operate_and_print(int op, char *c, t_dq *dst, t_dq *src)
{
	if (op == S)
	{
		swap(src);
		write(1, "s", 1);
	}
	else if (op == P)
	{
		push(dst, src);
		write(1, "p", 1);
	}
	else if (op == R)
	{
		rotate(src);
		write(1, "r", 1);
	}
	else if (op == RR)
	{
		reverse_rotate(src);
		write(1, "rr", 2);
	}
	write(1, c, 2);
}

void	swap(t_dq *dq)
{
	t_node	*tmp1;
	t_node	*tmp2;

	tmp1 = dq->head;
	tmp2 = tmp1->next;
	dq->head = tmp2;
	tmp1->prev = tmp2;
	tmp1->next = tmp2->next;
	tmp2->prev = 0;
	tmp2->next = tmp1;
}

void	push(t_dq *dst, t_dq *src)
{
	t_node	*tmp;

	if (src->size == 0)
		return ;
	else
	{
		tmp = src->head;
		src->head = tmp->next;
		if (src->head)
			src->head->prev = 0;
		else
			src->tail = 0;
		tmp->prev = 0;
		tmp->next = dst->head;
		if (dst->head)
			dst->head->prev = tmp;
		else
			dst->tail = tmp;
		dst->head = tmp;
		dst->size += 1;
		src->size -= 1;
	}
}

void	rotate(t_dq *dq)
{
	t_node	*tmp;

	if (dq->size < 2)
		return ;
	tmp = dq->head;
	dq->head = tmp->next;
	dq->head->prev = 0;
	dq->tail->next = tmp;
	tmp->prev = dq->tail;
	tmp->next = 0;
	dq->tail = tmp;
}

void	reverse_rotate(t_dq *dq)
{
	t_node	*tmp;

	if (dq->size < 2)
		return ;
	tmp = dq->tail;
	dq->tail = tmp->prev;
	dq->tail->next = 0;
	dq->head->prev = tmp;
	tmp->prev = 0;
	tmp->next = dq->head;
	dq->head = tmp;
}