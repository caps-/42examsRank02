/* OK, so we'll need a few steps to split a string in to words and return them
 * as a null terminated  array of strings. In no particular order:
 *
 * 1 - Count the number of individual words in the string that was passed.
 * 2 - Find and duplicate each word to put in to the array
 * 3 - Find the length of each individual word.
 * 4 - Fill the array. */

#include <stdlib.h>

/* Counts the words in a string. If skips past any whitepsace at the start, and
 * then moves along through the characters, then any whitespace after. If it
 * finds whitepace after finding characters it means we're at the end of a word
 * and the counter increments accordingly. */
int	count_words(char *str)
{
	int	wordcount = 0;

	while (*str == ' ' || *str == '\t' || *str == '\n')
		str++;
	while (*str != '\0')
	{
		++wordcount;
		while (*str != '\0' && *str != ' ' && *str != '\t' && *str != '\n')
			++str;
		while (*str == ' ' || *str == '\t' || *str == '\n')
			++str;
	}
	return (wordcount);
}

/* Find and return the length of a word. Easy. */
int	ft_wordlen(char *str)
{
	int	i = 0;

	while (str[i] != '\0' && str[i] != ' ' && str[i] != '\t' && str[i] != '\n')
		i++;
	return (i);
}

/* Duplicate a word. Gets the length of the str, adds a null terminator at the
 * end and then copies str to word.*/
char	*duplicate_word(char *str)
{
	int		i = 0;
	int		len = ft_wordlen(str);
	char	*word = malloc(sizeof(char) * (len + 1));

	word[len] = '\0';
	while (i < len)
	{
		word[i] = str[i];
		++i;
	}
	return (word);
}

/* */
void	fill_array(char **array, char *str)
{
	int	word_index = 0;

	while (*str == ' ' || *str == '\t' || *str == '\n')
		++str; //ignore whitespace and move to first word
	while (*str != '\0')
	{
		array[word_index] = duplicate_word(str); //put dupe in current index
		++word_index; //move to next index in array
		while (*str != '\0' && *str != ' ' && *str != '\t' && *str != '\n')
			++str; //move through word
		while (*str == ' ' || *str == '\t' || *str == '\n')
			++str; //move on to next word and repeat loop
	}
}

/* */
char	**ft_split(char *str)
{
	int		wordcount;
	char	**array;

	wordcount = count_words(str);
	array = malloc(sizeof(char *) * (wordcount + 1));

	array[wordcount] = 0;
	fill_array(array, str);
	return (array);
}

/*
#include <stdio.h>

int	main(void)
{
	int		i = 0;
	char	**str;

	str = ft_split("         there's like five   words here!");
	while (i < 5)
	{
		printf("string %d: %s\n", (i + 1), str[i]);
		++i;
	}
	return (0);
}*/
