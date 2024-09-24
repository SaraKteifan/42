#include "ft_printf.h"

int handle_format_string(const char *s)
{
    int i;

    i = 0;
    while (s[i] != '\0')
    {
        if (s[i] == '%')
        {
            get_format_specifier(&s[i]);
        }
        else
            
    }
}

int ft_printf(const char *format_string, ...)
{
    if (!format_string)
        return (0);
    else
        handle_format_string(format_string);
}