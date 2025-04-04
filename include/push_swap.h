#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# define ERROR -1

typedef struct stack_s stack_t;

typedef struct stack_s
{
	struct stack_s *next;
	struct stack_s *prev;
	int value;
} stack_t;

typedef struct stack_info_s
{
	stack_t *head;
	stack_t *tail;
	int length;
} stack_info_t;

void	sa(stack_t *afnc);
int	*error_handling_and_coodinate_compression(int argc, char **argv);
void	error_and_initialize(stack_info_t *a_stack, stack_info_t *b_stack,
		int argc, char **argv);
void	populate_node_from_args(t_DList *a_stack, t_DList *b_stack, int argc,
		int *original);
void	print_list_forward(stack_info_t *list);
void	print_list_behind(stack_info_t *list);
void	sb(stack_t *bfnc);
void	coodinate_compression(int *tmp, int *order, int i);

#endif // PUSH_SWAP_H
