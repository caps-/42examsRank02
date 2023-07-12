#include <unistd.h>

int	main(int argc, char **argv)
{
	int	i = 0;
	int	start;
	int	end;

	if (argc == 2)
	{
		while (argv[1][i] != '\0')
			i++;
		while (i >= 0) //starting at the end of the string/word
		{
			while (argv[1][i] == '\0' || argv[1][i] == ' ' || argv[1][i] == '\t')
				i--; //move back one position to ignore whitespace at the very end
			end = i; //this i value will mark the end of the string/word
			while (argv[1][i] && argv[1][i] != ' ' && argv[1][i] != '\t')
				i--; //now we move back through the word
			start = i + 1; //this will mark the start of the word
			int	flag;
			flag = start;
			while (start <= end)
				write(1, &argv[1][start++], 1);
			if (flag != 0)
				write(1, " ", 1); //if not at the start we'll add space and do next word
		}
	}
	write(1, "\n", 1);
}
