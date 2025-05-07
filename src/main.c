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
	if (!a_stack)
		exit(1);
	i = 0;
	while (i < argc)
	{
		ft_add_back(a_stack, number[i]);
		i++;
	}
}

void	initialize_stacks(t_DList **a_stack, t_DList **b_stack)
{
	*a_stack = ft_initialize_stack();
	if (!a_stack)
		ft_exit(NULL, NULL, NO_ERROR);
	*b_stack = ft_initialize_stack();
	if (!b_stack)
		ft_exit(*a_stack, NULL, NO_ERROR);
}

void	free_stacks(t_DList *a_stack, t_DList *b_stack, int *number)
{
	ft_free_list(a_stack);
	ft_free_list(b_stack);
	free(number);
}

void	serch_args(int argc)
{
	if (argc < 2)
	{
		printf("===================Error===================\n");
		printf("==== Please write more than 2 numbers ====\n");
		printf("===========================================\n");
		ft_exit(NULL, NULL, NO_ERROR);
	}
}

int	main(int argc, char **argv)
{
	t_DList *a_stack;
	t_DList *b_stack;
	int *number;

	serch_args(argc - 1);
	number = search_same_number_and_coordinate_compression(argc, argv);
	initialize_stacks(&a_stack, &b_stack);
	populate_node_from_args(a_stack, argc - 1, number);
	push_swap(a_stack, b_stack, number, argc - 1);
	free_stacks(a_stack, b_stack, number);
	return (0);
}
