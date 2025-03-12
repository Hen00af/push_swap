#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
//# include "C:\Users\user\Desktop\42_utils\minilibx_opengl_20191021\42common_core\push_swap\src\libft\libft.h" // 修正: 相対パスを使用

# define ERROR -1

typedef struct stack_s stack_t;

typedef struct stack_s
{
    int value;
    struct stack_s *next;
    struct stack_s *prev;   
} stack_t;

typedef struct stack_info_s
{
    stack_t *head;
    stack_t *tail;
    int length;
} stack_info_t;


void sa(stack_t *afnc);
stack_t *create_node(int value);
stack_info_t *initialize_stack();
void add_front(stack_info_t *list, int data);
void free_node(stack_info_t *list);
void error_handling(int argc);
void error_and_initialize(stack_info_t *a_stack, stack_info_t *b_stack, int argc, char **argv);
void populate_node_from_args(stack_info_t *stack, int argc, char **argv);
void print_list_forward(stack_info_t *list);
void print_list_behind(stack_info_t *list);
void free_list(stack_info_t *list);
void add_back(stack_info_t *list, int data);
void sb(stack_t *bfnc);

#endif // PUSH_SWAP_H
