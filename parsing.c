/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyukim <jihyukim@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 15:43:20 by jihyukim          #+#    #+#             */
/*   Updated: 2022/07/22 17:50:17 by jihyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	check_digit(char *str)
{
	int	i;

	i = -1;
	while(str[++i])
	{
		if (!ft_isdigit(str[i]) && str[i] != '-' && str[i] != '+')
			error_exit("Error\n");
		if ((str[i] == '-' || str[i] == '+') && !ft_isdigit(str[i + 1]))
			error_exit("Error\n");
		if ((str[i] == '-' || str[i] == '+') && i != 0)
			error_exit("Error\n");
	}
}

void	parsing(char **argv, t_dq *a)
{
	long long	num;
	char		**arr;
	int			i;
	int			j;

	i = 0;
	while (argv[++i])
	{
		arr = ft_split(argv[i], ' ');
		j = -1;
		while (arr[++j])
		{
			check_digit(arr[j]);
			num = ft_atoi(arr[j]);
			add_list(a, num);
		}
		free_arr(arr);
	}
}