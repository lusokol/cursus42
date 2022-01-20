# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/07 15:08:42 by macbookpro        #+#    #+#              #
#    Updated: 2022/01/20 15:36:37 by lusokol          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##########################################

NAME = philosophers

SRC =	main.c \
		utils.c \
		lst.c \
		exit.c \
		parsing.c \
		routine.c \
		text.c \

PATH_SRCS = ./srcs

INCLUDES =	./includes/

FLAGS = -Wall -Wextra -Werror# -g3 -fsanitize=address

##########################################

SRCS = $(addprefix $(PATH_SRCS)/,$(SRC))

OBJ_DIR = obj

OBJ = $(addprefix obj/,$(SRC:.c=.o))

TMP_FILE = tmp_folder

all: $(NAME)

$(OBJ_DIR)/%.o: $(PATH_SRCS)/%.c
	@if [ ! -d '$(TMP_FILE)' ]; then mkdir -p $(TMP_FILE); make project; fi;
	@mkdir -p $(OBJ_DIR)
	@printf "$(_ORANGE)| Compiling : $(_WHITE)%-21s$(_ORANGE)|\n" $<
	@gcc $(FLAGS) -I $(INCLUDES) -c $< -o $@

project:
	@printf "$(_ORANGE)___________________________________\n$(_R)"
	@printf "$(_BOLD)$(_ORANGE)| - %15s - 42 Project - |$(_R)\n" $(NAME)
	@printf "$(_ORANGE)___________________________________\n$(_R)"


$(NAME): $(OBJ)
	@gcc $(FLAGS) -I $(INCLUDES) $(OBJ) -o $(NAME)
	@printf "$(_ORANGE)___________________________________\n$(_R)"
	@printf "$(_BOLD)$(_GREEN)$(NAME) successfully compiles !$(_R)\n"
	@chmod 777 $(NAME)
	@rm -rf $(TMP_FILE)

clean:
	@printf "$(_RED)[Clean] Removing .o ...\e[0m\n"
	@rm -rf $(OBJ_DIR)

fclean: clean
	@printf "$(_RED)[Fclean] Removing $(NAME) ...$(_R)\n"
	@rm -rf $(NAME)

re: clean all

########################################## colors

_WHITE = \e[97m
_GREEN = \e[38;5;118m
_ORANGE = \e[38;5;208m
_RED = \e[38;5;196m
_BOLD = \e[1m
_R = \e[0m

##########################################

.PHONY: all clean fclean re project