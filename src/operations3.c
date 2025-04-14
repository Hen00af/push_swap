/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shattori <shattori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 05:51:49 by shattori          #+#    #+#             */
/*   Updated: 2025/04/14 17:42:34 by shattori         ###   ########.fr       */
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
int	calculate_total_cost(int a_cost, int b_cost)
{
	if ((a_cost >= 0 && b_cost >= 0) || (a_cost < 0 && b_cost < 0))
		return (ft_max(a_cost, b_cost));
	return (a_cost + b_cost);
}

t_move	find_cheapest_move(t_DList *a_stack, t_DList *b_stack)
{
	t_move	best_move;
	t_move	move;

	best_move.total_cost = INT_MAX;
	for (int i = 0; i < a_stack->size; i++)
	{
		move = calculate_move(a_stack, b_stack, i);
		if (move.total_cost < best_move.total_cost)
			best_move = move;
	}
	return (best_move);
}

void	execute_move(t_DList *a_stack, t_DList *b_stack, t_move move)
{
	int	a_cost;
	int	b_cost;

	a_cost = move.a_cost;
	b_cost = move.b_cost;
	while (a_cost > 0 && b_cost > 0)
	{
		ft_rr(a_stack, b_stack);
		a_cost--;
		b_cost--;
	}
	while (a_cost < 0 && b_cost < 0)
	{
		ft_rrr(a_stack, b_stack);
		a_cost++;
		b_cost++;
	}
	while (a_cost > 0)
	{
		ft_ra(a_stack);
		a_cost--;
	}
	while (a_cost < 0)
	{
		ft_rra(a_stack);
		a_cost++;
	}
	while (b_cost > 0)
	{
		ft_rb(b_stack);
		b_cost--;
	}
	while (b_cost < 0)
	{
		ft_rrb(b_stack);
		b_cost++;
	}
	ft_pb(a_stack, b_stack);
}

int	ft_cmp_int(const void *a, const void *b)
{
	int	ai;
	int	bi;

	ai = *(const int *)a;
	bi = *(const int *)b;
	return (ai - bi);
}

int	find_nth_min(t_DList *stack, int n)
{
	t_DNode	*current;
	int		*arr;
	int		i;
	int		result;

	current = stack->head;
	i = 0;
	arr = malloc(sizeof(int) * stack->size);
	if (!arr)
		return (0);
	while (current)
	{
		arr[i++] = current->value;
		current = current->next;
	}
	ft_qsort(arr, stack->size, sizeof(int), ft_cmp_int);
	result = arr[n - 1];
	free(arr);
	return (result);
}

void	push_a_to_b(t_DList *a_stack, t_DList *b_stack)
{
	int	size;
	int	median;
	int	count;
	int	min;

	size = a_stack->size;
	count = 0;
	while (a_stack->size > 3)
	{
		min = find_nth_min(a_stack, 3);
		if (a_stack->head->value < min)
			ft_ra(a_stack);
		else
		{
			ft_pb(a_stack, b_stack);
			count++;
		}
	}
	printf("push_a_to_b\n");
	test(a_stack, 1);
}

void	push_b_to_a(t_DList *a_stack, t_DList *b_stack)
{
	int	target_index;
	int	a_size;

	while (b_stack->size > 0)
	{
		target_index = find_insert_position(a_stack, head_value(b_stack));
		a_size = a_stack->size;
		if (target_index <= a_size / 2)
			while (target_index-- > 0)
				ft_ra(a_stack);
		else
			while (target_index++ < a_size)
				ft_rra(a_stack);
		ft_pa(a_stack, b_stack);
	}
}

int	get_value_at(t_DList *stack, int index)
{
	t_DNode	*current;
	int		i;

	if (index < 0 || index >= stack->size)
		return (INT_MAX);
	current = stack->head;
	i = 0;
	while (i < index && current != NULL)
	{
		current = current->next;
		i++;
	}
	if (current)
		return (current->value);
	return (INT_MAX);
}
int	find_insert_position(t_DList *stack, int value)
{
	t_DNode	*current;
	int		index;

	current = stack->head;
	index = 0;
	while (current != NULL)
	{
		if (value > current->value)
			break ;
		current = current->next;
		index++;
	}
	return (index);
}

t_move	calculate_move(t_DList *a_stack, t_DList *b_stack, int a_index)
{
	t_move	move;
	int		a_size;
	int		b_size;
	int		value;
	int		b_index;

	a_size = a_stack->size;
	b_size = b_stack->size;
	move.index_a = a_index;
	move.a_cost = (a_index <= a_size / 2) ? a_index : a_index - a_size;
	value = get_value_at(a_stack, a_index);
	b_index = find_insert_position(b_stack, value);
	move.b_cost = (b_index <= b_size / 2) ? b_index : b_index - b_size;
	move.total_cost = calculate_total_cost(move.a_cost, move.b_cost);
	return (move);
}

void	dealing_more_than_seven(t_DList *a_stack, t_DList *b_stack, int *number)
{
	push_a_to_b(a_stack, b_stack);
	test(b_stack, 1);
	dealing3(a_stack, b_stack);
	push_b_to_a(a_stack, b_stack);
	test(a_stack, 0);
}
