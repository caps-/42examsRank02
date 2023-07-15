#include <stdlib.h>


/* Throwing my own implementation of abs() because I don't think we're allowed
 * to use it in this exercise? If it's a negative number then returning -n will
 * return it as a positive one because maths. */
int	ft_abs(int n)
{
	return ((n < 0) ? -n : n);
}

/* Another one where the code should be prett self explanatory. Using the
 * absolute value of end - start + 1 for the length. */
int	*ft_range(int start, int end)
{
	int	i = 0;
	int	length = ft_abs(end - start) + 1;
	int	*range = malloc(sizeof(int) * length);

	while (i < length)
	{
		if (start < end)
		{
			range[i] = start;
			start++;
			i++;
		}
		else
		{
			range[i] = start;
			start--;
			i++;
		}
	}
	return (range);
}

/*
#include <stdio.h>

void	print_range(int start, int end)
{
	int i = 0;
	int	length = ft_abs(end - start) + 1;
	int	*range = ft_range(start, end);

	printf ("[");
	while (i <= length)
	{
		printf("%d", range[i]);
		if (i == length - 1)
		{
			printf("]");
			break;
		}
		printf(", ");
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 3)
		print_range(atoi(argv[1]), atoi(argv[2]));
	printf("\n");
	return (0);
}
*/
