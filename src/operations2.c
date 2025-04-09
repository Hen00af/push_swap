/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shattori <shattori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 05:48:07 by shattori          #+#    #+#             */
/*   Updated: 2025/04/10 08:19:18 by shattori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_rb(t_DList *b_stack)
{
	t_DNode	*tmp;

	if (b_stack->head == NULL || b_stack->head->next == NULL)
		return ;
	tmp = b_stack->head;
	b_stack->head = b_stack->head->next;
	b_stack->head->prev = NULL;
	tmp->next = NULL;
	b_stack->tail->next = tmp;
	tmp->prev = b_stack->tail;
	b_stack->tail = tmp;
	ft_putstr_fd("rb\n", 1);
}

void	ft_rra(t_DList *a_stack)
{
	t_DNode	*tmp;

	if (a_stack->head == NULL || a_stack->head->next == NULL)
		return ;
	tmp = a_stack->tail;
	a_stack->tail = tmp->prev;
	a_stack->tail->next = NULL;
	tmp->prev = NULL;
	tmp->next = a_stack->head;
	a_stack->head->prev = tmp;
	a_stack->head = tmp;
	ft_putstr_fd("rra\n", 1);
}

void	ft_rrb(t_DList *b_stack)
{
	t_DNode	*tmp;

	if (b_stack->head == NULL || b_stack->head->next == NULL)
		return ;
	tmp = b_stack->tail;
	b_stack->tail = b_stack->tail->prev;
	b_stack->tail->next = NULL;
	tmp->prev = NULL;
	tmp->next = b_stack->head;
	b_stack->head->prev = tmp;
	b_stack->head = tmp;
	ft_putstr_fd("rrb\n", 1);
}

void	ft_ss(t_DList *a_stack, t_DList *b_stack)
{
	ft_sa(a_stack);
	ft_sb(b_stack);
	ft_putstr_fd("ss\n", 1);
}

void	ft_rr(t_DList *a_stack, t_DList *b_stack)
{
	ft_ra(a_stack);
	ft_rb(b_stack);
	ft_putstr_fd("rr\n", 1);
}
