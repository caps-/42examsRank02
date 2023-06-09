#include <unistd.h>

/* Just some simple arithmetic using ASCII values, that's all it needs. */
void	alpha_mirror(char *s)
{
	int	i = 0;
	while (s[i])
	{
		if (s[i] >= 'A' && s[i] <= 'Z')
		{
			s[i] = 'Z' - s[i] + 'A';
		}
		else if (s[i] >= 'a' && s[i] <= 'z')
		{
			s[i] = 'z' - s[i] + 'a';
		}
		write(1, &s[i++], 1);
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		alpha_mirror(argv[1]);
	write(1, "\n", 1);
	return (0);
}
