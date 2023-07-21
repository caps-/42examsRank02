/* If anyone can think of how to do this in two lines then let me know lol. */

int	ft_strlen(char *str)
{
	int	i;

	for(i = 0; str[i]; i++);
	return (i);
}
