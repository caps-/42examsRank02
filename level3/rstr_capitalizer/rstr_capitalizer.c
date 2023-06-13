#include <unistd.h>

/* No need to actually make this into it's own function, I just did it cause I
 * think it makes the code in rstr_capitalizer() a little cleaner. */
int	is_whitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\0');
}

/* Just move through the string and convert any uppercase chars to lowercase,
 * and if it's a lowercase char with whitespace or a null terminator after it
 * convert it to uppercase. Pretty simple. */
void	rstr_capitalizer(char *str)
{
	int	i = 0;

	while (str[i])
	{
		if (str[i] >= 'A' && str[i] <= 'Z')
			str[i] += 32;
		if ((str[i] >= 'a' && str[i] <= 'z') && is_whitespace(str[i + 1]))
			str[i] -= 32;
		write(1, &str[i++], 1);
	}
}

int	main(int argc, char **argv)
{
	if (argc == 1)
		write(1, "\n", 1);
	else
	{
		int i = 1; //init to 1 not 0 to avoid printing the executable name too

		while (i < argc)
		{
			rstr_capitalizer(argv[i]);
			write(1, "\n", 1);
			i++;
		}
	}
	return (0);
}