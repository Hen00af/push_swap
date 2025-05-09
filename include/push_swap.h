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

typedef struct s_stacks
{
	int		*a;
	int		*b;
	int		a_size;
	int		b_size;
	char	*join_args;
}			t_stacks;

//--------------------utils--------------------

//--------------------sort----------------------
void	radix_sort(t_stacks *s);
int	is_array_sorted(t_stacks *s);
void    sort_four_to_five_elements(t_stacks *s);
void    sort_three_elements(t_stacks *s);
//--------------------move-----------------------
void	rotate(int *array, int size, char *direction, char *list);
void push (char *str,t_stacks *s);
void    swap(char *str,int *array,int size);

//--------------------main-----------------------
void    free_and_exit_with_message(t_stacks *s,char *msg);


#endif // PUSH_SWAP_H
