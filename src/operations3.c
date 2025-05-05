/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations3.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shattori <shattori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 05:51:49 by shattori          #+#    #+#             */
/*   Updated: 2025/04/24 07:44:56 by shattori         ###   ########.fr       */
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

	if (ft_is_sorted(a_stack))
		return (0);
	if (ft_is_sorted(b_stack))
		return (0);
	return (1);
}

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
	int	ai;
	int	bi;

	ai = *(const int *)a;
	bi = *(const int *)b;
	return (ai - bi);
}

int	find_nth_max(t_DList *stack, int n)
{
	t_DNode	*current;
	int		*arr;
	int		i;
	int		result;

	current = stack->head;
	arr = malloc(sizeof(int) * stack->size);
	i = 0;
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

int	ft_case_rarb(t_DList *a_stack, t_DList *b_stack, int c)
{
	int	i;

	i = ft_find_place_a(a_stack, c);
	if (i < ft_find_index(a_stack, b_stack))
		i = ft_find_index(a_stack, b_stack);
	return (i);
}

int	ft_case_rrarrb(t_DList *a, t_DList *b, int c)
{
	int	i;

	i = 0;
	if (ft_find_place_b(b, c))
		i = ft_lstsize(b) - ft_find_place_b(b, c);
	if ((i < (ft_lstsize(a) - ft_find_index(a, c))) && ft_find_index(a, c))
		i = ft_lstsize(a) - ft_find_index(a, c);
	return (i);
}

void	ft_case_rrarrb(t_DList *a, t_DList *b, int c)
{
	int	i;

	i = 0;
	if (ft_find_place_b(a, c))
		i = ft_lstsize(b) - ft_find_place_b(a, c);
	i = ft_find_index(b, c) + i;
	return (i);
}
// culculate how can i move b to a most efficiently
int	ft_calculate_b_to_a(t_DList *a_stack, t_DList *b_stack)
{
	int		i;
	t_DNode	*tmp;
	int		val;

	tmp = a_stack->head;
	i = ft_case_rrarrb(a_stack, b_stack, tmp->value);
	while (tmp)
	{
		val = tmp->value;
		if (i > ft_case_rarb(a_stack, b_stack, val))
			i = ft_case_rarb(a_stack, b_stack, val);
		if (i > ft_case_rrarrb(a_stack, b_stack, val))
			i = ft_case_rrarrb(a_stack, b_stack, val);
		if (i > ft_case_rarrb(a_stack, b_stack, val))
			i = ft_case_rarrb(a_stack, b_stack, val);
		if (i > ft_case_rrarb(a_stack, b_stack, val))
			i = ft_case_rrarb(a_stack, b_stack, val);
		tmp = tmp->next;
	}
	return (i);
}
// calculate how can i move a to b most efficiently
int	ft_calculate_a_to_b(t_DList *a_stack, t_DList *b_stack)
{
	int		i;
	t_DNode	*tmp;
	int		val;

	tmp = a_stack->head;
	i = ft_case_rrarrb(a_stack, b_stack, tmp->value);
	while (tmp)
	{
		val = tmp->value;
		if (i > ft_case_rarb(a_stack, b_stack, val))
			i = ft_case_rarb(a_stack, b_stack, val);
		if (i > ft_case_rrarrb(a_stack, b_stack, val))
			i = ft_case_rrarrb(a_stack, b_stack, val);
		if (i > ft_case_rarrb(a_stack, b_stack, val))
			i = ft_case_rarrb(a_stack, b_stack, val);
		if (i > ft_case_rrarb(a_stack, b_stack, val))
			i = ft_case_rrarb(a_stack, b_stack, val);
		tmp = tmp->next;
	}
	return (i);
}

void	pb_untill_3(t_DList *a_stack, t_DList *b_stack)
{
	int		i;
	t_DList	*tmp;

	while (ft_lstsize(a_stack) > 3 && !ft_is_sorted(a_stack))
	{
		tmp = a_stack;
		i = ft_calculate_a_to_b(a_stack, b_stack);
		while(i >= 0)
		{
			if(i == ft_case_rarb(a_stack,b_stack,head_value(tmp)))
				i = ft_apply_rarb(a_stack, b_stack);
		}
	}
}

t_DList	*push_a_to_b(t_DList *a_stack, t_DList *b_stack, int *number)
{
	if (!ft_is_sorted(a_stack))
		ft_pb(a_stack, b_stack);
	if (ft_lstsize(a_stack) > 3 && !ft_is_sorted(a_stack))
		ft_pb(a_stack, b_stack);
	if (ft_lstsize(a_stack) > 3 && !ft_is_sorted(a_stack))
		pb_untill_3(a_stack, b_stack);
	if (ft_is_sorted(a_stack))
		dealing3(a_stack, b_stack);
	return (b_stack);
}

t_DList **ft_sort_a(t_DList *a_stack, t_DList *stack_b)
{
	
}

void	push_b_to_a(t_DList *a_stack, t_DList *b_stack)
{
	int i;
	t_DList *tmp;

	while (b_stack->size)
	{
		tmp = b_stack->head;
		i =ft_rotate_type_ba();
		calculate_move(a_stack, b_stack, &best_move);
		execute_move(a_stack, b_stack, &best_move);
		ft_pa(a_stack, b_stack);
	}
}

t_DNode	*locate_node(t_DList *stack, int idx)
{
	t_DNode	*node;
	int		i;

	node = stack->head;
	i = 0;
	while (node && i < idx)
	{
		node = node->next;
		i++;
	}
	return (node);
}

int	find_insert_position(t_DList *a_stack, t_DList *b_stack, int idx_b)
{
	int		idx_a;
	t_DNode	*curr_a;
	t_DNode	*prev_a;
	t_DNode	*elem_b;

	idx_a = 0;
	elem_b = locate_node(b_stack, idx_b);
	if (!elem_b)
		return (0);
	while (idx_a < a_stack->size)
	{
		curr_a = locate_node(a_stack, idx_a);
		prev_a = locate_node(a_stack, (idx_a - 1 + a_stack->size)
				% a_stack->size);
		if (!curr_a || !prev_a)
			break ;
		if (prev_a->value < elem_b->value && elem_b->value < curr_a->value)
			return (idx_a);
		if ((prev_a->value > curr_a->value) && (elem_b->value > prev_a->value
				|| elem_b->value < curr_a->value))
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
	move->total_cost = ft_abs(move->a_cost) + ft_abs(move->b_cost)
		+ ft_abs(move->r);
}

void	update_cnt(t_move *tmp, t_move *best_move)
{
	static int	total = INT_MAX;

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
	int		idx_b;
	t_move	tmp_move;

	idx_b = 0;
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
	t_DNode	*current;
	int		min_value;
	int		min_index;
	int		i;
	int		rra_count;

	current = a_stack->head;
	min_value = current->value;
	min_index = 0;
	i = 0;
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
		rra_count = a_stack->size - min_index;
		while (rra_count-- > 0)
			ft_rra(a_stack);
	}
}

void	dealing_more_than_seven(t_DList *a_stack, t_DList *b_stack, int *number)
{
	push_a_to_b(a_stack, b_stack, number);
	dealing3(a_stack, b_stack);
	push_b_to_a(a_stack, b_stack);
	check(a_stack);
}
