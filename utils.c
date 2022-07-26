/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyukim <jihyukim@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 15:40:20 by jihyukim          #+#    #+#             */
/*   Updated: 2022/07/26 22:05:57 by jihyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(char *str)
{
	ft_putstr_fd(str, 1);
	exit(1);
}

int	cal_chunk(int x)
{
	return (0.000000053 * x * x + 0.03 * x + 14.5);
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

void	check_digit(char *str)
{
	int	i;

	i = -1;
	while (str[++i])
	{
		if (!ft_isdigit(str[i]) && str[i] != '-' && str[i] != '+')
			error_exit("Error\n");
		if ((str[i] == '-' || str[i] == '+') && !ft_isdigit(str[i + 1]))
			error_exit("Error\n");
		if ((str[i] == '-' || str[i] == '+') && i != 0)
			error_exit("Error\n");
	}
}

void	free_arr(char **arr)
{
	int	i;

	i = -1;
	while (arr[++i])
	{
		free(arr[i]);
		arr[i] = 0;
	}
	free(arr);
	arr = 0;
}
