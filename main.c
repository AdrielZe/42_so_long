#include "./headers/main.h"


// VALGRIND TEST:
// valgrind --leak-check=full --show-leak-kinds=all --track-origins=yes ./a.out

// COMPILE: 
// clang main.c -lX11 -lXext -lmlx


int	main(void)
{
	t_data data;

	data.mlx_ptr = mlx_init(); // Get resources form minilibx
	if (!data.mlx_ptr)
		return (MLX_ERROR);
	data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT, "GAME!!!!!!"); 
	if (!data.win_ptr)
	{
		free(data.win_ptr);
		return (MLX_ERROR);
	}
	
	//Set up image
	data.img.mlx_img = mlx_new_image(data.mlx_ptr, WINDOW_WIDTH, WINDOW_HEIGHT);
	data.xpm_img.mlx_xpm_img = mlx_xpm_file_to_image(data.mlx_ptr, "./resources/map/grass_block_32.xpm", &data.xpm_img.width, &data.xpm_img.height);
	if(!data.xpm_img.mlx_xpm_img)
	{
		free(data.xpm_img.mlx_xpm_img);
		return(MLX_ERROR);
	}

	data.img.addr = mlx_get_data_addr(data.img.mlx_img, &data.img.bpp, &data.img.line_len, &data.img.endian);
	// Hooks
	mlx_loop_hook(data.mlx_ptr, handle_no_event, &data); // This hook is triggered when there's no event processed. We use it to end the loop when we close our window
	mlx_hook(data.win_ptr, KeyPress, KeyPressMask, &handle_keypress, &data); //It is similar to a key hook, but we have two more parameters, the first and the second, where we have the name and the mask of the X event we want to use
	//mlx_key_hook(data.win_ptr, &handle_input, &data); //mlx_key_hook executes the 'handle_input' function, each time a key is released. The parameters are the win_ptr, a function we want to execute and the address of the t_data object that contains the attributes we need to access in handle_input(our function)
	render(&data);
	mlx_loop(data.mlx_ptr); // Responsável por iniciar o loop de eventos do programa, permitindo que ele responda a eventos como entradas de teclado, movimentação do mouse, cliques, etc.
	// Once finished the program, free resources allocated
	//render(&data);

	// Destroy displays to avoid memory leaks ( the display is the connexion identifier used  to connect with the X server)
	mlx_destroy_image(data.mlx_ptr, data.xpm_img.mlx_xpm_img);
	mlx_destroy_image(data.mlx_ptr, data.img.mlx_img);
	mlx_destroy_display(data.mlx_ptr); 

	// Free pointers
	free(data.mlx_ptr);
}