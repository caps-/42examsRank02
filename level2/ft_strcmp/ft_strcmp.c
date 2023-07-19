/* We'll move through two strings as long as the characters are matching.
 * If/when they don't match we stop and return the value of the char from s1
 * subtracted from s2. */
int     ft_strcmp(char *s1, char *s2)
{
        int     i = 0;

        while (s1[i] && s2[i] && s1[i] == s2[i])
                i++;
        return (s1[i] - s2[i]);
}

/*
#include <stdio.h>
#include <string.h>

int     main(int argc, char **argv)
{
        if (argc == 3)
        {
                printf("----------------------------\n");
                printf("[strcmp]    %d\n", strcmp(argv[1], argv[2]));
                printf("[ft_strcmp] %d", ft_strcmp(argv[1], argv[2]));
        }
        printf("\n");
        return (0);
}
*/