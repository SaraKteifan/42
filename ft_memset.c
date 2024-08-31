#include <stdio.h>

void    *ft_memset(void *s, int c, size_t n)
{
        char    *ptr;
        size_t  i;

        ptr = s;
        i = 0;
        while (i < n)
        {
                ptr[i] = (char)c;
                i++;
        }
        return (s);
}