#include <unistd.h>

int	is_whitespace(char c)
{
	return (c == ' ' || c == '\t' || c == '\0');
}

/* TODO: - Proper comments */
void	epur_str(char *str)
{
	int	i = 0;
	int flag;

	while (is_whitespace(str[i]))
		i++;
	while (str[i])
	{
		if (is_whitespace(str[i]))
			flag = 1;
		if (!is_whitespace(str[i])) //if no whitespace we're at a word
		{
			if (flag) //if flag is 1 then it means we need to add a space
				write(1, " ", 1);
			flag = 0; //reset our flag
			write(1, &str[i], 1); //writes the string up until we hit more whitespace
		}
		i++;
	}
	write(1, "\n", 1);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		epur_str(argv[1]);
	write(1, "\n", 1);
	return (0);
}