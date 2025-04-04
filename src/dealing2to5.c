/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dealing2to5.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shattori <shattori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 06:25:27 by shattori          #+#    #+#             */
/*   Updated: 2025/04/05 06:58:17 by shattori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	dealing2(t_DList *a_stack, t_DList *b_stack, int *number)
{
	if (number[0] > number[1])
		ft_sa(a_stack);
}

void	dealing3(t_DList *a_stack, t_DList *b_stack, int *number)
{
	if (number[2] < number[1] && number[1] < number[0])
	{
		ft_sa(a_stack);
		ft_rra(a_stack);
	}
	else if (number[2] < number[0] && number[0] < number[1])
		ft_rra(a_stack);
	else if (number[1] < number[0] && number[0] < number[2])
	{
		ft_sa(a_stack);
		ft_ra(a_stack);
	}
	else if (number[1] < number[2] && number[2] < number[0])
		ft_ra(a_stack);
	else if (number[0] < number[1] && number[1] < number[2])
		return ;
}

void	dealing4(t_DList *a_stack, t_DList *b_stack, int *number)
{
	if (number[3] < number[2] < number[1] < number[0])
	{
		ft_sa(a_stack);
		ft_rra(a_stack);
	}
}
