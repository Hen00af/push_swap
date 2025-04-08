/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shattori <shattori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 06:09:33 by shattori          #+#    #+#             */
/*   Updated: 2025/04/08 16:37:42 by shattori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	push_swap(t_DList *a_stack, t_DList *b_stack, int *number,
		int number_arg)
{
	if (number_arg == 2)
		dealing2(a_stack, b_stack, number);
	else if (number_arg == 3)
		dealing3(a_stack, b_stack, number);
	// else if (number_arg == 4)
	// 	dealing4(a_stack, b_stack, number);
	// else if (number_arg == 5)
	// 	dealing5(a_stack, b_stack);
	// else
	// 	dealing_more_than_five(a_stack, b_stack);
}
