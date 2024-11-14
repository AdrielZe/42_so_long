# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: asilveir <asilveir@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2024/10/07 20:16:54 by asilveir          #+#    #+#              #
#    Updated: 2024/11/14 19:03:59 by asilveir         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = so_long.a
SRC = main.c handle_events.c manage_movements.c render_game.c render_map.c
OBJ = $(SRC:.c=.o)
CC = clang
CFLAGS = -lX11 -lXext -lmlx



all: $(NAME) 

$(NAME): $(OBJ)
	ar rcs $(NAME) $(OBJ) 

clean:
	rm -rf $(OBJ)

fclean: clean
	rm -rf $(NAME) 

re: fclean all