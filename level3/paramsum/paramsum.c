#include <unistd.h>

void	ft_putnbr(int n)
{
	char	digit;

	if (n >= 10)
		ft_putnbr(n / 10);
	digit = (n % 10) + 48;
	write(1, &digit, 1);
}

/* The code itself is simple as all fuck, just print whatever argc is
 * - 1. The only interesting thing is the casting of argv which I didn't know
 * about. Try removing that line and then compiling to see the warning you'd
 * get without it. Afaik you can use that on any kind of variable. */
int	main(int argc, char **argv)
{
	(void)argv; //cast to supress compiler warnings about unsed argv

	ft_putnbr(argc - 1);
	write(1, "\n", 1);
	return (0);
}