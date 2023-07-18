#include <unistd.h>

/* Function to write numbers to the output. */
void	ft_putnbr(int n)
{
	char	number[10] = "0123456789";

	if (n > 9)
		ft_putnbr(n / 10);
	write(1, &number[n % 10], 1);
}

/* An implementation of the atoi function. */
int	ft_atoi(char *str)
{
	int result = 0;
	int sign = 1;

	while (*str == ' ' || (*str >= 9 && *str <= 13))
        	str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		result = result * 10 + *str - '0';
		str++;
	}
	return (sign * result);
}

/* Much nicer (imo) function to check if a number is prime using the square root
 * method. */
int	is_prime(int n)
{
	//Is the number 1? Or even worse, negative? Sorry, not a prime!
	if (n < 2)
		return (0);
	//I won't go in to all of the maths here, but basically we only need to
	//divide by numbers up to the square root of n to see if n is prime or not.
	//If n is divisible by any of those it means it's not a prime number.
	for (int i = 2; i * i <= n; i++)
	{
		if (n % i == 0)
			return (0);
	}
	return (1);
}

/* Simple main, we just check to see if any of the numbers <= the one passed to
 * the program are primes, and if they are we sum them all up.*/
int	main(int argc, char **argv)
{
	if (argc == 2)
	{
		int	sum = 0;
		int	number = ft_atoi((argv[1]));

		while (number > 0)
			if (is_prime(number--))
				sum += (number + 1);
		ft_putnbr(sum);
		write(1, "\n", 1)
	}
	else
		write(1, "0\n", 2);

	return (0);
}