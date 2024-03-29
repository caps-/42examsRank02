#include <unistd.h>

void	ft_putnbr(int n)
{
	char	str[10] = "0123456789";

	if (n > 9)
		ft_putnbr(n / 10);
	write(1, &str[n % 10], 1);
}

int	main(void)
{
	for (int i = 1; i <= 100; i++)
	{
		if (i % 15 == 0)
			write(1, "fizzbuzz", 8);
		else if (i % 3 == 0)
			write(1, "fizz", 4);
		else if (i % 5 == 0)
			write(1,  "buzz", 4);
		else
			ft_putnbr(i);
		write(1, "\n", 1);
	}
	return (0);
}
