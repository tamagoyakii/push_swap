/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyukim <jihyukim@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/22 14:58:55 by jihyukim          #+#    #+#             */
/*   Updated: 2022/07/22 16:53:03 by jihyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "./libft/libft.h"

# define PA 0
# define PB 1
# define RA 2
# define RB 3
# define SA 4
# define SB 5
# define RRA 6
# define RRB 7

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

void	free_arr(char **arr);
void	init_dq(t_dq *dq);
void	error_exit(char *str);

void	add_list(t_dq *a, int num);

void	parsing(char **argv, t_dq *a);
void	check_digit(char *str);



#endif