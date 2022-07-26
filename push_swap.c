/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyukim <jihyukim@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/21 14:15:19 by jihyukim          #+#    #+#             */
/*   Updated: 2022/08/08 17:27:56 by jihyukim         ###   ########.fr       */
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

void	parsing(char **argv, t_dq *a)
{
	long long	num;
	char		**arr;
	int			i;
	int			j;
	int			n;

	n = 0;
	i = 0;
	while (argv[++i])
	{
		arr = ft_split(argv[i], ' ');
		if (!arr)
			error_exit("");
		j = -1;
		while (arr[++j])
		{
			check_digit(arr[j]);
			num = ft_atol(arr[j]);
			add_node(a, num);
			n++;
		}
		free_arr(arr);
	}
	if (n == 0)
		error_exit("");
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
	set_index(&a);
	if (!is_sorted(&a))
		push_swap(&a, &b);
	free_node(&a);
	return (0);
}
