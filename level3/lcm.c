/* Takes two unsigned ints as params and returns the lowest common multiple,
 * the smallest positive integer that is divisible by a and b. If at least one
 * integer is 0/null then the LCM is 0.
 * 
 * If a is 10 and b is 15 then the LCM would be 30. Get it? Cool.
 *
 * So basically we figure out which number is bigger, a or b, and then give n
 * that value. Why? Because the lcm must be at least whatever the highest value
 * is that we passed to the function. Yeah? Then we just in to a recursive loop
 * that checks to see if the remainder of n divided by both a and b is zero. If
 * it is, it means we've found the lowest common multiple! If not we increment n
 * by 1 and then repeat the loop. */
unsigned int	lcm(unsigned int a, unsigned int b)
{
	unsigned int	n;

	if (a == 0 || b == 0)
		return (0);
	if (a > b)
		n = a;
	else
		n = b;
	while (1) // just makes this loop keep looping
	{
		if (n % a == 0 && n % b == 0)
			return (n);
		++n;
	}
}

/* Main function, don't include this in the actual exam! */
#include <stdio.h>

int	main(void)
{
	unsigned int	a = 10;
	unsigned int	b = 15;

	printf("%d\n", lcm(a, b));
			return (0);
}
