/* Most implimentations of this that I've seen, including anything I've managed
 * to come up with myself, have been a confusing, messy bunch of if and while 
 * argv[1][i] == or != whitespaces etc. Shit got ugly very quickly and was
 * cofusing and I lost track of shit fast. This is a much nicer solution that
 * is, imo, easier to follow. So here we go. */

#include <unistd.h>

int	ft_whitespace(char c)
{
	return (c == ' ' || c == '\t');
}

void	rostring(char *s)
{
	int	i = 0;
	int	first_word_length = 0;

	while (s[i])
	{
		while (ft_whitespace(s[i]))
			i++; //move past any whitespace at the start
		if (s[i] && !ft_whitespace(s[i]))
		{
			if (first_word_length == 0) //if we at the start of the first word
				while (s[i] && !ft_whitespace(s[i++])) //and its not whitespace
						first_word_length++; //get the length of the 1st word
			else
			{
				//this writes the rest of the string starting from the second 
                //word and then adds a space at the end ready for the
                //first word to be placed after it
				while (s[i] && !ft_whitespace(s[i]) && write(1, &s[i++], 1));
				write(1, " ", 1);
			}
		}
	}
	i = 0;
	while (ft_whitespace(s[i]))
		i++; //skip any extra whitepsce
	while (first_word_length--)
		write(1, &s[i++], 1); //then print the first word on the end!
}

int	main(int argc, char **argv)
{
	if (argc > 1 && argv[1])
		rostring(argv[1]);
	write(1, "\n", 1);
	return (0);
}

/* 
#include <unistd.h>

int	is_whitespace(char c)
{
	return (c == ' ' || c == '\t');
}

/* OK, here's how this works. It begins by moving past any whitespace at the
 * start and then moving through the first word, as well as marking the start
 * and end positions of it. Once that's done it can move on to the rest of the
 * string, working inside a while loop. Remember that each word must only be
 * seperated by ONE space, so that while condition on line xx actually checks to
 * see if there's more than one and moves through them, leaving only one space
 * before the next word. Next it prints */
 /*
void	rostring(char *str)
{
	int	i = 0;
	int word_start = 0;
	int	word_end = 0;
	int	flag = 0; //will mark where the first word needs to be moved to

	//Dealing with the first word.
	while (is_whitespace(str[i]))
		i++;
	word_start = i;
	while (str[i] && !is_whitespace(str[i]))
		i++;
	word_end = i;
	while (str[i] && is_whitespace(str[i]))
		i++;
	//Now for the rest of the stirng. Moves past whitespace, writes te
	while (str[i])
	{
		while (is_whitespace(str[i]) && is_whitespace(str[i + 1]))
			i++;
		if (is_whitespace(str[i]))
			flag = 1;
		write(1, &str[i], 1);
		i++;
	}
	//Deal with the last word.
	if (flag)
		write(1, " ", 1);
	while (word_start < word_end)
		write(1, &str[word_start++], 1);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		rostring(argv[1]);
	write(1, "\n", 1);
	return (0);
}
*/