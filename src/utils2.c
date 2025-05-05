/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shattori <shattori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/22 09:51:47 by shattori          #+#    #+#             */
/*   Updated: 2025/04/22 12:35:01 by shattori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_is_sorted(t_DList *stack)
{
	t_DNode	*current;

	current = stack->head;
	while (current && current->next)
	{
		if (current->value > current->next->value)
			return (1);
		current = current->next;
	}
	return (0);
}

int	ft_find_index(t_DList *stack, int nbr)
{
	int		i;
	t_DNode	*current;

	current = stack->head;
	i = 0;
	while (current != nbr)
	{
		i++;
		current = current->next;
	}
	current->index = 0;
	return (i);
}

int	ft_find_place_a(t_DList *a_stack, int nbr_push)
{
	int i;
	t_DList *tmp;

	i = 1;
	if (nbr_push < a_stack->head->value
		&& nbr_push > nbr_push > head_value(a_stack))
		i = 0;
	else if (nbr_push > ft_max(a_stack) || nbr_push < ft_min(a_stack))
		i = ft_find_index(a_stack, ft_min(a_stack));
	else
	{
		tmp = a_stack->head->next;
		while (a_stack->head->value || tmp->head->value)
		{
			if (nbr_push > a_stack->head->value && nbr_push < tmp->head->value)
				break ;
			tmp = tmp->head->next;
			i++;
		}
	}
}
