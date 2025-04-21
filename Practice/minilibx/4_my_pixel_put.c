#include "minilibx-linux/mlx.h"
#include <X11/X.h>
#include <stdlib.h>
#include <stdio.h>

#define MALLOC_ERROR	1
#define SIDE_LEN	800

typedef struct s_img
{
	void	*img_ptr;
	char	*img_pixels_ptr;
	int		bits_per_pixel;
	int		endian;
	int		line_len;
}			t_img;

typedef struct s_var
{
	void	*mlx;
	void	*win;
	t_img		img;
}			t_var;

void	my_pixel_put(t_img *img, int x, int y, int color)
{
	int	offset;

	offset = (img->line_len * y) + (x * (img->bits_per_pixel / 8));

	*((unsigned int *)(offset + img->img_pixels_ptr)) = color;
}

void	color_screen(t_var *data, int color)
{
	for (int y = 0; y < SIDE_LEN; ++y)
	{
		for (int x = 0; x < SIDE_LEN; ++x)
		{
			my_pixel_put(&data->img, x, y, color);
		}

	}

}

int	f(int keysym, t_var *data)
{
	if (keysym == XK_r)
		color_screen(data, 0xff0000);
	else if (keysym == XK_g)
		color_screen(data, 0xff00);
	else if (keysym == XK_b)
		color_screen(data, 0xff);
	else if (keysym == XK_Escape)
		exit(1);

	mlx_put_image_to_window(data->mlx, data->win, data->img.img_ptr, 0, 0);
	return 0;
}

int	main()
{
	t_var	vars;

	vars.mlx = mlx_init();
	vars.win = mlx_new_window(vars.mlx, SIDE_LEN, SIDE_LEN, "My Window");

	vars.img.img_ptr = mlx_new_image(vars.mlx, SIDE_LEN, SIDE_LEN);
	vars.img.img_pixels_ptr = mlx_get_data_addr(vars.img.img_ptr, &vars.img.bits_per_pixel, &vars.img.endian);

	printf("Line_len %d <-> SIDE_LEN %d\n" "bpp %d\n" "endian %d\n", vars.img.line_len, SIDE_LEN, vars.img.bits_per_pixel, vars.img.endian);

	mlx_key_hook(vars.win, f, &vars);
	mlx_loop(vars.mlx);
}
