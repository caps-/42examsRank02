#include <unistd.h>

/* Standard ft_atoi() function. */
int	ft_atoi(char *str)
{
	int	n = 0;

	while (*str != '\0')
	{
		n *= 10;
		n += *str - 48;
		++str;
	}
	return (n);
}

/* Really this is just a variation of the ft_putnum() function I use in a bunch
 * of other programs, only this time using base 16 instead of 10. */
void	print_hex(int n)
{
	char	hex[16] = "0123456789abcdef";

	if (n >= 16)
		print_hex(n / 16);
	write(1, &hex[n % 16], 1);
}

int	main(int argc, char **argv)
{
	if (argc == 2)
		print_hex(ft_atoi(argv[1]));
	write(1, "\n", 1);
	return (0);
}
