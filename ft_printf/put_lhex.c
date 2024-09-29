#include "ft_printf.h"

int	put_lhex(unsigned int n)
{
	int		count;
	char	*hex;

	count = 0;
	hex = "0123456789abcdef";
	if (n < 16)
		count += put_char(hex[n]);
	else
	{
		count += put_lhex(n / 16);
		count += put_lhex(n % 16);
	}
	return (count);
}
