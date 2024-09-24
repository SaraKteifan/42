#include "ft_printf.h"

int in_set(const char *set, char c)
{
        int i;

        i = 0;
        while (set[i] != '\0')
        {
                if(set[i] == c)
                        return (1);
                i++;
        }
        return (0);
}

char *flags_set(char *s)
{
        int i;
        int j;
        char *flags;

        i = 0;
        j = 0;
        while (!in_set("cspdiuxX%", s[i]))
        {
                flags[j++] = s[i++];
        }
        flags[j] = '\0';
        return (flags);
}

int ft_printf(const char *s, ...)
{
        int i;
        int count;
        va_list ap;
        char *flags;

        i = 0;
        va_start(ap, s);
        while (s[i] != '\0')
        {
                if (s[i] == '%')
                {
                        flags = flags_set(&s[++i]);
                }
                else
                        count += put_char(s[i++]);
        }
        va_end(ap);
        return(count);
}