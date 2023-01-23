/* Subject description is surprisingly on point for this one, we just need it
 * to take some function and apply it to a list that's also been passed to the
 * function.*/

#include "ft_list.h"

void	ft_list_foreach(t_list *begin_list, void (*f)(void *))
{
	t_list	*list_ptr;

	list_ptr = begin_list;
	while (list_ptr)
	{
		(*f)(list_ptr->data); //function runs on whatever's in data
		list_ptr = list_ptr->next; //moves on to the next element
	}
}

/*
#include <stdio.h>
#include <stdlib.h>

void	int_doubler(void *n)
{
	int	*num = (int *)n;
	*num *= 2;
}

int	main(void)
{
	t_list	*ptr_a = malloc(sizeof(t_list));
	int	n_a = 0;
	ptr_a->data = &n_a;
	ptr_a->next =0;
	
	t_list	*ptr_b = malloc(sizeof(t_list));
	int	n_b = 2;
	ptr_b->data = &n_b;
	ptr_b->next =0;

	t_list	*ptr_c = malloc(sizeof(t_list));
	int	n_c = 3;
	ptr_c->data = &n_c;
	ptr_c->next =0;

	ptr_a->next = ptr_b;
	ptr_b->next = ptr_c;

	t_list *list = ptr_a;
	while (list != 0)
	{
		printf("%d, ", *(int *)(list->data));
		list = list->next;
	}
	printf("\n");

	ft_list_foreach(ptr_a, int_doubler);

	list = ptr_a;
	while (list !=0)
	{
		printf("%d, ", *(int *)(list->data));
		list = list->next;
	}
	printf("\n");
	return (0);
}*/
