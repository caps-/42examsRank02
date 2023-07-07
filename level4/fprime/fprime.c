#include <stdio.h>
#include <stdlib.h>

/* We're using the division method here. Keep dividing n by increments of i 
 * until we're able to get an answer without a remainder, meaning we've got a 
 * prime number. Print that and the * char, divide n by i, and then reset i to 
 * 1 so we can do the while while loop again with the new value of n. Eventuall
 * we're going to get to a point where i is the same value as n, meaning we've
 * found the last prime factor and we can exit the loop without printing
 * another * character on the end. */

void	fprime(int n)
{
	int	i = 1;

	if (n == 1)
		printf("1");
  
	while (n >= i++)
	{
		if (n % i == 0)
		{
			printf("%d", i);
			if (i == n)
				break;
			printf("*");
			n /= i;  
			i = 1;
		}
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		fprime(atoi(argv[1]));
	printf("\n");
	return (0);
}
