/* Defining our t_point structure for x and y coordinates. */
typedef struct	s_point
{
	int			x;
	int			y;
}				t_point;

/* A recursive function to fill the grid or whatever it is you're filling. If
 * the current row or column values are outsize of the coordinates of the grid,
 * if the current coords already filled or if they're not specified as a target
 * then we skip this iteration of the function. If we're inside the grid and
 * the current coordinate is a target we'll set it's contents to an F. Then we
 * run the whole fill function again four times, one position up, down, left and
 * right of the current one. It'll keep doing this until all reachable
 * coordinates have been filled. */
void	fill(char **tab, t_point size, char target, int row, int col)
{
	//if the coords are out of bounds
	if (row < 0 || col < 0 || row >= size.y || col >= size.x)
		return;
	//if current pos is either already filled or is not a target to fill
	if (tab[row][col] == 'F' || tab[row][col] != target)
		return;
	//fill current coordinate with 'F'
	tab[row][col] = 'F';

	//go forth and flood fill!
	fill(tab, size, target, row -1, col);
	fill(tab, size, target, row +1, col);
	fill(tab, size, target, row, col -1);
	fill(tab, size, target, row, col +1);
}

/* Really we're just using the flood_fill() function as starting point, sending
 * the starting coordinates to the function above which will actually do the
 * filling. The target variable takes whatever character is at that coordinate
 * and uses it as the charater to fill/replace with an F. */
void	flood_fill(char **tab, t_point size, t_point begin)
{
	char	target = tab[begin.y][begin.x];

	fill(tab, size, target, begin.y, begin.x);
}

/* Ugly ass 42 code
#include <stdlib.h>
#include <stdio.h>

char** make_area(char** zone, t_point size)
{
	char** new;

	new = malloc(sizeof(char*) * size.y);
	for (int i = 0; i < size.y; ++i)
	{
		new[i] = malloc(size.x + 1);
		for (int j = 0; j < size.x; ++j)
			new[i][j] = zone[i][j];
		new[i][size.x] = '\0';
	}

	return new;
}

int main(void)
{
	t_point size = {8, 5};
	char *zone[] = {
		"11111111",
		"10001001",
		"10010001",
		"10110001",
		"11100001",
	};

	char**  area = make_area(zone, size);
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area[i]);
	printf("\n");

	t_point begin = {7, 4};
	flood_fill(area, size, begin);
	for (int i = 0; i < size.y; ++i)
		printf("%s\n", area[i]);
	return (0);
}
*/