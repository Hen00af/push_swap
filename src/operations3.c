/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shattori <shattori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 05:51:49 by shattori          #+#    #+#             */
/*   Updated: 2025/04/10 08:15:12 by shattori         ###   ########.fr       */
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

void	push_larger_than_pivot(t_DList *b, t_DList *a, t_DNode *pivot)
{
	int	i;
	int	rotate_count;
	int	size;

	i = 0;
	rotate_count = 0;
	size = b->size;
	while (i < size)
	{
		if (b->head->value >= pivot->value)
			ft_pa(a, b);
		else
		{
			ft_rb(b);
			rotate_count++;
		}
		i++;
	}
	while (rotate_count--)
		ft_rrb(b);
}

int	has_smaller_than_pivot(t_DList *a, int pivot_value)
{
	t_DNode	*tmp;
	int		i;

	tmp = a->head;
	i = 0;
	while (i < a->size)
	{
		if (tmp->value < pivot_value)
			return (1);
		tmp = tmp->next;
		i++;
	}
	return (0);
}

void	quick_sort_a(t_DList *a, t_DList *b)
{
	t_DNode	*pivot;

	if (a->size <= 3)
	{
		dealing3(a, b, NULL);
		return ;
	}
	pivot = take_pivot(a);
	push_smaller_than_pivot(a, b, pivot);
	quick_sort_a(a, b);
	quick_sort_b(a, b);
}

void	quick_sort_b(t_DList *a, t_DList *b)
{
	t_DNode	*pivot;

	if (b->size <= 3)
	{
		dealing3(a, b,0);
		return ;
	}
	pivot = take_pivot(b);
	push_larger_than_pivot(b, a, pivot);
	quick_sort_a(a, b);
	quick_sort_b(a, b);
}

void	dealing_more_than_seven(t_DList *a_stack, t_DList *b_stack, int *number)
{
	t_DNode	*pivot;

	printf("dealing more than 7 \n");
	pivot = take_pivot(a_stack);
	push_smaller_than_pivot(a_stack, b_stack, pivot);
	if (a_stack->size <= 3)
		dealing3(a_stack, b_stack, number);
	else if (has_smaller_than_pivot(a_stack, pivot->value))
		dealing_more_than_seven(a_stack, b_stack, number);
	while (b_stack->size > 0)
	{
		ft_pa(a_stack, b_stack);
		if (a_stack->head->value > a_stack->head->next->value)
			ft_sa(a_stack);
	}
	test(a_stack, 0);
}

void	push_smaller_than_pivot(t_DList *a, t_DList *b, t_DNode *pivot)
{
	int	i;
	int	pushed;
	int	rotate_count;
	int	size;

	i = 0;
	pushed = 0;
	rotate_count = 0;
	size = a->size;
	while (i < size)
	{
		if (a->head->value < pivot->value)
		{
			ft_pb(a, b);
			pushed++;
		}
		else
		{
			ft_ra(a);
			rotate_count++;
		}
		i++;
	}
	while (rotate_count--)
		ft_rra(a);
}
