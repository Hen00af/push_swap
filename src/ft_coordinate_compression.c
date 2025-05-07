/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_coordinate_compression.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: shattori <shattori@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 04:57:16 by shattori          #+#    #+#             */
/*   Updated: 2025/05/03 01:39:14 by shattori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void dealing(int *tmp, int size, int *sorted)
{
    int i = 0;
    int j;

    while (i < size)
    {
        j = 0;
        while (j < size)
        {
            if (tmp[i] == sorted[j])
            {
                tmp[i] = j;
                break;
            }
            j++;
        }
        i++;
    }
}

void	ft_coordinate_compression(int size,int *tmp )
{
	int	i;
	int	*sorted;

	sorted = malloc(sizeof(int) * (size));
	if (!sorted)
		ft_exit(NULL, NULL, NO_ERROR);
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
