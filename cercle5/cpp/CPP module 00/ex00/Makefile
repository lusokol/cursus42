# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/07 15:08:42 by macbookpro        #+#    #+#              #
#    Updated: 2022/01/27 14:33:45 by lusokol          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

##########################################

NAME = megaphone

SRC = megaphone.cpp

PATH_SRCS = ./

INCLUDES =	./

FLAGS = -Wall -Wextra -Werror -std=c++98# -g3 -fsanitize=address

##########################################

SRCS = $(addprefix $(PATH_SRCS)/,$(SRC))

OBJ_DIR = obj

OBJ = $(addprefix obj/,$(SRC:.cpp=.o))

CXX = clang++

BEGIN = 0

NO_RECURSE = 0

all: $(NAME)

$(OBJ_DIR)/%.o: $(PATH_SRCS)/%.cpp
ifeq ($(NO_RECURSE), 0)
	$(eval NB_FILE_TO_COMPILE ?= $(shell make --dry-run --debug=b | grep "does not\|Must remake" | grep -o "\`.*\.o'" | sort | uniq | wc -l))
endif
	@if [ '$(BEGIN)' -eq '0' ]; then BEGIN=1; make project; printf "nb file to compile : $(NB_FILE_TO_COMPILE)\n"; fi;
	@mkdir -p $(OBJ_DIR)
	@printf "$(_ORANGE)┃ Compiling : $(_WHITE)%-21s$(_ORANGE)┃\n" $<
	@$(CXX) $(FLAGS) -I $(INCLUDES) -c $< -o $@

project:
	@printf "$(_ORANGE)┏━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┓\n$(_R)"
	@printf "$(_BOLD)$(_ORANGE)┃ - %15s - 42 Project - ┃$(_R)\n" $(NAME)
	@printf "$(_ORANGE)┣━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┫\n$(_R)"


$(NAME): $(OBJ)
	@printf "$(_ORANGE)┗━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━━┛\n$(_R)"
	@$(CXX) $(FLAGS) -I $(INCLUDES) $(OBJ) -o $(NAME)
	@printf "$(_BOLD)$(_GREEN)$(NAME) successfully compiles !$(_R)\n"
	@chmod 777 $(NAME)

clean:
	@printf "$(_RED)[Clean] Removing .o ...\e[0m\n"
	@rm -rf $(OBJ_DIR)

fclean: clean
	@printf "$(_RED)[Fclean] Removing $(NAME) ...$(_R)\n"
	@rm -rf $(NAME)

show:
	printf "$(OBJ)\n"

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