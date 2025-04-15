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

int	calculate_total_cost(int a_cost, int b_cost)
{
	if ((a_cost >= 0 && b_cost >= 0) || (a_cost < 0 && b_cost < 0))
		return (ft_max(a_cost, b_cost));
	return (a_cost + b_cost);
}

int	select_direction(int idx, int list_size)
{
	if (2 * idx > list_size)
		return (idx - list_size);
	return (idx);
}

int	find_cheapest_move(t_DList *a_stack, t_DList *b_stack, t_move best_move)
{
	int		idx_b;
	t_move	tmp_move;

	idx_b = 0;
	// while ()
	// {
	// 	tmp_move.a_cost = find_insert_position(a_stack, b_stack, idx_b);
	// 	tmp_move.a_cost = select_direction(tmp_move.a_cost, a_stack->size);
	// 	tmp_move.b_cost = select_direction(idx_b, b_stack->size);
	// 	tmp_move.total_cost = 0;
	// }
}

void	execute_move(t_DList *a_stack, t_DList *b_stack, t_move move)
{
	int	a_cost;
	int	b_cost;

	a_cost = 1;
	b_cost = 1;
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

int	is_target_for_pb(int value)
{
	return (value == 0 || value == 1 || value == 2);
}

void	judge_how_to_pb(t_DList *a_stack, t_DList *b_stack, int *push_count)
{
	int	a_val;

	a_val = head_value(a_stack);
	if (!is_target_for_pb(a_val) || b_stack->size != 0)
	{
		if (tail_value(b_stack) < head_value(b_stack)
			&& b_stack->head->value != 0)
			ft_rr(a_stack, b_stack);
		else
			ft_ra(a_stack);
	}
	else
	{
		ft_pb(a_stack, b_stack);
		(*push_count)++;
	}
}

void	push_a_to_b(t_DList *a_stack, t_DList *b_stack)
{
	int	push_count;
	int	a_val;

	push_count = 0;
	while (a_stack->size > 3)
	{
		a_val = head_value(a_stack);
		ft_pb(a_stack,b_stack);
		printf("%d",b_stack->size);
		if (!is_target_for_pb(a_val) || b_stack->size > 0)
		{
			if (tail_value(b_stack) < head_value(b_stack))
			{
				printf("%d", b_stack->head->value);
				ft_rr(a_stack, b_stack);
			}
			else
			{
				ft_ra(a_stack);
				printf("%d", b_stack->size);
			}
		}
			ft_pb(a_stack, b_stack);
			push_count++;
		
	}
	printf("push_a_to_b\n");
	test(a_stack, 1);
}

void	push_b_to_a(t_DList *a_stack, t_DList *b_stack)
{
	t_move	best_move;

	// while (b_stack->size > 0)
	// {
	// 	calculate_move();
	// 	find_cheapest_move(a_stack, b_stack, best_move);
	// 	printf("best.a;%d\nbest.b%d\n", best_move.a_cost, best_move.b_cost);
	// 	execute_move(a_stack, b_stack, best_move);
	// 	b_stack->size--;
	// }
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

void	locate_node(t_DNode *node, t_DList *stack, int idx_b)
{
	int	i;

	i = 0;
	node = stack->head;
	while (i < idx_b)
	{
		node = node->next;
		i++;
	}
}

int	find_insert_position(t_DList *a_stack, t_DList *b_stack, int idx_b)
{
	int		idx_a;
	t_DNode	*curr_a;
	t_DNode	*prev_a;
	t_DNode	*elem_b;

	idx_a = 0;
	locate_node(elem_b, b_stack, idx_b);
	while (idx_a < a_stack->size)
	{
		locate_node(curr_a, a_stack, idx_b);
		locate_node(prev_a, a_stack, idx_a - 1);
		if (prev_a->value < elem_b->value && prev_a < elem_b)
			return (idx_a);
		if (prev_a->value < curr_a->value)
			if (elem_b->next < curr_a->next
				|| prev_a->prev->value < elem_b->value)
				return (idx_a);
		idx_a++;
	}
	return (idx_a);
}

t_move	calculate_move(t_DList *a_stack, t_DList *b_stack, int a_index)
{
	int		idx_b;
	t_move	tmp_move;

	// idx_b = 0;
	// while ()
	// {
	// }
}

void	dealing_more_than_seven(t_DList *a_stack, t_DList *b_stack, int *number)
{
	push_a_to_b(a_stack, b_stack);
	test(b_stack, 1);
	dealing3(a_stack, b_stack);
	// push_b_to_a(a_stack, b_stack);
	test(a_stack, 0);
}
