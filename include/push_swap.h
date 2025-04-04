/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: shattori <shattori@student.42.fr>          +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2025/04/05 04:46:58 by shattori          #+#    #+#             */
/*   Updated: 2025/04/05 04:46:58 by shattori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H

# include "../libft/libft.h"
# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# define ERROR -1
int	*error_handling_and_coodinate_compression(int argc, char **argv);
void	populate_node_from_args(t_DList *a_stack, int argc, int *original);
void	ft_coordinate_compression(int *tmp, int i);
void	push_swap(t_DList *a_stack, t_DList *b_stack, int *number,
		int number_arg);
void	dealing2(t_DList *a_stack, t_DList *b_stack, int *number);
void	dealing3(t_DList *a_stack, t_DList *b_stack, int *number);
void	dealing4(t_DList *a_stack, t_DList *b_stack, int *number);

void	ft_pa(t_DList *a_stack, t_DList *b_stack);
void	ft_pb(t_DList *a_stack, t_DList *b_stack);
void	ft_sa(t_DList *a_stack);
void	ft_sb(t_DList *b_stack);
void	ft_ss(t_DList *a_stack, t_DList *b_stack);
void	ft_ra(t_DList *a_stack);
void	ft_rb(t_DList *b_stack);
void	ft_rr(t_DList *a_stack, t_DList *b_stack);
void	ft_rra(t_DList *a_stack);
void	ft_rrb(t_DList *b_stack);
void	ft_rrr(t_DList *a_stack, t_DList *b_stack);
void	sa(t_DList *afnc);
void	sb(t_DList *bfnc);

#endif // PUSH_SWAP_H
