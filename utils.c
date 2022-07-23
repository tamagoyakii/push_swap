/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyukim <jihyukim@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 15:40:20 by jihyukim          #+#    #+#             */
/*   Updated: 2022/07/23 16:07:55 by jihyukim         ###   ########.fr       */
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

void	init_dq(t_dq *dq)
{
	dq->head = 0;
	dq->tail = 0;
	dq->size = 0;
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
