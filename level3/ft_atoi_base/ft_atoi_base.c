/* Checks to make sure the number contains valid characters, 0-9 a-f and A-F. */
int		is_valid(char c, int base)
{
	char digits[17] = "0123456789abcdef";
	char digits2[17] = "0123456789ABCDEF";

	while (base--)
		if (digits[base] == c || digits2[base] == c)
			return (1);
	return (0);
}

/* Uses ascii values to convert convert from characters to integers. */
int		value_of(char c)
{
	if (c >= '0' && c <= '9')
		return (c - 48);
	else if (c >= 'a' && c <= 'f')
		return (c - 'a' + 10);
	else if (c >= 'A' && c <= 'F')
		return (c - 'A' + 10);
	return (0);
}

/* Enter with the reeeeemix! Same concept as the OG ft_atoi, but we gotta use
 * our other functions here instead of like *str >= '0' or whatever. Go look at
 * ft_atoi and you'll see what I mean. I've seen smaller code than what's here,
 * but I'm a bit thick and don't really understand the other ways lol. Hey, it
 * works, it's good! */
int		ft_atoi_base(const char *str, int str_base)
{
	int result = 0;
	int sign = 1;

	while (*str <= 32)
		str++;
	if (*str == '-')
		sign = -1;
	if (*str == '-' || *str == '+')
		str++;
	while (is_valid(*str, str_base))
		result = result * str_base + value_of(*str++);
	return (sign * result);
}

/*
#include <stdio.h>

int	main(void)
{
	printf("--------------------------------\n");
	printf("%d\n", ft_atoi_base("16", 10));
	printf("%d\n", ft_atoi_base("  -f", 16));
	printf("%d\n", ft_atoi_base("16", 8));
	printf("%d\n", ft_atoi_base("DEADb33f", 16));
	printf("%d\n", ft_atoi_base("Does this work?", 16));
	printf("%d\n", ft_atoi_base("690543E2", 13));
	return (0);
}
*/