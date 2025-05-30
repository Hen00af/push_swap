/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shattori <shattori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 06:09:33 by shattori          #+#    #+#             */
/*   Updated: 2025/04/22 09:59:18 by shattori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_DNode	*take_pivot(t_DList *stack)
{
	int		pivot_value;
	int		size;
	int		i;
	t_DNode	*tmp;

	if (stack->size <= 0)
		return (NULL);
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

int	search_are_they_sorted(t_DList *a_stack, t_DList *b_stack)
{
	printf("10\n");
	if (ft_is_sorted(a_stack) == 0 && b_stack->size == 0 || ft_is_sorted(a_stack) ==0 && a_stack->size == 0)
		return (1);
	return (0);
}

void	push_swap(t_DList *a_stack, t_DList *b_stack, int *number,
		int number_arg)
{
	if (number_arg == 2)
		dealing2(a_stack);
	else if (number_arg == 3)
		dealing3(a_stack);
	else if (number_arg == 4)
		dealing4(a_stack, b_stack, number,4);
	else
	{
		// if (search_are_they_sorted(a_stack, b_stack))
		// 	return ;
		dealing_more_than_seven(a_stack, b_stack, number);
	}

}
