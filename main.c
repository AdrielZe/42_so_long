#include "./headers/main.h"


// VALGRIND TEST:
// valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./a.out

// COMPILE: 
// clang main.c -lX11 -lXext -lmlx


int	main(void)
{
	t_game game;

	game.mlx_ptr = mlx_init(); // Get resources form minilibx
	if (!game.mlx_ptr)
		return (MLX_ERROR);
	game.win_ptr = mlx_new_window(game.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "GAME!!!!!!"); 
	if (!game.win_ptr)
	{
		free(game.win_ptr);
		return (MLX_ERROR);
	}
	
	//Set up image
	game.img.mlx_img = mlx_new_image(game.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	game.wall.wall_ptr = mlx_xpm_file_to_image(game.mlx_ptr, "./resources/map/grass_block_32.xpm", &game.wall.width, &game.wall.height);
	game.character.character_ptr = mlx_xpm_file_to_image(game.mlx_ptr, "./resources/characters/character_60.xpm", &game.wall.width, &game.wall.height);
	if(!game.wall.wall_ptr)
	{
		free(game.wall.wall_ptr);
		return(MLX_ERROR);
	}

	game.img.addr = mlx_get_data_addr(game.img.mlx_img, &game.img.bpp, &game.img.line_len, &game.img.endian);
	// Hooks
	render(&game);
	mlx_loop_hook(game.mlx_ptr, handle_no_event, &game); // This hook is triggered when there's no event processed. We use it to end the loop when we close our window
	mlx_hook(game.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &game); //It is similar to a key hook, but we have two more parameters, the first and the second, where we have the name and the mask of the X event we want to use
	mlx_loop(game.mlx_ptr); // Responsável por iniciar o loop de eventos do programa, permitindo que ele responda a eventos como entradas de teclado, movimentação do mouse, cliques, etc
	// Once finished the program, free resources allocated

	// Destroy displays to avoid memory leaks ( the display is the connexion identifier used  to connect with the X server)
	mlx_destroy_image(game.mlx_ptr, game.wall.wall_ptr);
	mlx_destroy_image(game.mlx_ptr, game.img.mlx_img);
	mlx_destroy_display(game.mlx_ptr); 

	// Free pointers
	free(game.mlx_ptr);
}