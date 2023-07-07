#include <unistd.h>

/* About as simple as it can get. */
void    ft_putstr(char *str)
{
        while (*str)
                write(1, str++, 1);
}

/*
int     main(void)
{
        ft_putstr("test");
        return (0);
}
*/