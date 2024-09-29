#include "ft_printf.h"

int	put_ptr(void *ptr)
{
	int	count;

	count = 0;
	if (ptr == NULL)
	{
		count += put_str("(nil)");
		return (count);
	}
	count += put_str("0x");
	count += put_lhex(ptr);
	return (count);
}
