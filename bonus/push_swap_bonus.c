/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyukim <jihyukim@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 15:32:43 by jihyukim          #+#    #+#             */
/*   Updated: 2022/08/10 16:49:57 by jihyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_bonus.h"

void	push_swap_bonus(char *op, t_dq *a, t_dq *b)
{
	if (ft_strncmp(op, "pa\n", 3) == 0)
		operate_bonus(P, a, b);
	else if (ft_strncmp(op, "pb\n", 3) == 0)
		operate_bonus(P, b, a);
	else if (ft_strncmp(op, "sa\n", 3) == 0)
		operate_bonus(S, 0, a);
	else if (ft_strncmp(op, "sb\n", 3) == 0)
		operate_bonus(S, 0, b);
	else if (ft_strncmp(op, "ss\n", 3) == 0)
		operate_bonus(B_SS, a, b);
	else if (ft_strncmp(op, "ra\n", 3) == 0)
		operate_bonus(R, 0, a);
	else if (ft_strncmp(op, "rb\n", 3) == 0)
		operate_bonus(R, 0, b);
	else if (ft_strncmp(op, "rr\n", 3) == 0)
		operate_bonus(B_RR, a, b);
	else if (ft_strncmp(op, "rra\n", 4) == 0)
		operate_bonus(RR, 0, a);
	else if (ft_strncmp(op, "rrb\n", 4) == 0)
		operate_bonus(RR, 0, b);
	else if (ft_strncmp(op, "rrr\n", 4) == 0)
		operate_bonus(B_RRR, a, b);
	else
		error_exit("");
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
	check_op(&a, &b);
	check_sort(&a, &b);
	return (0);
}
