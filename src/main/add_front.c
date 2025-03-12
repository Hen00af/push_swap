#include "libft.h"

void add_front(stack_info_t *list, int data)
{
    if (!list)
        return;

    stack_t *new_node = create_node(data);
    if (!new_node)
        return;

    if (list->head == NULL)
    {
        list->head = new_node;
        list->tail = new_node;
    }
    else
    {
        new_node->next = list->head;
        list->head->prev = new_node;
        list->head = new_node;
    }
    list->size++;
}
