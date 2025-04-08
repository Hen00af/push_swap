/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dealing2to5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shattori <shattori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 06:25:27 by shattori          #+#    #+#             */
/*   Updated: 2025/04/08 17:06:02 by shattori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	test(t_DList *a_stack, int i)
{
	t_DNode	*current;
	int		j;

	j = 0;
	current = a_stack->head;
	while (current)
	{
		printf("a_stack[%d]: %d\n", j, current->value);
		current = current->next;
		j++;
	}
	printf("\n");
}

void	dealing2(t_DList *a_stack, t_DList *b_stack, int *number)
{
	test(a_stack, 0);
	if (number[1] > number[0])
		ft_sa(a_stack);
	test(a_stack, 0);
}

void	dealing3(t_DList *a_stack, t_DList *b_stack, int *number)
{
	printf("dealing3\n");
	test(a_stack, 0);
	if (number[0] == 1 && number[1] == 2)
	{
		ft_sa(a_stack);
		ft_ra(a_stack);
	}
	else if (number[0] == 1 && number[1] == 0)
		ft_ra(a_stack);
	else if (number[0] == 0 && number[1] == 1)
	{
		ft_sa(a_stack);
		ft_rra(a_stack);
	}
	else if (number[0] == 0 && number[1] == 2)
		ft_rra(a_stack);
	else if (number[0] == 2 && number[1] == 0)
		ft_sa(a_stack);
	test(a_stack, 0);
}

void	dealing4(t_DList *a_stack, t_DList *b_stack, int *number)
{
	test(a_stack, 0);
	while (a_stack->tail->value != 0)
		ft_ra(a_stack);
	test(a_stack, 0);
	ft_pb(a_stack, b_stack);
	dealing3(a_stack, b_stack, number);
	ft_pa(a_stack, b_stack);
	test(a_stack, 0);
}
