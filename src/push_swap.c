#include <push_swap.h>


void populate_node_from_args(stack_info_t *a_stack,stack_info_t *b_stack, int argc, int *original)
{
    int i;
    int value;
    if (!a_stack||!b_stack)
        exit(1);
    i = 0;
    while (i < argc)
    {
        add_front(a_stack, original[i]);
        i++;
    }
}

void start_dealing(stack_info_t *a_stack, stack_info_t *b_stack, int argc) 
{
    stack_t *current;
    int i;
    i = 0;
    current = a_stack->head;
    while (current)
    {
        printf("a_stack[%d]: %d\n", i, current->value);
        current = current->next;
        i++;
    }
}

int main(int argc, char **argv)
{
    stack_info_t *a_stack;
    stack_info_t *b_stack;
    stack_t *current;
    int *number;

    a_stack = initialize_stack();
    b_stack = initialize_stack();
    error_handling_and_coodinate_compression(argc,argv);
    populate_node_from_args(a_stack,b_stack, argc, number);
    start_dealing(a_stack, b_stack, argc);
    free_node(a_stack);
    free_node(b_stack);
    return 0;
}
