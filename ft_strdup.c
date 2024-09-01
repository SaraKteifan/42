#include <stdlib.h>
#include <stddef.h>
#include "libft.h"

char *ft_strdup(const char *s)
{
        size_t i;
        size_t j;
        char *str;

        i = ft_strlen(s);
        str = malloc(i);
        if(!str)
            return (NULL);
        j = 0;
        while (j < i)
        {
                str[j] = s[j];
                j++;
        }
        return (str);
}  