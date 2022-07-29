# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: jihyukim <jihyukim@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/07/21 14:15:32 by jihyukim          #+#    #+#              #
#    Updated: 2022/07/29 17:33:57 by jihyukim         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

CC = cc
CFLAGS = -Wall -Werror -Wextra

SRCS = push_swap.c operation.c sort.c utils.c utils_node.c

OBJS = $(SRCS:.c=.o)

all : $(NAME)

$(NAME) : $(OBJS)
	@make -C libft
	@$(CC) $(CFLAGS) -L ./libft -lft $(OBJS) -o $@

%.o :%.c
	@$(CC) $(CFLAGS) -c $< -o $@

clean :
	@make -C libft clean
	@rm -rf $(OBJS)

fclean : clean
	@make -C libft fclean
	@rm -rf $(NAME)

re : fclean all

.PHONY: all clean fclean re