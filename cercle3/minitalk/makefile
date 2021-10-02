# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/09/15 14:06:14 by macbookpro        #+#    #+#              #
#    Updated: 2021/10/02 11:45:43 by macbookpro       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

CLIENT_NAME = client
SERVER_NAME = server
PRINTF = ./utils/printf/libftprintf.a

CLIENT_SRCS =	./srcs/client.c \
				./srcs/client2.c

SERVER_SRCS =	./srcs/server.c

FLAGS = -Wall -Wextra -Werror

INCLUDES = ./utils/minitalk.h

PRINTF_DIR = ./utils/printf

all: ${PRINTF} ${CLIENT_NAME} ${SERVER_NAME}

$(PRINTF):
	@(cd $(PRINTF_DIR) && $(MAKE))
	@cp $(PRINTF) ./utils

$(CLIENT_NAME): ${PRINTF}
	@printf "\e[38;5;208mCompiling the client...\e[0m\n"
	@gcc $(FLAGS) $(CLIENT_SRCS) $(PRINTF) -I $(INCLUDES) -o client
	@printf "\e[38;5;118mClient successfully compiles !\e[0m\n"

$(SERVER_NAME): ${PRINTF}
	@printf "\e[38;5;208mCompiling the server...\e[0m\n"
	@gcc $(FLAGS) $(SERVER_SRCS) $(PRINTF) -I $(INCLUDES) -o server
	@printf "\e[38;5;118mServer successfully compiles !\e[0m\n"

clean:
	@printf "\e[38;5;196m[Clean] Removing client and server...\e[0m\n"
	@rm -rf $(CLIENT_NAME) $(SERVER_NAME) $(PRINTF)

fclean:
	@printf "\e[38;5;196m[Fclean] Removing client and server...\e[0m\n"
	@rm -rf $(CLIENT_NAME) $(SERVER_NAME) $(PRINTF) ./utils/libftprintf.a
	@cd $(PRINTF_DIR) && $(MAKE) $@

re: fclean all

run: ${SERVER_NAME}
	@printf "\e[38;5;87mStarting the server...\e[0m\n"
	@./server

.PHONY: all clean fclean re run