/* So simple. I actually ended up adding a few extra operations like ^n,
 * compiling it and then sticking it in my /opt folder to use as a simple
 * command line calculator lol. */

#include <stdio.h>
#include <stdlib.h>

void	do_op(int n1, char op, int n2)
{
	if (op == '+')
		printf("%d", n1 + n2);
	else if (op == '-')
		printf("%d", n1 - n2);
	else if (op == '*')
		printf("%d", n1 * n2);
	else if (op == '/')
		printf("%d", n1 / n2);
	else if (op == '%')
		printf("%d", n1 % n2);
}

int	main(int argc, char **argv)
{
	if (argc == 4)
	{
		int		n1 = atoi(argv[1]);
		int		n2 = atoi(argv[3]);
		char	op = argv[2][0];

		do_op(n1, op, n2);
	}
	printf("\n");
	return (0);
}