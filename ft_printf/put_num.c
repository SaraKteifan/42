#include <unistd.h>
#include <limits.h>

int put_num(char *flags, int n)
{
    int count;
	char	res;

    count = 0;
    if (flags[0] != '\0')
        count += handle_flags(flags, 'i');
	if (n == INT_MIN)
	{
		write(1, "-2147483648", 11);
        count += 11;
		return (count);
	}
	if (n < 0)
	{
		write(1, "-", 1);
        count++;
		n = -n;
	}
	if (n < 10)
	{
		res = n + 48;
		write(1, &res, 1);
        count++;
	}
	else
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putnbr_fd(n % 10, fd);
	}
    return (count);
}