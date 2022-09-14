# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: pmikada <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/08/08 17:35:24 by pmikada           #+#    #+#              #
#    Updated: 2022/08/17 14:41:34 by pmikada          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

NAME_A = push_swap.a

BONUS = checker

MAIN = main.c

B_MAIN = bonus_main.c

SRCS = ft_loc.c ft_utils.c ft_split.c ft_free.c ft_check_err.c \
		ft_swap.c ft_push.c ft_rotate.c ft_reverse_rotate.c \
		ft_change_index.c ft_algorithm.c ft_algorithm_utils.c ft_algorithm_sort.c

G_N_L = get_next_line/get_next_line.c get_next_line/get_next_line_utils.c

OBJS = $(SRCS:.c=.o)

B_OBJS = $(G_N_L:.c=.o)

CFLAGS = -Wall -Wextra -Werror

GCC = gcc

all: $(NAME)

$(NAME): $(OBJS)
	$(GCC) $(CFLAGS) -o $(NAME) $(MAIN) $(OBJS)

bonus: $(BONUS)

$(BONUS): $(OBJS) $(B_OBJS)
	$(GCC) $(CFLAGS) -o $(BONUS) $(B_MAIN) $(OBJS) $(B_OBJS)

clean:
	rm -rf *.o
	rm -rf get_next_line/*.o

fclean: clean
	rm -rf $(NAME) $(BONUS)

re: fclean all

.PHONY: all bonus clean fclean re
