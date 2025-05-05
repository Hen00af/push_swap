/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_coordinate_compression.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shattori <shattori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 04:57:16 by shattori          #+#    #+#             */
/*   Updated: 2025/04/20 22:26:51 by shattori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	dealing(int *tmp, int size, int *sorted)
{
	for (int i = 0; i < size; i++)
	{
		for (int j = 0; j < size; j++)
		{
			if (tmp[i] == sorted[j])
			{
				tmp[i] = j;
				break ;
			}
		}
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
