#include "push_swap.h"
#include <stdio.h>
#include <stdlib.h>


void	print_list_forward(t_DList *list)
{
	t_DNode *current;

	current = list->head;
	printf("List forward: ");
	while (current)
	{
		printf("%d ", current->value);
		current = current->next;
	}
	printf("\n");
}

void	print_list_behind(t_DList *list)
{
	t_DNode *current;
	int i;

	current = list->tail;
	printf("List backward: ");
	while (current)
	{
		printf("%d ", current->value);
		current = current->prev;
	}
	printf("\n");
}

int	main(void)
{
	t_DList *list = initialize_stack();

	add_front(list, 10);
	add_front(list, 20);
	add_back(list, 30);
	add_back(list, 40);
	printf("List size: %d\n", list->size);
	print_list_forward(list);
	print_list_behind(list);
	printf("\n");

	free_list(list);
	return (0);
}
