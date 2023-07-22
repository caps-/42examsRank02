/* Some bitwise stuff fi dem. For each bit we right shift octet and then do a
 * bitwise AND operation on it with whatever value i currently has. Quick,
 * handwavy reminder of how the & operator works:
 *
 * It takes two numbers, compares the bits of each one and then returns 1 if the
 * corresponding bits are both 1. So for example:
 *
 *   0101 (int 5)
 * & 0011 (int 3)
 *   ----
 * = 0001 (int 1)
 *
 *  So an unsigned char has 8 bits, so we need to do that 8 times with
 *  decerementing values of i, getting 1 or 0 as a resulit. This will actually
 *  end up being the order of bits that we need to make the binary 
 *  representation of the number we've given to the function! Adding 48 just
 *  gives us the right ascii value to print. */

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
