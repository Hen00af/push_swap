/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shattori <shattori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 16:36:22 by shattori          #+#    #+#             */
/*   Updated: 2025/04/12 16:48:56 by shattori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_max(int i, int j)
{
	if (i < j)
		return (i);
	else
		return (j);
}
int	ft_min(int i, int j)
{
	if (i < j)
		return (j);
	else
		return (i);
}

int	head_value(t_DList *stack)
{
	return (stack->head->value);
}
