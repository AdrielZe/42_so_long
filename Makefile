# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asilveir <asilveir@student.42.fr>          +#+  +:+       +#+        #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/07 20:16:54 by asilveir          #+#    #+#              #
#    Updated: 2024/12/05 18:10:23 by asilveir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# Nome dos executáveis
NAME = so_long
BONUS_NAME = so_long_bonus

# Diretórios
SRC_DIR = ./src
BONUS_DIR = ./bonus
MANDATORY_HEADERS_DIR = $(SRC_DIR)/headers
BONUS_HEADERS_DIR = $(BONUS_DIR)/headers

# Arquivos de fonte mandatório
SRC = $(SRC_DIR)/setup_game.c $(SRC_DIR)/handle_events.c \
	$(SRC_DIR)/process_inputs.c $(SRC_DIR)/render_map.c $(SRC_DIR)/render_character.c \
	$(SRC_DIR)/background_utils_1.c $(SRC_DIR)/background_utils_2.c $(SRC_DIR)/process_movements.c \
	$(SRC_DIR)/render_collectible.c $(SRC_DIR)/render_door.c $(SRC_DIR)/map_utils.c $(SRC_DIR)/move_up.c \
	$(SRC_DIR)/move_down.c $(SRC_DIR)/move_right.c $(SRC_DIR)/move_left.c $(SRC_DIR)/map_init.c \
	$(SRC_DIR)/map_validation_utils_1.c $(SRC_DIR)/map_validation_utils_2.c $(SRC_DIR)/map_validation_utils_3.c \
	$(SRC_DIR)/flood_fill_utils_1.c $(SRC_DIR)/flood_fill_utils_2.c $(SRC_DIR)/close_game.c

# Main específica do mandatório
MANDATORY_MAIN = $(SRC_DIR)/so_long.c

# Arquivos de fonte bônus
BONUS = $(BONUS_DIR)/src/handle_events_bonus.c \
	$(BONUS_DIR)/src/setup_animations_bonus.c \
	$(BONUS_DIR)/src/process_inputs_bonus.c \


# Main específica do bônus
BONUS_MAIN = $(BONUS_DIR)/src/so_long_bonus.c

# Compilador e flags
CC = clang
CFLAGS = -Wall -Wextra -Werror
MANDATORY_CFLAGS = $(CFLAGS) -I$(MANDATORY_HEADERS_DIR) -Ilibft
BONUS_CFLAGS = $(CFLAGS) -I$(BONUS_HEADERS_DIR) -Ilibft

# Diretórios da libft
LIBFT_DIR = ./libft
LIBFT = $(LIBFT_DIR)/libft.a

# Flags de linkagem
LDFLAGS = -L$(LIBFT_DIR) -lft -lX11 -lXext -lmlx

# Regra principal (mandatório)
all: $(LIBFT) $(NAME)

$(NAME): $(SRC) $(MANDATORY_MAIN)
	$(CC) $(MANDATORY_CFLAGS) $(SRC) $(MANDATORY_MAIN) $(LIBFT) $(LDFLAGS) -o $(NAME)

# Regra de bônus
bonus: $(LIBFT) $(BONUS_NAME)

$(BONUS_NAME): $(SRC) $(BONUS) $(BONUS_MAIN)
	$(CC) $(BONUS_CFLAGS) $(SRC) $(BONUS) $(BONUS_MAIN) $(LIBFT) $(LDFLAGS) -o $(BONUS_NAME)

# Compilar a libft
$(LIBFT):
	make -C $(LIBFT_DIR)

# Limpeza
clean:
	rm -rf $(NAME) $(BONUS_NAME)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -rf $(NAME) $(BONUS_NAME)
	make fclean -C $(LIBFT_DIR)

# Reconstruir tudo
re: fclean all

# Testar com Valgrind (mandatório)
valgrind: $(NAME)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME) map1.ber

# Testar com Valgrind (bônus)
valgrind_bonus: $(BONUS_NAME)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(BONUS_NAME) map1.ber

.PHONY: all clean fclean re valgrind bonus valgrind_bonus
