# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile.settings.mk                               :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: lusokol <lusokol@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/21 21:06:11 by rotrojan          #+#    #+#              #
#    Updated: 2022/02/01 16:25:17 by lusokol          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# The name of the binary
NAME = Phone_Book

# sources needed to compile
SRC =	main.cpp \
		phone_book.cpp \
		contact.cpp \

# path of sources (if nothing, put a '.')
PATH_SRCS = ./srcs

# pathe of includes
INCLUDES = ./includes

# flags for compilation
CXXFLAGS = -Wall -Wextra -Werror -std=c++98# -g3 -fsanitize=address

# compiler used
CXX = clang++
