/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyukim <jihyukim@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 14:15:19 by jihyukim          #+#    #+#             */
/*   Updated: 2022/07/25 16:57:04 by jihyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_dq *a, t_dq *b)
{
	if (a->size == 2)
	{
		operate_and_print(S, "a\n", 0, a);
	}
	else if (a->size <= 5)
		under_five(a, b);
	else
	{
		atob(a, b);
		btoa(a, b);
	}
}

void	set_index(t_dq *a)
{
	t_node	*i;
	t_node	*j;

	i = a->head;
	while (i)
	{
		j = i->next;
		while (j)
		{
			if (i->content > j->content)
				i->idx += 1;
			else if (i->content < j->content)
				j->idx += 1;
			else
				error_exit("Error\n");
			j = j->next;
		}
		i = i->next;
	}
}

int	is_sorted(t_dq *a)
{
	t_node	*i;
	t_node	*j;

	i = a->head;
	while (i->next)
	{
		j = i->next;
		if (i->content > j->content)
			return (0);
		i = i->next;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	t_dq	a;
	t_dq	b;

	if (argc < 2)
		return (0);
	init_dq(&a);
	init_dq(&b);
	parsing(argv, &a);
	if (!is_sorted(&a))
	{
		set_index(&a);
		push_swap(&a, &b);
	}
	free_node(&a);
	free_node(&b);
	return (0);
}
