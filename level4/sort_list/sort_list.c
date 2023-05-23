#include "list.h"

/* Linked lists. Ugh. OK.
 *
 * Something that jumps out IMMEJUTLY with this function is the whole int, int
 * situation. What the function is expecting to be passed is a pointer to another
 * function that takes 2 ints. Because it's a function we don't need to name the
 * paramaters, just tell it what type to expect.*/
t_list	*sort_list(t_list *lst, int (*cmp)(int, int))
{
	t_list	*start_of_list;
	int		temp;

	start_of_list = lst; //start_of_list is basically the start of lst
	while (lst-> next != 0)
	{
		//if the first data value is greater than the second one we'll go in to
		//if statement stuff, which is really just a simple swapping funciton.
		if (cmp(lst->data, lst->next->data) == 0)
		{
			temp = lst->data; //stick the data value in our temp variable
			lst->data = lst->next->data; //copy lst->next->data over to lst->data
			lst->next->data = temp; //then copy temp back in to lst->next->data
			lst = start_of_list; //start lst from start_of_list
		}
		//otherwise if the first data value was less than or equal to the second
		//one we'll just move on to the next element and check again.
		else
			lst = lst->next;
	}
	lst = start_of_list;
	return (lst);
}
/* Other functions here, uncomment to compile and test/run.
 *
 * This takes two integers and checks to see if a is <= b. If that's the case
 * it returns 1, otherwise it returns 0.
int	ascending(int a, int b)
{
	return (a <= b);
}

#include <stdio.h>
#include <stdlib.h>

t_list	*new_element(int data)
{
	t_list	*element = malloc(sizeof(t_list));

	if (element)
	{
		element->data = data;
		element->next = 0;
	}
	return (element);
}

int	main(void)
{
	t_list	*list;

	int a = 4;
	int	b = 2;
	int	c = 1;
	int	d = 3;

	list = new_element(a);
	list->next = new_element(b);
	list->next->next = new_element(c);
	list->next->next->next = new_element(d);

	sort_list(list, ascending);
	while (list)
	{
		printf("%d\n", list->data);
		list = list->next;
	}
	return (0);
}*/