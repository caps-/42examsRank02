#include <stdio.h>
#include <stdlib.h>

/* Using the division method to find the gcd, I think this is my fave and the
 * code is super simple and neat. We divide the larger number by the smaller
 * one, and if the remainder is 0 then the smaller number is the gcd. Otherwise
 * we go again, this time using the smaller number and the remainder. If our
 * numbers were 42 and 10, it would be:
 *
 * 42 / 10 = 4 mod 2
 * 10 / 2 = 5 mod 0
 * therefore the gcd = 2
 *
 * Code wise, it's a single while loop that loops as long as n1 / n2 has a
 * remainder other than 0. If n1 / n2 does give us a remainder we change n1's
 * value to smaller n2 value and then set n2 to be whatever the remainder
 * was. The while loop checks again to see if THAT gives us a remainder, and
 * just keeps repeating until we eventually do get a number with R 0. When that
 * happens n2 will be the greatest common denominator. */
void    pgcd(unsigned int n1, unsigned int n2)
{
    int temp;

    while ((temp = n1 % n2) != 0)
    {
        n1 = n2;
        n2 = temp;
    }
    printf("%d", n2);
}

int main(int argc, char **argv)
{
    if (argc == 3)
    {
        int n1 = atoi(argv[1]);
        int n2 = atoi(argv[2]);

        if (n1 > n2)
            pgcd(n1, n2);
        else
            pgcd(n2, n1);
    }
    printf("\n");
    return (0);
}