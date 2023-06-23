#include <stdlib.h>

int	*ft_rrange(int start, int end)
{
	int	i = 0;
	int	n = end - start + 1; //this gives us the number of numbers the range has
	int	*array;

	if (start > end)
		return (ft_rrange(end, start)); //swap em if start > end

	array = malloc(sizeof(int) * n); //no need to cast
	if (array)
	{
		while (i < n)
		{
			array[i] = end; //fill the array element
			end--; //decrement the number
			i++; //go to the next element
		}
	}
	return (array); //return the filled array!
}
/*
#include <stdio.h>

int	main(void)
{
	int	i = 0;
	int	*array  = ft_rrange(-2, 7);

	while (i <= 9)
	{
		printf("%d, ", array[i]);
		i++;
	}
	printf("\n");
	return (0);
}*/
