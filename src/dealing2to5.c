/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dealing2to5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shattori <shattori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 06:25:27 by shattori          #+#    #+#             */
/*   Updated: 2025/05/03 01:40:04 by shattori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	test(t_DList *stack)
{
	t_DNode	*current;
	int		j;

	j = 0;
	current = stack->head;
	while (current)
	{
		printf("%d\n", current->value);
		current = current->next;
		j++;
	}
}

void	dealing2(t_DList *a_stack)
{
	int	next;
	int	value;

	value = a_stack->head->value;
	next = a_stack->head->next->value;
	// printf("\n%d", value);
	// printf("%d\n", next);
	if (!a_stack || a_stack->size < 2)
		return ;
	if (value > next)
		ft_sa(a_stack);
}

void	dealing3(t_DList *a_stack)
{
	t_DNode	*cur;
	int		a;
	int		b;
	int		c;

	cur = a_stack->head;
	a = cur->value;
	b = cur->next->value;
	c = cur->next->next->value;
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
}

void	dealing4(t_DList *a_stack, t_DList *b_stack, int *number, int x)
{
	if(ft_is_sorted(a_stack))
		return;
	if (number[0] == x || number[1] == x)
		while (head_value(a_stack) != x)
			ft_ra(a_stack);
	else
		while (head_value(a_stack) != x)
			ft_rra(a_stack);
	ft_pb(a_stack, b_stack);
	dealing3(a_stack);
	ft_pa(a_stack, b_stack);
}
