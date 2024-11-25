# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asilveir <asilveir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/07 20:16:54 by asilveir          #+#    #+#              #
#    Updated: 2024/11/25 18:13:15 by asilveir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long

# Fontes
SRC = main.c setup_game.c handle_events.c manage_inputs.c render_game.c \
	render_map.c render_character.c render_background.c allocate_memory_map.c \
	handle_background_position.c manage_movements.c render_collectible.c \
	render_door.c

OBJ = $(SRC:.c=.o)

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
$(NAME): $(OBJ)
	$(CC) $(OBJ) $(LIBFT) $(LDFLAGS) -o $(NAME)

# Compilar a libft
$(LIBFT):
	make -C $(LIBFT_DIR)

# Compilar objetos
%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

# Limpeza
clean:
	rm -rf $(OBJ)
	make clean -C $(LIBFT_DIR)

fclean: clean
	rm -rf $(NAME)
	make fclean -C $(LIBFT_DIR)

# Reconstruir tudo
re: fclean all

# Testar com Valgrind
valgrind: $(NAME)
	valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./$(NAME)

.PHONY: all clean fclean re valgrind
