#include <unistd.h>

/* Super easy to do. We move through the string, and any time we encounter a '_'
 * charcter we move one place ahead and change the letter to uppercase before
 * going ahead and writing out the rest of the string. */
void    snake_to_camel(char *s)
{
        int     i = 0;

        while (s[i])
        {
                if (s[i] == '_')
                {
                        i++;
                        s[i] -= 32;
                }
                write(1, &s[i++], 1);
        }
}

int     main(int argc, char **argv)
{
        if (argc == 2)
                snake_to_camel(argv[1]);
        write(1, "\n", 1);
        return (0);
}
