#include "so_long.h"



typedef struct s_program
{
	void	*mlx_pointer;
	void	*window;
}			t_program;



typedef struct	s_data
{
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_length;
	int		endian;
}			t_data;



/** PURPOSE : init 42minilibx and open window.
 * 1. mlx_returns a pointer (void *). A lot of the library functions
 * need it in order to work.
 * 2. Open window, save pointer for later use. */
void	initalize(t_program *game)
{
	game->mlx_pointer = mlx_init();
	game->window = mlx_new_window(game->mlx_pointer,  HEIGHT, WIDTH, "ventana");
}

/** PURPOSE : Initialize the image with size 1920×1080 as follows: */
void	initalize_image(t_program *game, t_data *image)
{
	image->img = mlx_new_image(game->mlx_pointer,  HEIGHT, WIDTH);
}

/** PURPOSE : Creates a sort of mold of an image (or a pixel)
 * a memory adress is needed. Not only that, but also the data
 * related to the image, which will all be store in a struct.
 * --All arguments must be ponters.
 * 1. Img is the pointer of the previous initialized image.
 * 2. Bits per pixel, bpp. Color depth, is the number of bits used
 * to indicate the color of a single pixel
 * bits_per_pixel, line_length and endian variables passed by reference.
 * These will be set accordingly by MiniLibX */
void	create_mold(t_data *image)
{
	image->addr = mlx_get_data_addr(image->img, &image->bits_per_pixel, &image->line_length,
								&image->endian);
}

/* int	f(void *param)
{
	param = NULL;
	exit(0);
} */

/** PURPOSE : Creates single pixel with specs of DATA
 * at x - y, of a given colour.
 * The function that will mimic the behaviour
 * of mlx_pixel_put but will simply be many times faster.
 * Offset calculation:
 * int offset = (y * img.line_length + x * (img.bits_per_pixel / 8)) */
void	my_mlx_pixel_put(t_data *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_length + x * (data->bits_per_pixel / 8));
	*(unsigned int*)dst = color;
}

/** PURPOSE : Pushes the full image, with all the bytes at once
 * to the window. Connects the full image with the window. */
void	push_image_towindow(t_program *game, t_data *image)
{
	mlx_put_image_to_window(game->mlx_pointer, game->window, image->img, 0, 0);
}

/** PURPOSE : init 42minilibx, open window, and load an image.
 * 1. Define structure game (contains the lib and the window) and image.
 * 2. Define structure image (contains address of the image and parameters).
 * 3. Initialize both structures */
int main(void)
{
	t_program	*game;
	t_data		*image;

	game = ft_calloc(1,sizeof(*game));
	if (!game)
		ft_shutdown();
	image = ft_calloc(1,sizeof(*image));
	if (!image)
		ft_shutdown();
	initalize(game);
	initalize_image(game, image);
	create_mold(image);


	//void *ptr = 0;
	//mlx_hook(game->window, 17, 0, (*f)(), ptr);


	int x = 100;
	int y = 100;
	while (x < 1000 && y < 1000)
	{
		my_mlx_pixel_put(image, x, y, 0x00FF0000);
		x++;
	}
	x = 100;
	y = 100;
	while (x < 1000 && y < 1000)
	{
		my_mlx_pixel_put(image, x, y, 0x00FF0000);
		y++;
	}
	x = 100;
	while (x < 1000)
	{
		my_mlx_pixel_put(image, x, y, 0x00FF0000);
		x++;
	}
	y = 100;
	while (y < 1000)
	{
		my_mlx_pixel_put(image, x, y, 0x00FF0000);
		my_mlx_pixel_put(image, x+1, y+1, 0x0000FF00);
		my_mlx_pixel_put(image, x+2, y+2, 0x000000FF);
		y++;
	}
	push_image_towindow(game, image);
	mlx_loop(game->mlx_pointer);
	return (0);
}
