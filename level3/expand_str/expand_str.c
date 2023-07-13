#include <unistd.h>

int	is_whitespace(char c)
{
	return (c == ' ' || c == '\t');
}

/* Going through the string and actually doing it character by character. Not
 * much to say here, the code should be pretty self explanatory. */
void	expand_str(char *str)
{
	int	i = 0;
	int	flag = 0;

	//move past any leading whitespace
	while (is_whitespace(str[i]))
		i++;
	//go from the first word
	while (str[i])
	{
		if (is_whitespace(str[i]))
			flag = 1;
		if (!is_whitespace(str[i]))
		{
			if (flag)
			{
				write(1, "   ", 3);
				flag = 0;
			}
			write(1, &str[i], 1);
		}
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		expand_str(argv[1]);
	write(1, "\n", 1);
	return (0);
}
