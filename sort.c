/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyukim <jihyukim@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 14:35:23 by jihyukim          #+#    #+#             */
/*   Updated: 2022/07/26 22:08:29 by jihyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	get_max_pos(t_dq *b, int max_idx)
{
	int		pos;
	t_node	*node;

	pos = 1;
	node = b->head;
	while (node->idx != max_idx)
	{
		pos++;
		node = node->next;
	}
	return (pos);
}

void	under_five(t_dq *a, t_dq *b)
{
	int	min_idx;

	min_idx = a->size - 3;
	while (a->size > 3)
	{	
		if (a->head->idx < min_idx)
			operate_and_print(P, "b\n", b, a);
		else
			operate_and_print(R, "a\n", 0, a);
	}
	while (!is_sorted(a))
	{
		if (a->head->idx > a->tail->idx)
			operate_and_print(R, "a\n", 0, a);
		else if (a->head->idx > a->head->next->idx)
			operate_and_print(S, "a\n", 0, a);
		else
			operate_and_print(RR, "a\n", 0, a);
	}
	while (b->size)
		operate_and_print(P, "a\n", a, b);
	if (a->head->idx != 0)
		operate_and_print(S, "a\n", 0, a);
}

void	atob(t_dq *a, t_dq *b)
{
	int		chunk;
	int		num;
	t_node	*node;

	num = 0;
	chunk = cal_chunk(a->size);
	while (a->size != 0)
	{
		node = a->head;
		if (node->idx <= num)
		{
			operate_and_print(P, "b\n", b, a);
			num++;
		}
		else if (node->idx <= num + chunk)
		{
			operate_and_print(P, "b\n", b, a);
			operate_and_print(R, "b\n", 0, b);
			num++;
		}
		else if (a->tail->idx <= chunk + num)
			operate_and_print(RR, "a\n", 0, a);
		else
			operate_and_print(R, "a\n", 0, a);
	}
}

void	btoa(t_dq *a, t_dq *b)
{
	int	max_idx;
	int	pos;

	while (b->size != 0)
	{
		max_idx = b->size - 1;
		pos = get_max_pos(b, max_idx);
		if (pos <= b->size / 2)
		{
			while (b->head->idx != max_idx)
				operate_and_print(R, "b\n", 0, b);
		}
		else
		{
			while (b->head->idx != max_idx)
				operate_and_print(RR, "b\n", 0, b);
		}
		operate_and_print(P, "a\n", a, b);
	}
}
