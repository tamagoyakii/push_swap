/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyukim <jihyukim@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 15:40:20 by jihyukim          #+#    #+#             */
/*   Updated: 2022/07/31 14:13:21 by jihyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	error_exit(char *str)
{
	ft_putstr_fd(str, 1);
	exit(1);
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

int	ft_atol(const char *str)
{
	int			sign;
	long long	ret;

	sign = 1;
	ret = 0;
	while ((*str >= 9 && *str <= 13) || *str == 32)
		str++;
	if (*str && ((*str == '-') || (*str == '+')))
	{
		if (*str == '-')
			sign *= -1;
		str++;
	}
	while (*str && *str >= 48 && *str <= 57)
	{
		ret = ret * 10 + (*str - 48);
		if (ret * sign > 2147483647)
			error_exit("Error\n");
		else if (ret * sign < -2147483648)
			error_exit("Error\n");
		str++;
	}
	return (ret * sign);
}
