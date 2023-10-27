#include <unistd.h>

int	is_whitespace(char c)
{
	return (c == ' ' || c == '\t');
}

/* Start out by checking if the first character in the string is lowercase, if
 * it is we convert it to uppercase and write it and then move on to the rest.
 * We know that the start of any successive new word will have whitespace before
 * it, so we just change all uppercase letters to lowercase and then if a
 * lowercase letter does happen to have whitespace before it we change it to
 * uppercase. Boom, done. */

void	str_capitalizer(char *str)
{
	int	i = 0;

	if (str[i] >= 'a' && str[i] <= 'z')
		str[i] -= 32;
	write(1, &str[i], 1);
	while (str[++i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		if ((str[i] >= 'a' && str[i] <= 'z') && is_whitespace(str[i - 1]))
			str[i] -= 32;
		write(1, &str[i], 1);
	}
}

int main(int argc, char **argv)
{
	if (argc == 1)
		write(1, "\n", 1);
	else if (argc > 1)
	{
		for (int i = 1; i < argc; i++)
		{
			str_capitalizer(argv[i]);
			write(1, "\n", 1);
		}
	}
	return (0);
}
