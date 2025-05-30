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
# include "math.h"
# include <limits.h>
# include <stdarg.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# define ERROR -1
# define NO_ERROR 1

typedef struct s_move
{
	int a_cost;
	int b_cost;
	int total_cost;
	int r;
} t_move;

void	optimize_int(t_move *move);
int	find_insert_position(t_DList *a_stack, t_DList *b_stack, int idx_b);
int	tail_value(t_DList *stack);
void	calculate_move(t_DList *a_stack, t_DList *b_stack, t_move *move);
int	*error_handling_and_coodinate_compression(int argc, char **argv);
void	populate_node_from_args(t_DList *a_stack, int argc, int *original);
void	ft_coordinate_compression(int size,int *tmp );
int	search_are_they_sorted(t_DList *a_stack, t_DList *b_stack);
t_DNode	*take_pivot(t_DList *stack);
void	push_swap(t_DList *a_stack, t_DList *b_stack, int *number,
		int number_arg);
int *search_same_number_and_coordinate_compression(int argc, char **argv);
void	dealing2(t_DList *a_stak);
void	dealing3(t_DList *a_stack);
void	dealing4(t_DList *a_stack, t_DList *b_stack, int *number,int x);
void	dealing5(t_DList *a_stack, t_DList *b_stack, int *number);
void	dealing6(t_DList *a_stack, t_DList *b_stack);
void	dealing_more_than_seven(t_DList *a_stack, t_DList *b_stack,
		int *number);
void	push_smaller_than_pivot(t_DList *a_stack, t_DList *b_stack,
		t_DNode *pivot);
void	quick_sort_a(t_DList *a, t_DList *b);
void	quick_sort_b(t_DList *a, t_DList *b);
t_DNode	*locate_node(t_DList *stack, int idx);
void	dealing(int *tmp, int size, int *sorted);
int	head_value(t_DList *stack);
int	ft_is_sorted(t_DList *stack);
void	ft_exit(t_DList *list_a, t_DList *list_b,int status);

/***********************FOR_ERROR***********************/
void exit_with_error(const char *message);

/*--------------------OPERATIONS----------------------*/
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

void	test(t_DList *stack);
#endif // PUSH_SWAP_H
