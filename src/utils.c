/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shattori <shattori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 16:36:22 by shattori          #+#    #+#             */
/*   Updated: 2025/05/02 19:01:15 by shattori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"


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