char	*ft_strcpy(char *s1, char *s2)
{
	int	i;

	for(i = 0; s2[i] != '\0'; i++)
		s1[i] = s2[i];
	s1[i] = '\0';

	return (s1);
}

/*
#include <stdio.h>

int	main(void)
{
	char	s1[] = "string 1";
	char	s2[] = "string 2";

	printf("%s\n", s1);
	printf("%s\n", s2);
	ft_strcpy(s1, s2);
	printf("\n[ft_strcpy]\n\n");
	printf("%s\n", s1);
	printf("%s\n", s1);

	return (0);
}
*/