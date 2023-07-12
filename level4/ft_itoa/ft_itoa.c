/* Converts an integer into a string. Actually not a lot to this, we just get
 * the length the string needs to be and allocate mem for it and then fill it up
 * accordingly. The actual conversion from a single digit int to a char is super
 * easy, it's literally just the int + 48. */

#include <stdlib.h>

char	*ft_itoa(int nbr)
{
	int		n = nbr;
	int		len = 0;
	char	*result;

	if (nbr <= 0)
	{
		len++; //makes room for a - sign
	}
	while (n)
	{
		n /= 10;
		len++; //gets us the length/number of digits
	}
	result = malloc(sizeof(char *) * (len + 1));
	if (result == NULL)
		return (NULL);
	result[len] = '\0'; //adds the null terminator on the end of the string
	if (nbr == 0)
	{
		result[0] = '0'; //gotta do this here, won't work in the main while loop below
		return (result);
	}
	if (nbr < 0)
	{
		result[0] = '-'; //stick the - sign at the start of the string
		nbr *= -1;
	}
	while (nbr)
	{
		result[--len] = nbr % 10 + 48; //put the char in the string
		nbr /= 10; //go to the next digit
	}
	return (result); //boom ting!
}

/*
#include <stdio.h>

int	main(void)
{
	char	*s1 = ft_itoa(9823);
	char	*s2 = ft_itoa(-321);
	char	*s3 = ft_itoa(0);

	printf("------------\n");
	printf("%s, %s, %s\n", s1, s2, s3);
	return (0);
}
*/