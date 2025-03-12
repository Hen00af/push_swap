#include "libft.h"

stack_t *create_node(int data)
{
    stack_t *node = (stack_t *)malloc(sizeof(stack_t));
    if (!node)
        return NULL;
    node->data = data;
    node->next = NULL;
    node->prev = NULL;
    return node;
}