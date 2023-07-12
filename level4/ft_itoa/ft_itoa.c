#include <stdlib.h>

char	*ft_itoa(int nbr)
{
	int		n = nbr;
	int		len = 0;
	char	*result;

	if (nbr <= 0)
	{
		len++;
	}
	while (n)
	{
		n /= 10;
		len++;
	}
	result = (char *)malloc(sizeof(char *) * (len + 1));
	if (result == NULL)
		return (NULL);
	result[len] = '\0';
	if (nbr == 0)
	{
		result[0] = '0';
		return (result);
	}
	if (nbr < 0)
	{
		result[0] = '-';
		nbr *= -1;
	}
	while (nbr)
	{
		result[--len] = nbr % 10 + 48;
		nbr /= 10;
	}
	return (result);
}

/*
#include <stdio.h>

int	main(void)
{
	char	*s1 = ft_itoa(9823);
	char	*s2 = ft_itoa(-321);

	printf("----------\n");
	printf("%s, %s\n", s1, s2);
	return (0);
}
*/