/* Pretty simple. Get the length of the string so we can allocate the right
 * amount of memory to copy the string in to. Copy the shits over, stick a null
 * terminator on the end and return the duplicated string.*/

#include <stdlib.h>

char	*ft_strdup(char *src)
{
	int		i = 0;
	int		length = 0;
	char	*duplicate;

	while (src[length++]);
	duplicate = malloc(sizeof(char) * (length + 1));

	if (duplicate != NULL)
	{
		while (src[i])
		{
			duplicate[i] = src[i];
			i++;
		}
		duplicate[i] = '\0';
	}
	return (duplicate);
}

/*
#include <stdio.h>
#include <string.h>

int	main(void)
{
	char	*s1 = "test";
	char	*s2 = strdup(s1);
	char	*s3 = ft_strdup(s1);

	printf("---------------\n");
	printf("Original : %s\n", s1);
	printf("strdup   : %s\n", s2);
	printf("ft_strdup: %s\n", s3);
	return (0);
}
*/