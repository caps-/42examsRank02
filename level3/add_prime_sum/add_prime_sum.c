#include <unistd.h>

void	ft_putnbr(int n)
{
	char c;

	if (n < 0)
		write(1, "0", 1);
	if (n < 10)
	{
		c = n + 48;
		write(1, &c, 1);
	}
	else
	{
		ft_putnbr(n / 10);
		ft_putnbr(n % 10);
	}
}

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

int	is_prime(int n)
{
	int	i = 3;

	if (n <= 1)
		return (0);
	if (n % 2 == 0 && n > 2)
		return (0);
	while (i < (n / 2))
	{
		if (n % i == 0)
			return (0);
		i += 2;
	}
	return (1);
}

int	main(int argc, char **argv)
{
	int	sum = 0;

	if (argc == 2)
	{
		int	number = ft_atoi((argv[1]));

		while (number > 0)
			if (is_prime(number--))
				sum += (number + 1);
		ft_putnbr(sum);
	}
	else
		write(1, "0", 1);
	write(1, "\n", 1);

	return (0);
}