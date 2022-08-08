/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyukim <jihyukim@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 17:25:02 by jihyukim          #+#    #+#             */
/*   Updated: 2022/08/08 18:39:55 by jihyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "push_swap_bonus.h"

void	check_op(t_dq *a, t_dq *b)
{
	char	*op;

	while (1)
	{
		op = get_next_line(0);
		if (op == NULL)
			break;
		push_swap_bonus(op, a, b);
		free(op);
		op = 0;
	}
}

void	check_sort(t_dq *a, t_dq *b)
{
	if (is_sorted(a) && b->size == 0)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
	free_node(a);
}
