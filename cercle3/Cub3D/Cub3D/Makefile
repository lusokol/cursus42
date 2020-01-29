NAME = Cub3D

SRCS = fill_struct.c \
	   check_map.c \
	   get_next_line.c \
	   get_next_line_utils.c \
	   libft.a \
	   main.c \

MLX = libmlx.a \

FLAGS = -Wall -Werror -Wextra -g3 -fsanitize=address -lmlx -framework OpenGL -framework AppKit

CONFIG = fichierTest.cub

all: ${NAME}

$(NAME): 
	@echo "Creation de l'executable..."
	@gcc $(FLAGS) -D BUFFER_SIZE=32 $(SRCS) $(MLX) -o $(NAME)

clean:
	@echo "Clean..."
	@rm -rf $(NAME)

fclean:
	@echo "Fclean..."
	@rm -rf $(NAME)

re:	fclean all

run:	re
	@(clear)
	@(./$(NAME) $(CONFIG))

.PHONY:	all clean fclean re
