# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/07 15:08:42 by macbookpro        #+#    #+#              #
#    Updated: 2022/01/11 13:42:25 by lusokol          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = 

SRCS =	

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