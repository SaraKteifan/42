int     atoi(const char *nptr)
{
        int     i;
        int     res;
        int     sign;

        i = 0;
        res = 0;
        sign = 1;

        while (nptr[i] == 32 || (nptr[i] >= 9 && nptr[i] <= 13))
                i++;

        if (nptr[i] == '-')
        {
                sign *= -1;
                i++;
        }

        while (nptr[i] >= '0' && nptr[i] <= '9')
        {
                res *= 10;
                res += nptr[i] - 48;
                i++;
        }
        return (res * sign);
}