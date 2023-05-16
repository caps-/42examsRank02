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