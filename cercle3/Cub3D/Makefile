NAME = Cub3D

SRCS = ./srcs/fill_struct.c \
	   ./srcs/check_map.c \
	   ./srcs/get_next_line.c \
	   ./srcs/get_next_line_utils.c \
	   ./srcs/main.c \
	   ./srcs/movement.c \
	   ./srcs/rotkey.c \
	   ./srcs/texture.c \
	   ./srcs/skybox.c \
	   ./srcs/sprite.c \
	   ./srcs/saut.c \
	   ./srcs/parsing_sprite.c \
	   ./srcs/hud.c \
	   ./srcs/goomba.c \
	   ./srcs/game_over.c \
	   ./srcs/all_check.c \
	   ./srcs/calcul.c \
	   ./srcs/check_error.c \
	   ./srcs/init_struct.c \
	   ./srcs/next.c \
	   ./srcs/raycasting.c \
	   ./srcs/bmpbis.c \
	   ./srcs/bmp.c \

BIBLIO = libmlx.a libmlx.dylib libft.a\

FLAGS = -Wall -Werror -Wextra -framework OpenGL -framework AppKit# -g3 -fsanitize=address

CONFIG = map.cub

all: ${NAME}

$(NAME) : libmlx.a libmlx.dylib libft.a
	@echo "Création de l'executable..."
	@gcc $(FLAGS) -D BUFFER_SIZE=32 $(SRCS) $(BIBLIO) -o $(NAME)
	@echo "Compilation terminée !"

clean:
	@echo "Clean..."
	@rm -rf $(NAME)
	@echo "Clean !"

fclean:
	@echo "Fclean..."
	@rm -rf $(NAME) $(SRCS:.c=.o) $(BIBLIO)
	@(cd ./libft && $(MAKE) fclean)
	@echo "Fclean !"

re:	clean all

run:	re
	@(clear)
	@(./$(NAME) $(CONFIG))

libft.a:
	@echo "Compilation de la libft"
	@(cd ./libft && $(MAKE) $@ && cp libft.a ../.)

libmlx.dylib:
	@echo "Compilation de la mlx MMS"
	@(cd ./minilibx2 && $(MAKE) $@ && cp libmlx.dylib ../.) 2>/dev/null

libmlx.a:
	@echo "Compilation de la mlx openGL"
	@(cd ./minilibx && $(MAKE) $@ && cp libmlx.a ../.) 2>/dev/null

.PHONY:	all clean fclean re
