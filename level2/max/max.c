#include <stdio.h>

/* Just check to see if result is less than the next numberin the array. If it is
 * then the next number is obviously bigger so we set the result to that and
 * then compare it again to the next number, blah blah blah keep looping until
 * we've checked em all and then return the final result. */
int	max(int *tab, unsigned int len)
{
        int     result = tab[len];

        while (len-- > 0)
        {
                if (result < tab[len])
                        result = tab[len];
        }
        return (result);
}

/*
#include <stdio.h>

int     main(void)
{
        int     tab[8] = {1, 8, 16, 0, 64, 3, 52, 5};

        printf("%d\n", max(tab, 8));
        return (0);
}
