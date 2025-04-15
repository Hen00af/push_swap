/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shattori <shattori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 05:51:49 by shattori          #+#    #+#             */
/*   Updated: 2025/04/15 17:36:48 by shattori         ###   ########.fr       */
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
#include <stdlib.h>
#include <limits.h>
#include <stdio.h>
#include "push_swap.h"  // 必要に応じて自分のヘッダをインクルード

int	select_direction(int idx, int list_size)
{
	if (2 * idx > list_size)
		return (idx - list_size);
	return (idx);
}

void	execute_move(t_DList *a_stack, t_DList *b_stack, t_move *move)
{
	if (move->r > 0)
		while (move->r-- > 0)
			ft_rr(a_stack, b_stack);
	else
		while (move->r++ < 0)
			ft_rrr(a_stack, b_stack);
	if (move->a_cost > 0)
		while (move->a_cost-- > 0)
			ft_ra(a_stack);
	else
		while (move->a_cost++ < 0)
			ft_rra(a_stack);
	if (move->b_cost > 0)
		while (move->b_cost-- > 0)
			ft_rb(b_stack);
	else
		while (move->b_cost++ < 0)
			ft_rrb(b_stack);
	move->a_cost = 0;
	move->b_cost = 0;
	move->total_cost = 0;
	move->r = 0;
}

int	ft_cmp_int(const void *a, const void *b)
{
	int	ai = *(const int *)a;
	int	bi = *(const int *)b;
	return (ai - bi);
}

int	find_nth_max(t_DList *stack, int n)
{
	t_DNode	*current = stack->head;
	int		*arr = malloc(sizeof(int) * stack->size);
	int		i = 0;
	int		result;

	if (!arr)
		return (0);
	while (current)
	{
		arr[i++] = current->value;
		current = current->next;
	}
	ft_qsort(arr, stack->size, sizeof(int), ft_cmp_int);
	result = arr[stack->size - 1 - n];
	free(arr);
	return (result);
}

void	push_a_to_b(t_DList *a_stack, t_DList *b_stack)
{
	int	i = 0;
	int	push_count = 0;
	int	a_val;
	int	max;

	while (a_stack->size > 3)
	{
		max = find_nth_max(a_stack, i);
		a_val = head_value(a_stack);
		if (max == a_val)
		{
			ft_ra(a_stack);
			i++;
		}
		else
		{
			ft_pb(a_stack, b_stack);
			push_count++;
		}
	}
	printf("push_a_to_b\n");
	test(a_stack, 1);
	test(b_stack, 1);
}

void	push_b_to_a(t_DList *a_stack, t_DList *b_stack)
{
	t_move	best_move;

	while (b_stack->size)
	{
		calculate_move(a_stack, b_stack, &best_move);
		execute_move(a_stack, b_stack, &best_move);
		ft_pa(a_stack, b_stack);
	}
}

t_DNode	*locate_node(t_DList *stack, int idx)
{
	t_DNode	*node = stack->head;
	int		i = 0;

	while (node && i < idx)
	{
		node = node->next;
		i++;
	}
	return (node);
}

int	find_insert_position(t_DList *a_stack, t_DList *b_stack, int idx_b)
{
	int		idx_a = 0;
	t_DNode	*curr_a;
	t_DNode	*prev_a;
	t_DNode	*elem_b = locate_node(b_stack, idx_b);

	if (!elem_b)
		return (0);
	while (idx_a < a_stack->size)
	{
		curr_a = locate_node(a_stack, idx_a);
		prev_a = locate_node(a_stack, (idx_a - 1 + a_stack->size) % a_stack->size);
		if (!curr_a || !prev_a)
			break;
		if (prev_a->value < elem_b->value && elem_b->value < curr_a->value)
			return (idx_a);
		if ((prev_a->value > curr_a->value) &&
			(elem_b->value > prev_a->value || elem_b->value < curr_a->value))
			return (idx_a);
		idx_a++;
	}
	return (0);
}

void	optimize_int(t_move *move)
{
	if (move->a_cost > 0 && move->b_cost > 0)
	{
		move->r = ft_min(move->a_cost, move->b_cost);
		move->a_cost -= move->r;
		move->b_cost -= move->r;
	}
	else if (move->a_cost < 0 && move->b_cost < 0)
	{
		move->r = ft_max(move->a_cost, move->b_cost);
		move->a_cost -= move->r;
		move->b_cost -= move->r;
	}
	else
		move->r = 0;
	move->total_cost = ft_abs(move->a_cost) + ft_abs(move->b_cost) + ft_abs(move->r);
}

void	update_cnt(t_move *tmp, t_move *best_move)
{
	static int total = INT_MAX;

	if (tmp->b_cost == 0)
		total = INT_MAX;
	optimize_int(tmp);
	if (tmp->total_cost < total)
	{
		total = tmp->total_cost;
		*best_move = *tmp;
	}
}

void	calculate_move(t_DList *a_stack, t_DList *b_stack, t_move *move)
{
	int		idx_b = 0;
	t_move	tmp_move;

	while (idx_b < b_stack->size)
	{
		tmp_move.a_cost = find_insert_position(a_stack, b_stack, idx_b);
		tmp_move.a_cost = select_direction(tmp_move.a_cost, a_stack->size);
		tmp_move.b_cost = select_direction(idx_b, b_stack->size);
		tmp_move.total_cost = 0;
		tmp_move.r = 0;
		update_cnt(&tmp_move, move);
		idx_b++;
	}
}
void	check(t_DList *a_stack)
{
	t_DNode *current = a_stack->head;
	int min_value = current->value;
	int min_index = 0;
	int i = 0;

	while (current)
	{
		if (current->value < min_value)
		{
			min_value = current->value;
			min_index = i;
		}
		current = current->next;
		i++;
	}
	if (min_index <= a_stack->size / 2)
	{
		while (min_index-- > 0)
			ft_ra(a_stack);
	}
	else
	{
		int rra_count = a_stack->size - min_index;
		while (rra_count-- > 0)
			ft_rra(a_stack);
	}
}


void	dealing_more_than_seven(t_DList *a_stack, t_DList *b_stack, int *number)
{
	push_a_to_b(a_stack, b_stack);
	test(b_stack, 1);
	dealing3(a_stack, b_stack);
	push_b_to_a(a_stack, b_stack);
	check(a_stack);
	test(a_stack, 0);

}
