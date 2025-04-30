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

int binary_search(int *arr,int size,int target)
{
	int left;
	int right;
	int mid;

	left=0;
	right = size - 1;
	while(left <= right)
	{
		mid = (left + right) / 2;
		if(arr[mid] == target)
			return(mid);
		else if(arr[mid] < target)
			left = mid + 1;
		else
		right = mid - 1;
	}
	return(-1);
}

void	dealing(int *tmp, int size, int *sorted)
{
	int i;
	i = 0;
	while(i < size)
	{
		tmp[i] = binary_search(sorted,size,tmp[i]);
		i++;
	}
}

void	ft_coordinate_compression(int *tmp, int size)
{
	int	i;
	int	*sorted;

	sorted = malloc(sizeof(int) * (size));
	if (!sorted){
		ft_perror("failed malloc");
		exit(1);
	}
	i = 0;
	while (i < size)
	{
		sorted[i] = tmp[i];
		i++;
	}
	ft_qsort(sorted, size, sizeof(int), ft_compare_int);
	dealing(tmp, size, sorted);
	free(sorted);
}
