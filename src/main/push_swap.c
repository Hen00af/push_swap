#include <stdio.h>
#include <stdlib.h>
#include "error_handling.c"

typedef struct stack_s {
    struct stack_s *next;
    struct stack_s *prev;
    int value;
} stack_t;

typedef struct stack_info_s {
    stack_t *head;
    stack_t *tail;
    int length;
} stack_info_t;

stack_t *create_node(int value) {
    stack_t *new_node = (stack_t *)malloc(sizeof(stack_t));
    if (!new_node)
        return NULL;
    new_node->next = NULL;
    new_node->prev = NULL;
    new_node->value = value;
    return new_node;
}

void add_front(stack_info_t *list, int data) 
{ 
    stack_t *new_node = create_node(data);
    if (!new_node || !list)
        return;
    if (!list->head) {
        list->head = new_node;
        list->tail = new_node;
    } else {
        new_node->next = list->head;
        list->head->prev = new_node;
        list->head = new_node;
    }
    list->length++;
}

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

stack_info_t *initialize_stack()
{
    stack_info_t *stack_info;

    stack_info = (stack_info_t *)malloc(sizeof(stack_info_t));
    if (!stack_info)
        exit(1);
    stack_info->head = NULL;
    stack_info->tail = NULL;
    stack_info->length = 0;
    return stack_info;
}

void free_node(stack_info_t *list) {
    stack_t *current = list->head;
    while (current) {
        stack_t *next = current->next;
        free(current);
        current = next;
    }
    free(list);
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
    error_handling(argc,argv,number);
    populate_node_from_args(a_stack,b_stack, argc, number);
    start_dealing(a_stack, b_stack, argc);
    free_node(a_stack);
    free_node(b_stack);
    return 0;
}
