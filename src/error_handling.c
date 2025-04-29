/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_handling.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+
	+:+     */
/*   By: shattori <shattori@student.42.fr>          +#+  +:+
	+#+        */
/*                                                +#+#+#+#+#+
	+#+           */
/*   Created: 2025/04/05 04:58:26 by shattori          #+#    #+#             */
/*   Updated: 2025/04/05 04:58:26 by shattori         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <push_swap.h>


int	*search_same_number_and_coodinate_compression(int argc, char **argv)
{
	int i;
	int j;
	int *tmp;

	i = 0;
	j = 0;
	tmp = malloc(sizeof(int) * (argc));
	if (!tmp)
		exit(1);
	while (i < argc)
	{
		tmp[i] = ft_atoi(argv[i]);
		i++;
	}
	i = 0;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (tmp[i] == tmp[j] && i != j)
			{
				exit_with_error("===== Please write different numbers =====");
			}
			j++;
		}
		i++;
	}
	ft_coordinate_compression(tmp, i);
	return (tmp);
}

int	*error_handling_and_coodinate_compression(int argc, char **argv)
{
	if (argc < 2)
	{
		printf("===================Error===================\n");
		printf("==== Please write more than 2 numbers ====\n");
		printf("===========================================\n");
		exit(1);
	}
	return (search_same_number_and_coodinate_compression(argc, argv));
}
