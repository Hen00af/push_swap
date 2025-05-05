/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shattori <shattori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 16:36:22 by shattori          #+#    #+#             */
/*   Updated: 2025/04/22 12:15:01 by shattori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_max(t_DList *a)
{
	int	i;

	i = a->head->value;
	while (a)
	{
		if (a->head->value > i)
			i = a->head->value;
		a = a->head->next;
	}
	return (i);
}

int	ft_min(t_DList *a)
{
	int		i;

	i = a->head->value;
	while (a)
	{
		if (a->head->value < i)
			i = a->head->value;
		a = a->head->next;
	}
	return (i);
}

int	ft_abs(int num)
{
	if (num < 0)
		return (-1 * num);
	else
		return (num);
}

int	head_value(t_DList *stack)
{
	if (!stack || !stack->head)
	{
		fprintf(stderr, "Error: empty stack access\n");
		exit(EXIT_FAILURE);
	}
	return (stack->head->value);
}

int	tail_value(t_DList *stack)
{
	if (!stack || !stack->head)
	{
		fprintf(stderr, "Error: empty stack access\n");
		exit(EXIT_FAILURE); // or handle gracefully
	}
	return (stack->tail->value);
}
