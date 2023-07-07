/* I'll just explain the actual char to int conversion here which happens during
 * the while loop, and we'll pretend we the string is the characters "57".
 *
 * To start off, let's look at the right hand side of that expression and break
 * it down in to two parts before we move on. Because this is the first
 * iteration of the while loop, the 'number' variable is still set to 0. Doing
 * 0 x 10 give us 0. We're also taking the current character "5", which has an
 * ASCII value of 53, and subtracting 48 from that. So 53 - 48 = 5. That integer
 * value of 5 is now stored in the 'number' variable. Cool. We increment along
 * to the next position in the string, which in this case is "7". We do the same
 * thing to that "7" character that we did before, giving us an int value of 3,
 * but now the 'number' variable is 5, which gets multiplied by 10 to give us
 * 50. So what we're doing this time round is actually adding 50 + 7 and
 * sticking THAT in our 'number variable, which if we return it gives the
 * integer value of 57! */

int     ft_atoi(const char *str)
{
        int     sign = 1;
        int     result = 0;

        while (*str <= 32)
                str++;
        if (*str == '-')
                sign = -1;
        if (*str == '-' || *str == '+')
                str++;
        while (*str >= '0' && *str <= '9')
        {
                result = result * 10 + *str - 48;
                str++;
        }
        return (sign * result);
}

/*
#include <stdio.h>

int     main(void)
{
        printf("%d\n", ft_atoi("42"));
        printf("%d\n", ft_atoi("-4242"));
        return (0);
}
*/