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

void	populate_stack_from_args(t_DList *a_stack, int count, int *numbers)
{
	int i;

	if (!a_stack)
	{
		ft_perror("Error: stack not initialized\n");
		exit(1);
	}
	i = 0;
	while (i < count)
	{
		ft_add_back(a_stack, numbers[i]);
		i++;
	}
}

void initialize_stack(t_DList **a_stack,t_DList **b_stack)
{
	*a_stack = ft_initialize_stack();
	*b_stack = ft_initialize_stack();
}

void free_all(t_DList *a_stack,t_DList *b_stack,int *number)
{
	if(a_stack)
		ft_free_list(a_stack);
	if(b_stack)
		ft_free_list(b_stack);
	if(number)
		free(number);
}

void check_args(int argc)
{
	if (argc < 3)
		exit_with_error("===Please write more than 2 numbers===");
}

int	main(int argc, char **argv)
{
	t_DList *a_stack;
	t_DList *b_stack;
	int *number;

	check_args(argc);
	number = search_same_number_and_coodinate_compression(argc,argv);
	initialize_stack(&a_stack,&b_stack);
	populate_stack_from_args(a_stack, argc - 1, number);
	push_swap(a_stack, b_stack, number, argc - 1) ;
	free_all(a_stack,b_stack,number);
	return (0);
}
