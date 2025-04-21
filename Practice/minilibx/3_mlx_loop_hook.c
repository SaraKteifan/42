#include "minilibx-linux/mlx.h"
#include <stdio.h>
#include <unistd.h>

typedef struct s_data
{
	void	*mlx;
	void	*win;
	int		color;
}			t_data;

int	f(int keysym, t_data *data)
{
	printf("Pressed %d\n", keysym);
	sleep(1);
	return 1;
}

int	change_color(t_data *data)
{
	mlx_string_put(data->mlx, data->win, 150, 150, data->color, "Color Changing Window!");

	if (data->color == 0xFF0000)
		data->color = 0x00FF00;
	else if (data->color == 0x00FF00)
		data->color = 0x0000FF;
	else
		data->color = 0xFF0000;
	return (0);
}

int	main(void)
{
	t_data	data;

	data.mlx = mlx_init();
	data.win = mlx_new_window(data.mlx, 400, 400, "Sample Window");
	data.color = 0xFF0000;

	mlx_key_hook(data.win, f, &data);

	mlx_loop_hook(data.mlx, change_color, &data);

	mlx_loop(data.mlx);
	return (0);
}
