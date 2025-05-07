#include "push_swap.h"

void exit_with_error(const char *message)
{
    printf("===================Error===================\n");
    printf("%s\n", message);
    printf("===========================================\n");
    exit(1);
}

void	ft_exit(t_DList *list_a, t_DList *list_b,int status)
{
    if(list_a)
	    ft_free_list(list_a);
    if(list_b)
	    ft_free_list(list_b);
	if (status == NO_ERROR)
		exit(0);
	(void)write(2, "Error\n", 6);
	exit(status);
}
