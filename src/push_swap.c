/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shattori <shattori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 06:09:33 by shattori          #+#    #+#             */
/*   Updated: 2025/04/10 08:20:42 by shattori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_DNode	*take_pivot(t_DList *stack)
{
	int		pivot_value;
	int size;
	int i;
	t_DNode	*tmp;
	
	if(stack->size <= 0)
	return NULL;

	i = 0;
	size = stack->size / 2;
	tmp = stack->head;
	while (i < size)
	{
		if (tmp->value == stack->tail->value)
			return (NULL);
		tmp = tmp->next;
		i++;
	}
	return (tmp);
}

void	push_swap(t_DList *a_stack, t_DList *b_stack, int *number,
		int number_arg)
{
	if (search_are_they_sorted(a_stack, b_stack) == 0)
		return ;
	if (number_arg == 2)
		dealing2(a_stack, b_stack, number);
	else if (number_arg == 3)
		dealing3(a_stack, b_stack, number);
	else if (number_arg == 4)
		dealing4(a_stack, b_stack, number);
	else if (number_arg == 5)
		dealing5(a_stack, b_stack, number);
	else if (number_arg == 6)
		dealing6(a_stack, b_stack, number);
	else
		dealing_more_than_seven(a_stack, b_stack, number);
}
