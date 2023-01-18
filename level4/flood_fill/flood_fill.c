/* Oh boy. So I think for this one to make sense you had to have done the
 * so_long project? I did fract-ol instead, so this one was an absolute fucking
 * mystery to me. Also the subject description is really, really terrible so
 * given my complete lack of context for anything it took me forever to figure
 * out what it was even trying to say. So with that all being said, let's jump
 * in and figure this thing out. */

#include "flood_fill.h"

/* */
void	ft_fill(char **tab, t_point size, char target, int row, int col)
{
	if (row < 0 || col < 0 || row >= size.y || col >= size.x)
		return;
	if (tab[row][col] == 'F' || tab[row][col] != target)
		return;
	tab[row][col] = 'F';

	ft_fill(tab, size, target, row -1, col);
	ft_fill(tab, size, target, row +1, col);
	ft_fill(tab, size, target, row, col - 1);
	ft_fill(tab, size, target, row, col + 1);
}

/* */
void	flood_fill(char **tab, t_point size, t_point begin)
{
	char	target = tab[begin.y][begin.x];
	ft_fill(tab, size, target, begin.y, begin.x);
}

/* Main function, don't include this in the actual exam! */

#include <stdio.h>
#include <stdlib.h>

void print_tab(char **a, t_point size)
{
    int i;
    int j;
    i = 0;
    while (i < size.y)
    {
        j = 0;
        while (j < size.x)
        {
            printf("%c ", a[i][j]);
            j++;
        }
        i++;
        printf("\n");
    }
}

char** make_area(char **a, t_point size)
{
    char **res;
    int  i, j;

    res = malloc(sizeof(char *) * size.y);
    i = 0;
    while (i < size.y)
    {
        res[i] = malloc(sizeof(char *) * (size.x + 1));
        j = 0;
        while (j < size.x)
        {
            res[i][j] = a[i][j * 2];
            j++;
        }
        i++;
    }
    return (res);
}

int main(void)
{
	t_point size = {8, 5};
	t_point begin = {0, 0};
    char **area;
	char *zone[] = {
		"1 1 1 1 1 1 1 1",
		"1 0 0 0 0 0 0 1",
		"1 0 0 1 0 0 0 1",
		"1 0 0 0 0 0 1 1",
		"1 1 1 0 0 1 0 1",
	};

    area = make_area((char **)zone, size);
	print_tab(area, size);
	flood_fill(area, size, begin);
	printf("\n");
	print_tab(area, size);
	return (0);
}
