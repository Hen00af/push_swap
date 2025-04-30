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
	// if (!a_stack){
	// 	printf("nothing args\n");
	// 	exit(1);
	// }
	i = 0;
	while (i < argc - 1)
	{
		ft_add_back(a_stack, number[i]);
		i++;
	}
}

void initialize_stack(t_DList *a_stack,t_DList *b_stack)
{
	a_stack = ft_initialize_stack();
	b_stack = ft_initialize_stack();
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
	printf("%d",number[1]);
	initialize_stack(a_stack,b_stack);
	populate_node_from_args(a_stack, argc, number);
	push_swap(a_stack, b_stack, number, argc - 1) ;
	free_all(a_stack,b_stack,number);
	return (0);
}
