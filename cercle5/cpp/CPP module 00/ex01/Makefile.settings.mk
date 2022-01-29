# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile.settings.mk                               :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/10/21 21:06:11 by rotrojan          #+#    #+#              #
#    Updated: 2022/01/29 18:57:42 by macbookpro       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# The name of the binary
NAME = Phone_Book

# sources needed to compile
SRC =	main.cpp \
		phone_book.cpp \
		contact.cpp \

# path of sources (if nothing, put a '.')
PATH_SRCS = .

# pathe of includes
INCLUDES = .

# flags for compilation
FLAGS = -Wall -Wextra -Werror -std=c++98# -g3 -fsanitize=address

# compiler used
CXX = clang++
