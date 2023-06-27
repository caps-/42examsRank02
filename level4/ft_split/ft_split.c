#include <stdlib.h>

/* Check to see if the current character is whitespace*/
int	is_whitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

/* Returns the number of words in a string. */
int	wordcount(char *str)
{
	int	i = 0;
	int	count = 0;

	while (str[i])
	{
		while (str[i] && is_whitespace(str[i]))
			i++;
		if (str[i])
			count++;
		while (str[i] && !is_whitespace(str[i]))
			i++;
	}
	return (count);
}

/* Copies n characters from src over to dst and returns it. */
char	*ft_strcpy(char *src, char *dst, int n)
{
	int i = -1;

	while (++i < n && src[i])
		dst[i] = src[i];
	dst[i] = '\0';
	return (s1);
}

/* It's all about that main while loop. Our i variable moves past any whitespace
 * until we hit a letter/number/whatever , which means we're at the start of a
 * word. We'll copy the value of i in to j and then move i along again until it
 * reaches the end of the word. If i is now greater than j it means we got a
 * word ready to stick in our array, and if we subtract i from j we'll also get
 * the length of that word. Remember that each time this while loop runs j will
 * catch up to i, so it'll keep going to the start of each word. Once i stops
 * getting bigger than j it means we're at the last word. */
char	**ft_split(char *str)
{
	int		i = 0;
	int		j = 0;
	int		k = 0;
	int		wc = wordcount(str);
	char	**array = malloc(sizeof(char *) * (wc + 1));

	while (str[i])
	{
		while (str[i] && is_whitespace(str[i]))
			i++;
		j = i;
		while (str[i] && !is_whitespace(str[i]))
			i++;
		if (i > j)
		{
			array[k] = malloc(sizeof(char *) * ((i - j) + 1));
			ft_strcpy(&str[j], array[k++], i - j);
		}
	}
	array[k] = NULL;
	return (array);
}

/*
#include <stdio.h>

int	main(void)
{
	char	**str = ft_split("	there's like       5 	words      here");

	printf("-------------------\n");
	for (int i = 0; i < 5; i++)
		printf("String 0%d: %s\n", i + 1, str[i]);
	return (0);
}
*/