#include "libft.h"

stack_info_t *create_stack()
{
    stack_info_t *stack;

    stack = (stack_info_t *)malloc(sizeof(stack_info_t));
    if (!stack)
    {
        fprintf(stderr, "Error: Memory allocation failed for stack_info_t\n");
        return NULL;
    }
    stack->head = NULL;
    stack->tail = NULL;
    stack->size = 0;
    return stack;
}