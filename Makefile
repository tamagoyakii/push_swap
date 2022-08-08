# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jihyukim <jihyukim@student.42.kr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/21 14:15:32 by jihyukim          #+#    #+#              #
#    Updated: 2022/08/08 18:46:40 by jihyukim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

BONUS = checker

CC = cc
CFLAGS = -Wall -Werror -Wextra

SRCS = push_swap.c \
	operation.c \
	sort.c \
	utils.c \
	utils_node.c

SRCS_BONUS = bonus/get_next_line_bonus.c \
			bonus/push_swap_bonus.c \
			bonus/checker_bonus.c \
			bonus/operation_bonus.c \
			bonus/utils_bonus.c \
			bonus/utils_node_bonus.c

OBJS = $(SRCS:.c=.o)

OBJS_BONUS = $(SRCS_BONUS:.c=.o)

all : $(NAME)

bonus : $(BONUS)

$(NAME) : $(OBJS)
	@make re -C libft
	@$(CC) $(CFLAGS) -L ./libft -lft $(OBJS) -o $@

$(BONUS) : $(OBJS_BONUS)
	@make re -C libft
	@$(CC) $(CFLAGS) -L ./libft -lft $(OBJS_BONUS) -o $@

%.o :%.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@make -C libft clean
	@rm -rf $(OBJS) $(OBJS_BONUS)

fclean : clean
	@make -C libft fclean
	@rm -rf $(NAME) $(BONUS)

re : fclean all

.PHONY: all clean fclean re bonus