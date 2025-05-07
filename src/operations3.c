/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shattori <shattori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 05:51:49 by shattori          #+#    #+#             */
/*   Updated: 2025/05/02 21:23:54 by shattori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rrr(t_DList *a_stack, t_DList *b_stack)
{
	ft_rra(a_stack);
	ft_rrb(b_stack);
	ft_putstr_fd("rrr\n", 1);
}

static void	radix_sort_stack_b(t_stacks *s, int b_size, int bit_size, int j)
{
	while (b_size-- && j <= bit_size && !is_array_sorted(s))
	{
		if (((s->b[0] >> j) & 1) == 0)
			rotate(s->b, s->b_size, "up", "b");
		else
			push("pa", s);
	}
	if (is_array_sorted(s))
		while (s->b_size != 0)
			push("pa", s);
}

void dealing_more_than_seven(t_DList *a_stack, t_DList *b_stack, int *number)
{
	int j ;
	int bit_size ;
	int size ;
	t_DNode *node;

	bit_size = 0;
	size = a_stack->size;
	node = a_stack -> head;
	while (size > 1 && ++bit_size)
		size /= 2;
	j = 0;
	while (j < bit_size)
	{
		size = a_stack->size;
		while (size-- && !ft_is_sorted(a_stack))
		{
			if(((node->value >> j) & 1) == 0 )
			ft_pb(a_stack,b_stack);
			else
			ft_rb(a_stack);
		}
		radix_sort_stack_b(a_stack, b_stack, bit_size, j + 1);
		j++;
	}
}
