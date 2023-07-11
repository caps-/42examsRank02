/* The idea behind this function is to keep dividing n by 2 and seeing if we can
 * get get n down to 2. If we can (n / 2 being 1) then it means the number is a
 * power of 2. */
int	is_power_of_2(unsigned int n)
{
	if (n == 0)
		return (0);

	while (n % 2 == 0)
		n /= 2;
	return ((n == 1) ? 1 : 0);
}

/*
#include <stdio.h>
#include <stdlib.h>

int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		int	n = atoi(argv[1]);

		if (is_power_of_2(n))
			printf("%d is a power of 2.", n);
		else
			printf("%d is not a power of 2.", n);
	}
	printf("\n");
	return (0);
}
*/