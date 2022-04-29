# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: fbindere <fbindere@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2022/01/21 21:06:22 by eozben            #+#    #+#              #
#    Updated: 2022/04/29 19:11:27 by fbindere         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = cub3D
FLAGS = -Wall -Wextra -Werror
INC = -Iincludes
SRCS = open_textures.c texture_utils.c cub3d.c error.c cast_sprites.c \
		cast_walls.c draw_floor_ceiling.c draw_sprites.c draw_walls.c \
		check_map.c check_utils.c parser_utils.c parser.c read_map.c \
		read_textures.c camera_move.c key_presses.c mlx_utils.c mouse.c \
		move.c minimap.c door.c foe.c
OBJ_PATH = ./objs/
OBJS = $(patsubst %.c,$(OBJ_PATH)%.o,$(SRCS))
LIBS = -Llibft -lft -Lmlx -lmlx
LIBFT = ./libft/libft.a
LIBMLX = ./mlx/libmlx.a
UP = "\033[A"
CUT = "\033[K"

all:$(NAME)

$(NAME): $(OBJ_PATH) $(OBJS) $(LIBFT) $(LIBMLX)
	@$(CC) $(FLAGS) $(OBJS) -o $(NAME) $(LIBS) -framework OpenGL -framework AppKit
	@echo "                                                         "
	@echo " \033[1;32m  ___|   _ \    \  |   _ \ _ _|  |      ____|  __ \   | "
	@echo "  |      |   |  |\/ |  |   |  |   |      __|    |   |  | "
	@echo "  |      |   |  |   |  ___/   |   |      |      |   | _| "
	@echo " \____| \___/  _|  _| _|    ___| _____| _____| ____/  _) \033[0m"
	@echo "                                                         "

$(OBJ_PATH)%.o: srcs/*/%.c
	@$(CC) $(FLAGS) -c $< -o $@

$(LIBMLX):
	@echo ""
	@echo "mlx:"
	@echo "\033[1;32m0%\033[0m   [                      ]"
	@sleep 0.1
	@printf $(UP)$(CUT)
	@echo "\033[1;32m33%\033[0m  [\033[1;32m ██████\033[0m               ]"
	@sleep 0.1
	@printf $(UP)$(CUT)
	@echo "\033[1;32m50%\033[0m  [\033[1;32m ██████████\033[0m           ]"
	@make -silent -C ./mlx
	@printf $(UP)$(CUT)
	@echo "\033[1;32m83%\033[0m  [\033[1;32m ████████████████\033[0m     ]"
	@sleep 0.1
	@printf $(UP)$(CUT)
	@echo "\033[1;32m100%\033[0m [\033[1;32m ████████████████████ \033[0m]"

$(LIBFT):
	@echo ""
	@echo "libft:"
	@echo "\033[1;32m0%\033[0m   [                      ]"
	@sleep 0.1
	@printf $(UP)$(CUT)
	@echo "\033[1;32m33%\033[0m  [\033[1;32m ██████\033[0m               ]"
	@sleep 0.1
	@printf $(UP)$(CUT)
	@echo "\033[1;32m50%\033[0m  [\033[1;32m ██████████\033[0m           ]"
	@make -silent -C ./libft
	@printf $(UP)$(CUT)
	@echo "\033[1;32m83%\033[0m  [\033[1;32m ████████████████\033[0m     ]"
	@sleep 0.1
	@printf $(UP)$(CUT)
	@echo "\033[1;32m100%\033[0m [\033[1;32m ████████████████████ \033[0m]"

$(OBJ_PATH):
	@mkdir -p $(OBJ_PATH)

clean:
	@rm -rf $(OBJ_PATH)
	@make clean -C ./libft
	@echo "\033[1;32m.o files removed!\033[0m"

fclean:
	@rm -rf $(NAME)
	@rm -rf $(OBJ_PATH)
	@make clean -C ./mlx
	@make fclean -C ./libft
	@echo "\033[1;32mbinary files removed!\033[0m"

re: fclean all