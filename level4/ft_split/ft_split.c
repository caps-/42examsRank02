/* Third version of this, I've split up a bunch of shit into their own seperate
 * functions cause I think it makes the code for ft_split() neater and easier to
 * follow. */
#include <stdlib.h>

/* Checks for whitespace. */
int	is_whitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n');
}

/* Gets a wordcount for a string. */
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

/* My own implementation of strncpy(). Copies n characters of s2 in to s1 and
 * returns it. */
char	ft_strncpy(char *s1, char *s2, int n)
{
	int	i = -1;

	while (++i < n && s2[i])
		s1[i] = s2[i];
	s1[i] = '\0';
	return (i);
}

/* The star of the show. */
char	**ft_split(char *str)
{
	int		i = 0;
	int		j = 0;
	int		k = 0;
	int		wc = wordcount(str);
	char	**array = malloc(sizeof(char *) * (wc + 1));

	while (str[i])
	{
		//We'll start by moving past any leading whitespace, when we're no
		//longer seeing any it means i has reached the beginning of a word.
		//We'll copy the value of i in to j, then move i along until it reaches
		//the end of the word.
		while (str[i] && is_whitespace(str[i]))
			i++;
		j = i;
		while (str[i] && !is_whitespace(str[i]))
			i++;
		//If i is greater than j it means i is now at the end of the word, and
		//subtracting i from j will give us that words length. Remember that
		//each time this while loop runs j will catch up to i, marking the start
		//of the next word before i moves on again. When i stops getting bigger
		//than j it means we're at the last word.
		if (i > j)
		{
			//OK, so we know that i - j is the word length, so we can use that
			//to malloc an array element to stick our word into, plus 1 at the
			//end for a null terminator. We use our ft_strncpy() function to
			//copy the current word in to the array, again using i - j to tell
			//the function how many characters we're copying.
			array[k] = malloc(sizeof(char) * ((i - j) + 1));
			ft_strncpy(array[k++], &str[j], i - j);
		}
	}
	//Last element in the array is nulled and we return that shit, b00m!
	array[k] = NULL;
	return (array);
}
/*
#include <stdio.h>

int	main(void)
{
	char	**str = ft_split("	there's like    five words  	here");

	printf("----------------------------------------\n");
	for (int i = 0; i < 5; i++)
		printf("String 0%d: %s\n", i + 1, str[i]);
	return (0);
}*/