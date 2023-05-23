#include <stdlib.h>

/* Function to copy a string s2 to s1. Needs to know the length of the string
 * being copied. Pretty simple.*/
char *ft_strncpy(char *s1, char *s2, int n)
{
	int i = -1;

	while (++i < n && s2[i])
		s1[i] = s2[i];
	s1[i] = '\0';
	return (s1);
}

/* The start of the show, ft_split().*/
char	**ft_split(char *str)
{
	int i = 0;
	int j = 0;
	int k = 0;
	int wordcount = 0;

	//Count the words. Start by moving past any whitespace, when we encounter an
	//actual character it means we've hit the start of a word and we can increment
	//our wordcount. Then we move through the word until we stop seeing characters
	//and then go back to the start of the loop again to look for the next word,
	//repeating until we've found and counted up all of the individual words.
	while (str[i])
	{
		while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
			i++;
		if (str[i])
			wordcount++;
		while (str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'))
			i++;
	}

	//Initialize the array we're going to fill with words and return at the end.
	char **array = (char **)malloc(sizeof(char *) * (wordcount + 1));

	//Reset our counter.
	i = 0;

	//Now to fill the array up!
	while (str[i])
	{
		//We move past any whitespace.
		while (str[i] && (str[i] == ' ' || str[i] == '\t' || str[i] == '\n'))
			i++;
		//Set j to i in order to mark the start of a word.
		j = i;
		//Then move through the word itself.
		while (str[i] && (str[i] != ' ' && str[i] != '\t' && str[i] != '\n'))
			i++;
		//So now if i > j it means i is now at the end of the word. If we subtract
		//i from j we will have the word length as our result! Nice! Remember that
		//each time this while loop runs j will catch up to i, marking the start
		//of each new word, before i moves on again. When i stops getting bigger
		//than j it means we're at the last word.
		//
		//OK, we know that i - j is the word length, so we can use that to malloc
		//an array element to stick our word in, plus 1 at the the end for a null
		//terminator. We use our ft_strncpy() function to copy the current word
		//in to the current array element, again using i - j to tell us how many
		//characters we're copying.
		if (i > j)
		{
			array[k] = (char *)malloc(sizeof(char) * ((i - j) + 1));
			ft_strncpy(array[k++], &str[j], i - j);
		}
	}
	//Last array element is fuck all, then we return the filled array. Boom!
	array[k] = NULL;
	return (array);
}

/*
#include <stdio.h>

int	main(void)
{
	int		i = 0;
	char	**str = ft_split("         there's like five   words here!");
	while (i < 5)
	{
		printf("string 0%d: %s\n", (i + 1), str[i]);
		++i;
	}
	return (0);
}*/