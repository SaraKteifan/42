#include "fractol.h"

int	main(int ac, char **av)
{
	t_fractal	fractal;
	
	if (2 == ac && !ft_strncmp(av[1], "mandelbrot", 10) || 4 == ac && !ft_strncmp(av[1], "julia", 5))
	{

	}
	else
	{
		putstr_fd(ERROR_MESSAGE, STDERR_FILENO);
		exit(EXIT_FAILURE);
	}
}
