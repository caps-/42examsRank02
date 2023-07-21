/* Actually a pretty simple one, just remember to write a function to print
 * numbers to the output. I kept main clean by using a break statement in the
 * tab_mult() function to stop the function from printing a newline after 9x so
 * we can have a typical (by my standards anyway) main. */

#include <unistd.h>

int	ft_atoi(char *str)
{
	int	sign = 1;
	int	result = 0;

	while (*str)
	{
		while (*str <= 32)
			str++;
		if (*str == '-')
			sign = -1;
		if (*str == '-' || *str == '+')
			str++;
		while (*str >= '0' && *str <= '9')
		{
			result = result * 10 + *str - 48;
			str++;
		}
	}
	return (sign * result);
}

void	ft_putnbr(int n)
{
	char	number[10] = "0123456789";

	if (n > 9)
		ft_putnbr(n / 10);
	write(1, &number[n % 10], 1);
}

void	tab_mult(int n)
{
	for (int i = 1; i < 10; i++)
	{
		ft_putnbr(i);
		write(1, " x ", 3);
		ft_putnbr(n);
		write(1, " = ", 3);
		ft_putnbr(i * n);
		if (i == 9)
			break;
		write(1, "\n", 1);
	}
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		tab_mult(ft_atoi(argv[1]));
	write(1, "\n", 1);
	return (0);
}
