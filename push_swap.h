/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyukim <jihyukim@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 14:58:55 by jihyukim          #+#    #+#             */
/*   Updated: 2022/07/26 22:11:15 by jihyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"

# define S 1
# define P 2
# define R 3
# define RR 4

typedef struct s_node
{
	struct s_node	*prev;
	struct s_node	*next;
	int				content;
	int				idx;
}				t_node;

typedef struct s_deque
{
	t_node	*head;
	t_node	*tail;
	int		size;
}				t_dq;

void	push_swap(t_dq *a, t_dq *b);
void	set_index(t_dq *a);
void	parsing(char **argv, t_dq *a);

int		get_max_pos(t_dq *b, int max_idx);
void	under_five(t_dq *a, t_dq *b);
void	atob(t_dq *a, t_dq *b);
void	btoa(t_dq *a, t_dq *b);

void	operate_and_print(int op, char *c, t_dq *dst, t_dq *src);
void	swap(t_dq *dq);
void	push(t_dq *dst, t_dq *src);
void	rotate(t_dq *dq);
void	reverse_rotate(t_dq *dq);

void	error_exit(char *str);
int		cal_chunk(int x);
int		is_sorted(t_dq *a);
void	check_digit(char *str);
void	free_arr(char **arr);

void	init_dq(t_dq *dq);
void	add_node(t_dq *a, int num);
void	free_node(t_dq *dq);

#endif