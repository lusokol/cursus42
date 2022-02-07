# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile.settings.mk                               :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/21 21:06:11 by rotrojan          #+#    #+#              #
#    Updated: 2022/02/07 16:36:53 by lusokol          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# The name of the binary
NAME = Brain

# sources needed to compile
SRC =	main.cpp

# path of sources
PATH_SRCS = ./srcs

# pathe of includes
INCLUDES =	./includes/

# flags for compilation
FLAGS = -Wall -Wextra -Werror -std=c++98# -g3 -fsanitize=address

# compiler used
CXX = clang++
