/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   bonus.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asilveir <asilveir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/19 15:51:19 by asilveir          #+#    #+#             */
/*   Updated: 2024/12/05 00:58:53 by asilveir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BONUS_H
# define BONUS_H

#include "../headers/main.h"
# include "../libft/libft.h"
# include <stdlib.h>
# include <mlx.h>
# include <X11/keysym.h>
# include <X11/X.h>
# include <stdio.h>
# include <fcntl.h>

# define WINDOW_WIDTH 1792
# define WINDOW_HEIGHT 896
# define MLX_ERROR 1
# define WALL_SIZE 32

int	check_collectibles_bonus(t_game *game);


#endif