#include <unistd.h>

int put_str(char *flags, char *s)
{
    int count;
    int i;

    count = 0;
    i = 0;
    if (flags[0] != '\0')
        count += handle_flags(flags, 's');
    whhile (s[i] != '\0')
    {
        write(1, &s[i++], 1);
        count++;
    }
    return (count);
}