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

void	search_same_number(int argc, int *tmp)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (tmp[i] == tmp[j] && i != j)
			{
				printf("===================Error===================\n");
				printf("===== Please write different numbers =====\n");
				printf("===========================================\n");
				free(tmp);
				exit(1);
			}
			j++;
		}
		i++;
	}
}

int *search_same_number_and_coordinate_compression(int argc, char **argv)
{
    int i;
    int *tmp;

    i = 0;
    tmp = malloc(sizeof(int) * argc);
    if (!tmp)
    {
        perror("Memory allocation failed");
        return NULL;  
    }
	while (i < argc - 1) {
		tmp[i] = ft_atoi(argv[i + 1]);
		printf("after atoi: %d\n", tmp[i]);
		i++;
	}
    search_same_number(argc - 1, tmp);
    ft_coordinate_compression(argc, tmp);
    return tmp;
}
