#include "ft_printf.h"
#include <stdio.h>
#include <limits.h>

int	main()
{
	int	a;
	int	b;

	printf("libc's: ");
	a = printf("%d%d%d%d%d%d%d\n", 1,2,3,4,5,6,7);
	ft_printf("Sara's: ");
	b = ft_printf("%d%d%d%d%d%d%d\n", 1,2,3,4,5,6,7);
	printf("a: %i, b: %i\n", a, b);

}
