# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile.settings.mk                               :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/21 21:06:11 by rotrojan          #+#    #+#              #
#    Updated: 2022/02/01 16:28:09 by lusokol          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# The name of the binary
NAME = megaphone

# sources needed to compile
SRC = megaphone.cpp \

# path of sources
PATH_SRCS = ./srcs

# pathe of includes
INCLUDES =	./includes/

# flags for compilation
FLAGS = -Wall -Wextra -Werror -std=c++98# -g3 -fsanitize=address

# compiler used
CXX = clang++
