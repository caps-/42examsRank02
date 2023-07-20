/* Right, so let's take the first character we're passing to this function from
 * the main, 't'. The function takes a char which is 8 bits or one byte and
 * swaps the two halves of the byte around (first four and last four bits).
 * In this case 't' becomes 'G':
 *
 * 		t = 0111 0100
 * 		G = 0100 0111
 *
 * So here's how we do it. Right shifting by 4:
 *
 * 		t = 0111 0100
 *   >> 4 = 0000 0111
 *
 * If we shift left by 4 we get:
 * 		t = 0111 0100
 *   << 4 = 0100 0000
 *
 * If we use those with an OR operator the following happens:
 *
 *		0000 0111
 *	  | 0100 0000
 *	    ---------
 *		0100 0111
 *
 * Boom! We've just swapped the bits around, and in this case the result is the
 * binary value for 'G'! */
unsigned char	swap_bits(unsigned char octet)
{
	return (octet >> 4 | octet << 4);
}
/*
#include <stdio.h>

int     main(void)
{
        printf("-----------------------\n");
        printf("t after bit swap becomes %c\n", swap_bits('t'));
        printf("G after bit swap becomes %c\n", swap_bits('G'));
}
*/
