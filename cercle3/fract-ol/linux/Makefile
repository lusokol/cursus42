# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/07 15:08:42 by macbookpro        #+#    #+#              #
#    Updated: 2021/10/11 17:12:45 by macbookpro       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fract-ol

SRCS =	./srcs/main.c \
		./srcs/key.c \
		./srcs/mandelbrot.c \
		./srcs/utils.c \
		./srcs/zoom.c \
		./srcs/julia.c \
		./srcs/burningship.c \
		./srcs/color.c \
		./srcs/convert.c \
		./srcs/error.c

FLAGS = -Wall -Wextra -Werror

LINUX = -L./minilibx-linux -lmlx -lXext -lX11 -lm# -framework OpenGL -framework AppKit

INCLUDES =	./includes

MINILIBX =	./minilibx-linux

LIBMLX = libmlx_Linux.a

all: $(LIBMLX) $(NAME)

$(NAME):
	@printf "\e[38;5;208mCompiling fract-ol...\e[0m\n"
	@gcc $(FLAGS) $(LIBMLX) $(SRCS) -I $(INCLUDES) $(LINUX) -o $(NAME)
	@printf "\e[38;5;118mFract-ol successfully compiles !\e[0m\n"
	@chmod 777 $(NAME)

$(LIBMLX): $(MINILIBX)/$(LIBMLX)
	@cp $(MINILIBX)/$(LIBMLX) .

$(MINILIBX)/$(LIBMLX):	
	@printf "\e[38;5;208mCompiling the minilibx...\e[0m\n"
	@(cd $(MINILIBX) && $(MAKE))
	@printf "\e[38;5;118mMinilibx successfully compiles !\e[0m\n"


clean:
	@printf "\e[38;5;196m[Clean] Removing fract-ol...\e[0m\n"
	@rm -rf $(NAME) $(LIBMLX)

fclean:
	@printf "\e[38;5;196m[Fclean] Removing fract-ol and minilibx...\e[0m\n"
	@rm -rf $(NAME) $(LIBMLX)
	@cd $(MINILIBX) && $(MAKE) $@

re: clean all

.PHONY: all clean fclean re