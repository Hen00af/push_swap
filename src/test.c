#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>


t_DList	*create_dlist(void)
{
	t_DList *list;

	list = (t_DList *)malloc(sizeof(t_DList));
	if (!list)
		return (NULL);
	list->head = NULL;
	list->tail = NULL;
	list->size = 0;
	return (list);
}

void	print_list_forward(t_DList *list)
{
	t_DNode *current = list->head;
	while (current != NULL)
	{
		printf("%d ", current->value);
		current = current->next;
	}
	printf("\n");
}
void	print_list_behind(t_DList *list)
{
	stack_t *current = list->tail;
	while (current != NULL)
	{
		printf("%d ", current->value);
		current = current->prev;
	}
	printf("\n");
}

int	main(void)
{
	t_DList *list = create_dlist();

	add_front(list, 10);
	add_front(list, 20);
	add_back(list, 30);
	add_back(list, 40);

	print_list_forward(list);
	print_list_behind(list);
	printf("\n");

	free_list(list);
	return (0);
}
