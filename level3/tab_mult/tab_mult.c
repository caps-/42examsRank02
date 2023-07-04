#include <unistd.h>

/* ft_atoi() again, same old. */
int	ft_atoi(char *str)
{
	int	i = 0;
	int	sign = 1;

	while (*str)
	{
		while (*str == ' ' || (*str >= 9 && *str <= 13))
			str++;
		if (*str == '-')
			sign = -1;
		if (*str == '-' || *str == '+')
			str++;
		while (*str >= '0' && *str <= '9')
		{
			i = i * 10 + *str - 48;
			str++;
		}
	}
	return (sign * i);
}

void	ft_putnum(int n)
{
	char	number[10] = "0123456789";

	if (n > 9)
		ft_putnum(n / 10);
	write(1, &number[n % 10], 1);
}

/* So I used this one with grademe.fr and it passed, but I haven't tried it in
 * the exam. They want the number given to the program as well as that number x 9
 * to to not be any larger than INT_MAX, at least that's what I'm assuming the
 * subject text means. I have NO idea if we're allowed to use INT_MAX/limits.h
 * and you can get all the way fucked if you think I'm going to remember the
 * actual numerical value. SO yeah, I skipped it. */
void	tab_mult(int n)
{
	int	i = 1;

	while (i <= 9)
	{
		ft_putnum(i);
		write(1, " x ", 3);
		ft_putnum(n);
		write(1, " = ", 3);
		ft_putnum(i * n);
		write(1, "\n", 1);
		i++;
	}
}

/*
int	main(int argc, char **argv)
{
	if (argc != 2)
		write(1, "\n", 1);
	else
		tab_mult(ft_atoi(argv[1]));
	return (0);
}
*/