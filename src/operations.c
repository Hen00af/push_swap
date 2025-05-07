/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   operations.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shattori <shattori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 05:18:22 by shattori          #+#    #+#             */
/*   Updated: 2025/04/28 08:45:27 by shattori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_sa(t_DList *a_stack)
{
	int	tmp;

	if (a_stack->head == NULL || a_stack->head->next == NULL)
		return ;
	tmp = head_value(a_stack);
	a_stack->head->value = a_stack->head->next->value;
	a_stack->head->next->value = tmp;
	ft_putstr_fd("sa\n", 1);
}

void	ft_sb(t_DList *b_stack)
{
	int	tmp;

	if (b_stack->head == NULL || b_stack->head->next == NULL)
		return ;
	tmp = b_stack->head->value;
	b_stack->head->value = b_stack->head->next->value;
	b_stack->head->next->value = tmp;
	ft_putstr_fd("sb\n", 1);
}

void	ft_pa(t_DList *a_stack, t_DList *b_stack)
{
	t_DNode	*tmp;

	if (b_stack->head == NULL)
		return ;
	tmp = b_stack->head;
	b_stack->head = b_stack->head->next;
	if (b_stack->head != NULL)
		b_stack->head->prev = NULL;
	else
		b_stack->tail = NULL;
	tmp->next = a_stack->head;
	if (a_stack->head != NULL)
		a_stack->head->prev = tmp;
	a_stack->head = tmp;
	if (a_stack->tail == NULL)
		a_stack->tail = tmp;
	a_stack->size++;
	b_stack->size--;
	ft_putstr_fd("pa\n", 1);
}

void	ft_pb(t_DList *a_stack, t_DList *b_stack)
{
	t_DNode	*tmp;

	if (a_stack->head == NULL)
		return ;
	tmp = a_stack->head;
	a_stack->head = a_stack->head->next;
	if (a_stack->head != NULL)
		a_stack->head->prev = NULL;
	else
		a_stack->tail = NULL;
	tmp->next = b_stack->head;
	if (b_stack->head != NULL)
		b_stack->head->prev = tmp;
	tmp->prev = NULL;
	b_stack->head = tmp;
	if (b_stack->tail == NULL)
		b_stack->tail = tmp;
	a_stack->size--;
	b_stack->size++;
	ft_putstr_fd("pb\n", 1);
}

void	ft_ra(t_DList *a_stack)
{
	t_DNode	*tmp;

	if (a_stack->head == NULL || a_stack->head->next == NULL)
		return ;
	tmp = a_stack->head;
	a_stack->head = a_stack->head->next;
	a_stack->head->prev = NULL;
	tmp->next = NULL;
	a_stack->tail->next = tmp;
	tmp->prev = a_stack->tail;
	a_stack->tail = tmp;
	ft_putstr_fd("ra\n", 1);
}
