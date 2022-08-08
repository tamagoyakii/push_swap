/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_bonus.h                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jihyukim <jihyukim@student.42.kr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 15:33:01 by jihyukim          #+#    #+#             */
/*   Updated: 2022/08/08 17:32:31 by jihyukim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_BONUS_H
# define PUSH_SWAP_BONUS_H

# include "../libft/libft.h"

# define READ_EOF 0
# define READ_SUCCESS 1

# define S 2
# define P 3
# define R 4
# define RR 5
# define B_SS 6
# define B_RR 7
# define B_RRR 8

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

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

char	*gnl_strchr(const char *s, int c);
char	*gnl_strjoin(char const *s1, char const *s2);
char	*split_line(char **storage);
char	*read_last(char	**storage);
char	*get_next_line(int fd);

void	check_op(t_dq *a, t_dq *b);
void	check_sort(t_dq *a, t_dq *b);

void	operate_bonus(int op, t_dq *dst, t_dq *src);
void	swap(t_dq *dq);
void	push(t_dq *dst, t_dq *src);
void	rotate(t_dq *dq);
void	reverse_rotate(t_dq *dq);

void	error_exit(char *str);
int		is_sorted(t_dq *a);
void	check_digit(char *str);
void	free_arr(char **arr);
int		ft_atol(const char *str);

void	init_dq(t_dq *dq);
void	add_node(t_dq *a, int num);
void	free_node(t_dq *dq);

void	push_swap_bonus(char *op, t_dq *a, t_dq *b);
void	parsing(char **argv, t_dq *a);

#endif
