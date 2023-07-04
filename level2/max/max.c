#include <stdio.h>

/* Just check to see if result is less than the next numberin the array. If it is
 * then the next number is obviously bigger so we set the result to that and
 * then compare it again to the next number, blah blah blah keep looping until
 * we've checked em all and then return the final result. */
int	max(int *tab, unsigned int len)
{
	unsigned int	i = 0;
	int				result = tab[i];

	while (i++ < len)
	{
		if (result < tab[i])
		{
			result = tab[i];
		}
	}
	return (result);
}

/*
int	main(void)
{
	int	n[] = {8593, 48954382, 694, -89456245};

	printf("--------------------\n");
	printf("%d\n", max(n, 4));
	return (0);
}
*/