/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shattori <shattori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 16:36:22 by shattori          #+#    #+#             */
/*   Updated: 2025/04/15 14:26:44 by shattori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_max(int i, int j)
{
	if (i < j)
		return (j);
	else
		return (i);
}
int	ft_min(int i, int j)
{
	if (i < j)
		return (i);
	else
		return (j);
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
int tail_value(t_DList *stack)
{
	if (!stack || !stack->head)
	{
		fprintf(stderr, "Error: empty stack access\n");
		exit(EXIT_FAILURE); // or handle gracefully
	}
	return (stack->tail->value);
}
