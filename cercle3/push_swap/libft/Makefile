# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: macbookpro <macbookpro@student.42.fr>      +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2019/09/18 20:53:32 by lusokol           #+#    #+#              #
#    Updated: 2021/10/14 15:27:56 by macbookpro       ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = libft.a

SRCS = ft_atoi.c \
	   ft_isalpha.c \
	   ft_bzero.c \
	   ft_isascii.c \
	   ft_isalnum.c \
	   ft_isdigit.c \
	   ft_calloc.c \
	   ft_isprint.c \
	   ft_itoa.c \
	   ft_memccpy.c \
	   ft_memchr.c \
	   ft_memcpy.c \
	   ft_memcmp.c \
	   ft_memset.c \
	   ft_putchar_fd.c \
	   ft_putendl_fd.c \
	   ft_putstr_fd.c \
	   ft_strchr.c \
	   ft_putnbr_fd.c \
	   ft_strlcat.c \
	   ft_strdup.c \
	   ft_strjoin.c \
	   ft_strlen.c \
	   ft_strncmp.c \
	   ft_split.c \
	   ft_strrchr.c \
	   ft_substr.c \
	   ft_strlcpy.c \
	   ft_toupper.c \
	   ft_tolower.c \
	   ft_strtrim.c \
	   ft_strmapi.c \
	   ft_strnstr.c \
	   ft_memmove.c \
	   ft_lstadd_back.c \
	   ft_lstadd_front.c \
	   ft_lstdelone.c \
	   ft_lstiter.c \
	   ft_lstclear.c \
	   ft_lstlast.c \
	   ft_lstnew.c \
	   ft_lstsize.c \
	   ft_lstmap.c \
	   ft_putnbr.c \
	   ft_putchar.c \
	   ft_putstr.c \
	   ft_printf.c \
	   ft_printf_arg.c \
	   ft_printf_arg2.c \
	   checks.c \
	   ft_util.c \
	   disp_util.c \

PRINTF = ../ft_printf.o \
		 ../ft_printf_arg.o \
		 ../ft_printf_arg2.o \
		 ../checks.o \
		 ../ft_util.o \
		 ../disp_util.o \

FLAGS = -Wall -Wextra -Werror -g3

all: ${NAME}

$(NAME):
	@printf "\e[38;5;208mCompiling the libft...\e[0m\n"
	@gcc $(FLAGS) -c $(SRCS) -I .
	@printf "\e[38;5;118mLibft successfully compiles !\e[0m\n"
	@ar rc $(NAME) $(SRCS:.c=.o) $^
	@ranlib $(NAME)
	@mv $(NAME) ../.

clean:
	@printf "\e[38;5;208m[Clean] the libft...\e[0m\n"
	@rm -rf $(SRCS:.c=.o)


fclean:	clean
	@printf "\e[38;5;208m[FClean] the libft...\e[0m\n"
	@rm -rf ../$(NAME)

re:	fclean all

.PHONY:	all clean fclean re
