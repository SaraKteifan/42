#include <unistd.h>

int put_char(char *flags, char c)
{
    int count;

    count = 1;
    if (flags[0] != '\0')
        count += handle_flags(flags, 'c');
    write(1, &c, 1);
    return (count);
}