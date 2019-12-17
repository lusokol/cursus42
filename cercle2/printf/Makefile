NAME = libftprintf.a

SRCS = ft_printf.c \
	   ft_printf_arg.c \
	   checks.c \

FLAGS = -Wall -Werror -Wextra

LIBFT = libft.a

LIBFT_DIR = ./libft

all: ${NAME}

$(NAME):
	@gcc $(FLAGS) -c $(SRCS) -I .
	@(cd $(LIBFT_DIR) && $(MAKE))
	@mv $(LIBFT_DIR)/$(LIBFT) ./$(NAME)

clean:
	@echo "Suppression des .o"
	@rm -rf $(SRCS:.c=.o)
	@(cd $(LIBFT_DIR) && $(MAKE) $@)

fclean:
	@echo "Suppression des .o"
	@echo "Suppression des .a"
	@rm -rf $(NAME)
	@(cd $(LIBFT_DIR) && $(MAKE) $@)

re: fclean all

.PHONY:	all clean fclean re
