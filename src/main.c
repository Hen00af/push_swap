/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: shattori <shattori@student.42.fr>          +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2025/04/05 19:06:33 by shattori          #+#    #+#             */
/*   Updated: 2025/04/05 19:06:33 by shattori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>


void	populate_node_from_args(t_DList *a_stack, int argc, int *number)
{
	int i;
	int value;
	if (!a_stack)
		exit(1);
	i = 0;
	while (i < argc - 1)
	{
		ft_add_front(a_stack, number[i]);
		i++;
	}
}

// void	test(t_DList *a_stack, int i)
// {
// 	t_DNode *current;
// 	int j;

// 	j = 0;
// 	current = a_stack->head;
// 	while (current)
// 	{
// 		printf("a_stack[%d]: %d\n", j, current->value);
// 		current = current->next;
// 		j++;
// 	}
// 	printf("\n");

// 	ft_ra(a_stack);

// 	current = a_stack->head;
// 	while (current)
// 	{
// 		printf("a_stack[%d]: %d\n", j, current->value);
// 		current = current->next;
// 	}
// 	printf("\n");
// 	ft_rra(a_stack);
// }

int	main(int argc, char **argv)
{
	t_DList *a_stack;
	t_DList *b_stack;
	t_DNode *current;
	int *number;
	int i;

	i = 0;
	number = error_handling_and_coodinate_compression(argc - 1, argv + 1);
	a_stack = ft_initialize_stack();
	b_stack = ft_initialize_stack();

	populate_node_from_args(a_stack, argc, number);
	// test(a_stack, i);
	// printf("a_stack->head : %d\n", head_value(a_stack));
	push_swap(a_stack, b_stack, number, argc - 1);
	ft_free_list(a_stack);
	ft_free_list(b_stack);
	free(number);
	return (0);
}
