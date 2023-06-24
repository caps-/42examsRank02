#include <unistd.h>

void	last_word(char *str)
{
	int	i = 0;
	int	j = 0;

	//This basically sas if there's a space with an alphanumeric character afer
	//it then it must be the start of a new word. We mark the start of that word
	//by storing the value of i + 1 (+ 1 to skip that whitespace) and then
	//incrementing i until we hit the start of the next word. The loop keeps
	//going until we hit the last one.
	while (str[i])
	{
		if (str[i] == ' ' && str[i + 1] >= 33 && str[i + 1] <= 126)
			j = i + 1;
		i++;
	}
	//Then we write it!
	while (str[j] >= 33 && str[j] <= 126)
	{
		write(1, &str[j++], 1);
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		last_word(argv[1]);
	write(1, "\n", 1);
	return (0);
}
