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

void	check_for_duplicates(int *tmp, int argc)
{
    int	i;
    int	j;

    i = 0;
    while (i < argc)
    {
        j = i + 1;
        while (j < argc)
        {
            if (tmp[i] == tmp[j]){
                exit_with_error("===== Please write different numbers =====");
				free(tmp);
			}
            j++;
        }
        i++;
    }
}

int	*search_same_number_and_coodinate_compression(int argc, char **argv)
{
	int i;
	int size;
	int *tmp;

	i = 0;
	size = argc - 1;
	tmp = malloc(sizeof(int) * (argc));
	if (!tmp)
		exit(1);
	while (i < size)
	{
		tmp[i] = ft_atoi(argv[i + 1]);
		i++;
	}
	check_for_duplicates(tmp,size);
	ft_coordinate_compression(tmp, i);
	return (tmp);
}
