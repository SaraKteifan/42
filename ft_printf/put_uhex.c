#include "ft_printf.h"

int	put_uhex(unsigned int n)
{
	int		count;
	char	*hex;

	count = 0;
	hex = "0123456789ABCDEF";
	if (n < 16)
		count += put_char(hex[n]);
	else
	{
		count += put_uhex(n / 16);
		count += put_uhex(n % 16);
	}
	return (count);
}
