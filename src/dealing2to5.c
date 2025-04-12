/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dealing2to5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shattori <shattori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 06:25:27 by shattori          #+#    #+#             */
/*   Updated: 2025/04/12 16:51:32 by shattori         ###   ########.fr       */
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
	t_DNode	*current;

	printf("dealing2");
	printf("dealing2\n");
	current = a_stack->head;
	test(a_stack, 0);
	if (head_value(a_stack) > a_stack->tail->value)
		ft_sa(a_stack);
	test(a_stack, 0);
}

void	dealing3(t_DList *a_stack, t_DList *b_stack, int *number)
{
	t_DNode	*cur;
	int		a;
	int		b;
	int		c;

	printf("dealing3");
	cur = a_stack->head;
	a = cur->value;
	b = cur->next->value;
	c = cur->next->next->value;
	test(a_stack, 0);
	if (a < c && c < b) // 0 2 1
	{
		ft_sa(a_stack);
		ft_ra(a_stack);
	}
	else if (b < a && a < c) // 1 0 2
		ft_sa(a_stack);
	else if (c < a && a < b) // 2 0 1
		ft_rra(a_stack);
	else if (b < c && c < a) // 1 2 0
		ft_ra(a_stack);
	else if (c < b && b < a) // 2 1 0
	{
		ft_sa(a_stack);
		ft_rra(a_stack);
	}
	test(a_stack, 0);
}

void	dealing4(t_DList *a_stack, t_DList *b_stack, int *number)
{
	printf("dealing4");
	test(a_stack, 0);
	if (a_stack->head->next->value)
		while (head_value(a_stack) != 0)
			ft_ra(a_stack);
	test(a_stack, 0);
	ft_pb(a_stack, b_stack);
	dealing3(a_stack, b_stack, number);
	ft_pa(a_stack, b_stack);
	test(a_stack, 0);
}

void	dealing5(t_DList *a_stack, t_DList *b_stack, int *number)
{
	printf("dealing5");
	test(a_stack, 0);
	while (head_value(a_stack) != 0)
		ft_ra(a_stack);
	ft_pb(a_stack, b_stack);
	test(a_stack, 0);
	while (head_value(a_stack) != 1)
		ft_ra(a_stack);
	ft_pb(a_stack, b_stack);
	test(a_stack, 0);
	dealing3(a_stack, b_stack, number);
	test(a_stack, 0);
	ft_pa(a_stack, b_stack);
	ft_pa(a_stack, b_stack);
	test(a_stack, 0);
}

void	dealing6(t_DList *a_stack, t_DList *b_stack, int *number)
{
	printf("dealing6");
	while (head_value(a_stack) != 0)
		ft_ra(a_stack);
	ft_pb(a_stack, b_stack);
	while (head_value(a_stack) != 1)
		ft_ra(a_stack);
	ft_pb(a_stack, b_stack);
	while (head_value(a_stack) != 2)
		ft_ra(a_stack);
	ft_pb(a_stack, b_stack);
	dealing3(a_stack, b_stack, number);
	test(a_stack, 0);
	ft_pa(a_stack, b_stack);
	ft_pa(a_stack, b_stack);
	ft_pa(a_stack, b_stack);
	test(a_stack, 0);
}