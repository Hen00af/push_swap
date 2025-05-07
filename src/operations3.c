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

static void radix_sort_stack_b(t_DList *a_stack, t_DList *b_stack, int j)
{
	int b_size = b_stack->size;

	while (b_size-- > 0)
	{
		int val = b_stack->head->value;
		if (((val >> j) & 1) == 0)
			ft_rb(b_stack);
		else
			ft_pa(a_stack, b_stack); 
	}
	while (b_stack->size > 0)
		ft_pa(a_stack, b_stack);
}

void dealing_more_than_seven(t_DList *a_stack, t_DList *b_stack, int *number)
{
	int j = 0;
	int bit_size = 0;
	int size = a_stack->size;

	// printf("1\n");
	while (size >> ++bit_size)
		size /= 2;
	j = -1;
	while (++j <= bit_size)
	{
		size = a_stack->size;
		while (size--&&!ft_is_sorted(a_stack))
		{
			if (((a_stack->head->value >> j) & 1) == 0)
				ft_pb(a_stack, b_stack);
			else
				ft_ra(a_stack);
		}
		// radix_sort_stack_b(a_stack, b_stack, j);
	}
	while (a_stack->size != 0)
	ft_pb(a_stack,b_stack);
}
