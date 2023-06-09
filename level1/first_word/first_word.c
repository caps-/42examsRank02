#include <unistd.h>

/* Only thing I'll point out about this is to not forget to add the extra s[i]
 * at the end of the while condition on line 12, otherwise in certain cases
 * like giving it a string with nothing but spaces it'll spit out nonsense. */
void	first_word(char *s)
{
	int	i = 0;

	while (s[i] == ' ' || s[i] == '\t')
		i++;
	while ((s[i] != ' ' && s[i] != '\t') && s[i])
		write(1, &s[i++], 1);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		first_word(argv[1]);
	write(1, "\n", 1);
	return (0);
}
