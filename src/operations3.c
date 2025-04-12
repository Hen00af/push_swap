/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shattori <shattori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 05:51:49 by shattori          #+#    #+#             */
/*   Updated: 2025/04/12 16:58:23 by shattori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rrr(t_DList *a_stack, t_DList *b_stack)
{
	ft_rra(a_stack);
	ft_rrb(b_stack);
	ft_putstr_fd("rrr\n", 1);
}

int	search_are_they_sorted(t_DList *a_stack, t_DList *b_stack)
{
	t_DNode	*current;

	current = a_stack->head;
	while (current && current->next)
	{
		if (current->value > current->next->value)
			return (1);
		current = current->next;
	}
	current = b_stack->head;
	while (current && current->next)
	{
		if (current->value > current->next->value)
			return (1);
		current = current->next;
	}
	return (0);
}

void	push_a_to_b(t_DList *a_stack, t_DList *b_stack)
{
	int	i;

	i = 0;
	printf("\n%d\n\n\n", head_value(a_stack));
	while (a_stack->size > 0)
	{
		printf("%d",head_value(a_stack));
		// if (ft_max(head_value(a_stack),head_value(b_stack)) == head_value(a_stack))
		// 	ft_pb(a_stack, b_stack);
		// else
		// {
			ft_pb(a_stack,b_stack);
		// 	ft_sa(b_stack);
		// }
		
	}
	test(b_stack, 0);
}

void	dealing_more_than_seven(t_DList *a_stack, t_DList *b_stack, int *number)
{
	push_a_to_b(a_stack, b_stack);
	// test(a_stack, 0);
}
