/* Pretty simple stuff, the only thing to remember is in the if function in
 * main. Make sure you do != argv[2][1] and != argv[3][1] so the program won't
 * accept anything other than a single character for those arguments. The
 * instructions don't explicitly state it, but if you look at the example
 * outputs then passing a whole word as the second and/or third argument should
 * result in the program printing nothing other than \n. */

#include <unistd.h>

void	search_and_replace(char *str, char c1, char c2)
{
	int	i = 0;

	while (str[i] != '\0')
	{
		if (str[i] == c1)
			str[i] = c2;
		write(1, &str[i], 1);
		i++;
	}
}

int	main(int argc, char **argv)
{
	if (argc == 4 && !argv[2][1] && !argv[3][1])
		search_and_replace(argv[1], argv[2][0], argv[3][0]);
	write(1, "\n", 1);
	return (0);
}