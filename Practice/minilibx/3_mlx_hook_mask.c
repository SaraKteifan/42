#include "minilibx-linux/mlx.h"
#include <X11/X.h>
#include <stdio.h>

#define WINDOW_WIDTH 800
#define WINDOW_HEIGHT 600

typedef struct s_data
{
	void	*mlx_ptr;
	void	*win_ptr;
}			t_data;

int	button_press(int button, int x, int y, t_data *data)
{
	if (button == 1)
		printf("Left mouse button pressed at (%d, %d)!", x, y);
	else if (button == 3)
		printf("Right mouse button pressed at (%d, %d)!", x, y);

	return (0);
}

int	main(void)
{
	t_data data;

	data.mlx_ptr = mlx_init();
	data.win_ptr = mlx_new_window(data.mlx_ptr, WINDOW_HEIGHT, WINDOW_WIDTH, "MLX Window");

	mlx_hook(data.win_ptr, ButtonPress, ButtonPressMask, &button_press, &data);

	mlx_loop(data.mlx_ptr);
}
