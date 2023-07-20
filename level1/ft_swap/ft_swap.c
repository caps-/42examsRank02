/* Third variables are for suckers. */
void	ft_swap(int *a, int *b)
{
	*a = *a + *b;
	*b = *a - *b;
	*a = *a - *b;
}

/*
#include <stdio.h>

int	main(void)
{
	int	a = 15;
	int	b = 2;

	printf("------------------\n");
	printf("%d, %d\n", a, b);
	ft_swap(&a, &b);
	printf("[SWAPPED]\n%d, %d\n", a, b);
	return (0);
}
*/
