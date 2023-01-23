/* Once again the description given for this function is fucking awful. What
 * the function is supposed to do is take a list and some reference data, then 
 * remove anything from the list that matches the reference data. The last
 * paramater in the function prototype is a pointer to a function that we can
 * chose, so in the main function we're going to past strcmp to compare the list
 * with the reference data. 
 *
 * Remember to not turn in the header, the only thing in the directory when you
 * push should be this file.*/

#include "ft_list.h"
#include <stdlib.h>

void	ft_list_remove_if(t_list **begin_list, void *data_ref, int (*cmp)())
{
	if (begin_list == NULL || *begin_list == NULL)
		return;

	t_list	*list = *begin_list;

	if (cmp(list->data, data_ref) == 0) //if we have a match
	{
		*begin_list = list->next; //move on to the next character/node
		free(list); //free up the list
		ft_list_remove_if(begin_list, data_ref,cmp); //go again
	}
	list = *begin_list;
	ft_list_remove_if(&list->next, data_ref, cmp);
}

#include <stdio.h>
#include <string.h>

void	print_list(t_list **begin_list)
{
	t_list	*list = *begin_list;
	
	while (list != 0)
	{
		printf("%s\n", list->data);
		list = list->next;
	}
}

/*
int	main(void)
{
	char	straa[] = "string aa";
	t_list *aa = malloc(sizeof(t_list));
	aa->next = 0;
	aa->data = straa;

	char	strbb[] = "string bb";
	t_list *bb = malloc(sizeof(t_list));
	bb->next = 0;
	bb->data = strbb;

	char strcc[] = "string cc";
	t_list *cc = malloc(sizeof(t_list));
	cc->next = 0;
	cc->data = strcc;

	char strdd[] = "string dd";
	t_list *dd = malloc(sizeof(t_list));
	dd->next = 0;
	dd->data = strdd;

	aa->next = bb;
	bb->next = cc;
	cc->next = dd;

	t_list	**begin_list = &aa;

	print_list(begin_list);
	printf("---------\n");
	ft_list_remove_if(begin_list, straa, strcmp);
	print_list(begin_list);

	return (0);
}*/
