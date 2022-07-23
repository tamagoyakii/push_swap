/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyukim <jihyukim@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/23 14:35:23 by jihyukim          #+#    #+#             */
/*   Updated: 2022/07/23 16:31:54 by jihyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

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
			operate_and_print(P, "b\n", a, b);
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

	while (b->size != 0)
	{
		max_idx = b->size - 1;
		if (is_top(b, max_idx))
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

int	is_top(t_dq *b, int max_idx)
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
	if (pos <= b->size / 2)
		return (1);
	else
		return (0);
}
