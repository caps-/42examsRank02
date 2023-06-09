/* Recursively adding 1 (for the current element of the list) to the next element
 * until we're all out of elements. The test functions take longer to write than
 * the actual function we need to submit lol. */
#include "ft_list.h"

int	ft_list_size(t_list *begin_list)
{
	if (begin_list == 0)
		return (0);
	else
		return (1 + ft_list_size(begin_list->next));
}

/*
#include <stdio.h>
#include <stdlib.h>

t_list	*new(void *data)
{
	t_list *n;

	n = (t_list *)malloc(sizeof(t_list));
	if (n)
	{
		n->data = data;
		n->next = NULL;
	}
	return (n);
}

int main(void)
{
	t_list *a, *b, *c, *d;

	a = new("this");
	b = new("is");
	c = new("a");
	d = new("list");
	a ->next = b;
	b->next = c;
	c->next = d;
	printf("%d\n", ft_list_size(a));
	return 0;
}*/
