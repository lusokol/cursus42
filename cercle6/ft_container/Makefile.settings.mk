# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile.settings.mk                               :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/21 21:06:11 by rotrojan          #+#    #+#              #
#    Updated: 2022/04/19 15:45:40 by macbookpro       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# The name of the binary
NAME = ft_container

# sources needed to compile
SRC =	main.cpp \

# path of sources
PATH_SRCS = ./srcs

# pathe of includes
INCLUDES =	./includes/

# flags for compilation
CXXFLAGS = -Wall -Wextra -Werror# -std=c++98# -g3 -fsanitize=address

# compiler used
CXX = c++
