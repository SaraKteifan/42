#include <stdlib.h>
#include <limits.h>
#include "libft.h"

void *ft_calloc(size_t nmemb, size_t size)
{
        void *ptr;

        if (nmemb == 0 || size == 0 || (nmemb > SIZE_MAX / size))
                return (NULL);
        ptr = malloc(nmemb * size);
        if(!ptr)
                return (NULL);
        ft_memset(ptr, 0, nmemb * size);
        return (ptr);
}