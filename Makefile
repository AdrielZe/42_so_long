# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asilveir <asilveir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/07 20:16:54 by asilveir          #+#    #+#              #
#    Updated: 2024/11/18 15:56:45 by asilveir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long
SRC = main.c handle_events.c manage_movements.c render_game.c render_map.c render_character.c
OBJ = $(SRC:.c=.o)
CC = clang
//CFLAGS = -Wall -Wextra -Werror
LDFLAGS = -lX11 -lXext -lmlx
VALGRIND_FLAGS = --leak-check=full --show-leak-kinds=all --track-origins=yes

all: $(NAME)

$(NAME): $(OBJ)
	$(CC) $(OBJ) -o $(NAME) $(LDFLAGS)

%.o: %.c
	$(CC) $(CFLAGS) -c $< -o $@

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME)

re: fclean all

valgrind: $(NAME)
	valgrind $(VALGRIND_FLAGS) ./$(NAME)

.PHONY: all clean fclean re valgrind

