#include <unistd.h>

/* Check to see if the ith and jth position match. If they do both move forward
 * one place. If they don't match we move to the next position in s2 and see if
 * we have a match there. This just keeps going until we get to the end of both
 * strings. After that's done, if we find a null terminator at the current
 * position in s1 it means it managed to find the string hidden inside s2, so we
 * write 1 to the output. Otherwise it's not a match and we write 0. */
void	hidenp(char *s1, char *s2)
{
	int	i = 0;
	int	j = 0;

	while (s1[i] && s2[j])
	{
		if (s2[j] == s1[i])
			i++;
		j++;
	}
	if (s1[i] == '\0')
		write(1, "1", 1);
	else
		write(1, "0", 1);
}

int	main(int argc, char **argv)
{
	if (argc == 3)
		hidenp(argv[1], argv[2]);
	write(1, "\n", 1);
	return (0);
}