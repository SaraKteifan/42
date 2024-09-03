#include <stddef.h>
#include <stdlib.h>
#include "libft.h"

char *ft_strjoin(char const *s1, char const *s2)
{
        size_t  i;
        size_t  j;
        size_t  k;                                                                                                              char *joined;                                                                                                                                                                                                                                   i = ft_strlen(s1);                                                                                                      j = ft_strlen(s2);                                                                                                      joined = malloc(i + j + 1);                                                                                             k = 0;
        while (k < i)
        {                                                                                                                               joined[k] = s1[k];
                k++;
        }
        while (k < i + j)
        {
                joined[k] = s2[k - i];
                k++;
        }
        joined[i + j] = '\0';
        return (joined);
}   