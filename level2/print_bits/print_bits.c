#include <unistd.h>

void	print_bits(unsigned char octet)
{
	int				i = 8;
	unsigned char	bit;

	while (i--)
	{
		bit = ((octet >> i & 1) + 48);
		write(1, &bit, 1);
	}
}

/*
#include <stdlib.h>

int	main(int argc, char **argv)
{
	if (argc == 2)
		print_bits(atoi(argv[1]));
	write(1, "\n", 1);
	return (0);
}
*/
