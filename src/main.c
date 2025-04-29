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
		ft_add_back(a_stack, number[i]);
		i++;
	}
}

void initialize_stack(t_DList *a_stack,t_Dlist *b_stack)
{
	a_stack = ft_initialize_stack();
	b_stack = ft_initialize_stack();
}
void free_list(t_DList *a_stack,t_Dlist *b_stack)
{
	
}

int	main(int argc, char **argv)
{
	t_DList *a_stack;
	t_DList *b_stack;
	int *number;

	number = error_handling_and_coodinate_compression(argc - 1, argv + 1);
	populate_node_from_args(a_stack, argc, number);
	push_swap(a_stack, b_stack, number, argc - 1) ;
	ft_free_list(a_stack);
	ft_free_list(b_stack);
	free(number);
	return (0);
}
