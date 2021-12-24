# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/07 15:08:42 by macbookpro        #+#    #+#              #
#    Updated: 2021/12/23 16:26:41 by macbookpro       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS =	./srcs/push_swap.c \
		./srcs/lst.c \
		./srcs/sort_small.c \
		./srcs/logic_sort.c \
		./srcs/init.c \
		./srcs/init2.c \
		./srcs/free.c \
		./srcs/nb_move.c \
		./srcs/logic_move.c \
		./srcs/calcul_logic.c \
		./srcs/rules.c \
		./srcs/rules2.c \
		./srcs/rules3.c \
		./srcs/rules_silent.c \
		./srcs/rules_silent2.c \
		./srcs/rules_silent3.c \
		./srcs/bt_lst.c \
		./srcs/check_bt.c \
		./srcs/push_b.c \
		./srcs/push_b2.c \

LIBFT = libft.a

FLAGS = -Wall -Wextra -Werror# -g3 -fsanitize=address

INCLUDES =	./includes

all: $(NAME)

$(NAME): $(LIBFT) 
	@printf "\e[38;5;208mCompiling $(NAME)...\e[0m\n"
	@clang $(FLAGS) $(SRCS) $(LIBFT) -I $(INCLUDES) -o $(NAME)
	@printf "\e[38;5;118m$(NAME) successfully compiles !\e[0m\n"
	@chmod 777 $(NAME)

$(LIBFT):
	@(cd ./libft && $(MAKE) --no-print-directory $^)

clean:
	@printf "\e[38;5;196m[Clean] Removing $(NAME)...\e[0m\n"
	@rm -rf $(NAME)

fclean:
	@printf "\e[38;5;196m[Fclean] Removing $(NAME)...\e[0m\n"
	@rm -rf $(NAME)
	@(cd ./libft && $(MAKE) --no-print-directory $@)

re: clean all

.PHONY: all clean fclean re