#include <string.h>

size_t	ft_strcspn(const char *s, const char *reject)
{
	int	i = 0;
	int	j;

	while (s[i])
	{
		j = 0; //init j here so we can move through reject each loop
		while (reject[j])
		{
			if (s[i] == reject[j])
				return (i);
			j++;
		}
		i++;
	}
	return (i);
}
/*
#include <stdio.h>

int	main(void)
{
	char	s01[] = "0123456789abcdef";
	char	s02[] = "gplxza";

	printf("strcspn   : %lu\n", strcspn(s01, s02));
	printf("ft_strcspn: %lu\n", ft_strcspn(s01, s02));

	return (0);
}*/