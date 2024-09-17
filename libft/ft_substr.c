#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

char *ft_substr(char const *s, unsigned int start, size_t len)
{
        size_t i;
        char *sub;

        i = 0;
        if (start > ft_strlen(s))
            return (NULL);
        sub = malloc(len + 1);
        if (!sub)
            return (NULL);
        while (i < len && s[start] != '\0')
        {
                sub[i] = s[start];
                i++;
                start++;
        }
        sub[len] = '\0';
        return (sub);
} 