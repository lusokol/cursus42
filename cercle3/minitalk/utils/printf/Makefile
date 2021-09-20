NAME = libftprintf.a

SRCS = ft_printf.c \
	   ft_printf_arg.c \
	   ft_printf_arg2.c \
	   checks.c \
	   ft_util.c \
	   disp_util.c \

FLAGS = -Wall -Werror -Wextra

LIBFT = libft.a

LIBFT_DIR = ./libft

all: ${NAME}

$(NAME):
	@gcc $(FLAGS) -c $(SRCS) -I .
	@(cd $(LIBFT_DIR) && $(MAKE))
	@mv $(LIBFT_DIR)/$(LIBFT) ./$(NAME)

clean:
	@rm -rf $(SRCS:.c=.o)
	@(cd $(LIBFT_DIR) && $(MAKE) $@)

fclean:
	@rm -rf $(NAME) $(SRCS:.c=.o)
	@(cd $(LIBFT_DIR) && $(MAKE) $@)

re: fclean all

.PHONY:	all clean fclean re
