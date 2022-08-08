/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operation_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyukim <jihyukim@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 17:09:38 by jihyukim          #+#    #+#             */
/*   Updated: 2022/08/08 18:48:40 by jihyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	operate_bonus(int op, t_dq *dst, t_dq *src)
{
	if (op == S)
		swap(src);
	else if (op == P)
		push(dst, src);
	else if (op == R)
		rotate(src);
	else if (op == RR)
		reverse_rotate(src);
	else if (op == B_SS)
	{
		swap(dst);
		swap(src);
	}
	else if (op == B_RR)
	{
		rotate(dst);
		rotate(src);
	}
	else if (op == B_RRR)
	{
		reverse_rotate(dst);
		reverse_rotate(src);
	}
}

void	swap(t_dq *dq)
{
	int	tmp_con;
	int	tmp_idx;

	if (dq->size < 2)
		return ;
	tmp_con = dq->head->content;
	tmp_idx = dq->head->idx;
	dq->head->content = dq->head->next->content;
	dq->head->idx = dq->head->next->idx;
	dq->head->next->content = tmp_con;
	dq->head->next->idx = tmp_idx;
}

void	push(t_dq *dst, t_dq *src)
{
	t_node	*tmp;

	if (src->size == 0)
		return ;
	else
	{
		tmp = src->head;
		src->head = src->head->next;
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
