#include "push_swap.h"

void create_index(t_stacks *s)
{
    int i;
    int j;
    int k;
    int *new_a;

    new_a = malloc(s->a_size * sizeof * new_a);
    if(new_a == NULL)
        free_and_exit_with_message(s,"Error\n");
    i = -1;
    while (++i < s -> a_size)
    {
        k = 0;
        j = -1;
        while (j ++ < s->a_s)
    }
}

int ft_atol(const char *n, t_stacks *s)
{
    int i;
    long sign;
    long long res;

    res =0;
    sign = 1;
    i = 0;
    while(n[i] == ' ' || (n[i] >= '\t'))
        i++;
    if((n[i] == '+' || n[i] == '-'))
    {
        if( n[i] == '-')
            sign = -1;
        i++;
    }
    while (n[i])
    {
        if(res > INT_MAX || (res * sign) < INT_MIN || ft_strlen(n) > 11)
            free_and_exit_with_message(s,"Error\n");
        if(!(n[i] >= '0' && n[i] <= '9'))
            free_and_exit_with_message(s,"Error\n");
        res = res *10 + (n[i++] - '0');
    }
    return ((int)(res * sign));

}

void parse_number(t_stacks *s)
{
    char **tmp;
    int i;
    int z;

    z = 0;
    tmp = ft_split(s->join_args, ' ');
    i = 0;
    while (tmp[i] != NULL && tmp[i][0] != '\0')
    {
        s->a[z++] = ft_ato
    }
}
