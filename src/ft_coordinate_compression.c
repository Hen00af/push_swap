/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_coordinate_compression.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shattori <shattori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 04:57:16 by shattori          #+#    #+#             */
/*   Updated: 2025/04/05 05:04:04 by shattori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	dealing(int *tmp, int size, int *sorted)
{
	int	i;
	int	j;

	i = 0;
	while (i < size)
	{
		j = 0;
		while (j < size)
		{
			if (tmp[i] == sorted[j])
			{
				tmp[i] = j;
				break ;
			}
			j++;
		}
		i++;
	}
}

void	ft_coordinate_compression(int *tmp, int size)
{
	int	i;
	int	*sorted;

	sorted = malloc(sizeof(int) * (size));
	if (!sorted)
		exit(1);
	i = 0;
	while (i < size)
	{
		sorted[i] = tmp[i];
		i++;
	}
	ft_qsort(sorted, size, sizeof(int), ft_compare_int);
	i = 0;
	dealing(tmp, size, sorted);
	free(sorted);
}
