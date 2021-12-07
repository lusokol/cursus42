# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/07 15:08:42 by macbookpro        #+#    #+#              #
#    Updated: 2021/12/07 11:34:35 by lusokol          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap

SRCS =	./srcs/push_swap.c \
		./srcs/lst.c \
		./srcs/rules.c \
		./srcs/sort_small.c \
		./srcs/rules_silent.c \
		./srcs/quick_sort.c \
		./srcs/logic_sort.c \

LIBFT = libft.a

FLAGS = -Wall -Wextra -Werror -g3 -fsanitize=address

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