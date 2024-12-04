# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asilveir <asilveir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/07 20:16:54 by asilveir          #+#    #+#              #
#    Updated: 2024/12/04 20:21:55 by asilveir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

# Diretório src
SRC_DIR = ./src

# Lista de arquivos fonte
SRC = $(SRC_DIR)/so_long.c $(SRC_DIR)/setup_game.c $(SRC_DIR)/handle_events.c \
	$(SRC_DIR)/process_inputs.c $(SRC_DIR)/render_map.c $(SRC_DIR)/render_character.c \
	$(SRC_DIR)/background_utils_1.c $(SRC_DIR)/background_utils_2.c $(SRC_DIR)/process_movements.c \
	$(SRC_DIR)/render_collectible.c $(SRC_DIR)/render_door.c $(SRC_DIR)/map_utils.c $(SRC_DIR)/move_up.c \
	$(SRC_DIR)/move_down.c $(SRC_DIR)/move_right.c $(SRC_DIR)/move_left.c $(SRC_DIR)/map_init.c \
	$(SRC_DIR)/map_validation_utils_1.c $(SRC_DIR)/map_validation_utils_2.c $(SRC_DIR)/map_validation_utils_3.c \
	$(SRC_DIR)/flood_fill_utils_1.c $(SRC_DIR)/flood_fill_utils_2.c $(SRC_DIR)/close_game.c

# Compilador e flags
CC = clang
CFLAGS = -Wall -Wextra -Werror -Ilibft

# Diretórios da libft
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

# Flags de linkagem
LDFLAGS = -L$(LIBFT_DIR) -lft -lX11 -lXext -lmlx

# Regra principal
all: $(LIBFT) $(NAME)

# Compilar o jogo
$(NAME): $(SRC)
	$(CC) $(CFLAGS) $(SRC) $(LIBFT) $(LDFLAGS) -o $(NAME)

# Compilar a libft
$(LIBFT):
	make -C $(LIBFT_DIR)

# Limpeza
clean:
	rm -rf $(NAME)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -rf $(NAME)
	make fclean -C $(LIBFT_DIR)

# Reconstruir tudo
re: fclean all

# Testar com Valgrind
valgrind: $(NAME)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME) map1.ber

.PHONY: all clean fclean re valgrind
