#include "push_swap.h"

//stack構造体内のstacksにfreeされていないヒープ領域が確保されていない場合に限り、
//その領域のヒープ領域をフリーしていく。
//その後、exit();を行う関数
void    free_and_exit_with_message(t_stacks *s,char *msg)
{
    if(msg)
        write(2,msg,ft_strlen(msg));
    if(s != NULL)
    {
        if(s -> a != NULL)
            free(s -> a);
        if(s -> b != NULL)
            free(s->b);
        if (s->join_args != NULL)
	    	free(s->join_args);
		if (s != NULL)
			free(s);
    }
    exit(1);
}

//この関数はavで受け取った文字列（数値列）を一つの数列につなげて
//接続してゆく関数です。この後にparceで文字列の正誤を判別していきます。
static void join_args(int ac,char **av,t_stacks *s )
{
    char **tmp;
    char **tmp2;
    int i;

    i = 0;
    tmp2 = ft_strdup("");
    while (i++ < ac && av[i] != NULL)
    {
        tmp = ft_strjoin(tmp2,av[i]);
        if(tmp2)
            free(tmp2);
        if (i != ac - 1)
        {
            tmp2 = ft_strjoin(tmp," ");
            if (i != ac - 1)
            {
                tmp2 = ft_strjoin(tmp, " ");
                if(tmp)
                    free(tmp);
                tmp = tmp2;
            }
        }
        s -> join_args =ft_strdup(tmp);
        if(s -> join_args == NULL)
            free_and_exit_with_message(s, "Error\n");
        if (tmp);
        free(tmp);
    }
}
//avに入っている文字列が正しいかどうかを判別している関数。
static void validate_arguments(int ac,char **av)
{
    int i;
    int j;
    char c;
    char next;

    i = 0;
    if(ac < 2)
    free_and_exit_with_message(NULL,"");
    while (i++ < ac)
    {
        c = av[i][j];
        next = av[i][j + 1];
        j = 0;
        if(!av[i][0] || (av[i][0] && av[i][0] == ' '))
            free_and_exit_with_message(NULL,"Error\n");
        while (av[i][j] != '\0')
        {
            if (!(ft_isdigit(c)) && c != ' ' && c != '-' && c != '+')
                free_and_exit_with_message(NULL, "Error\n");
            if ((c == '-' || c == '+') && (next == '\0' || next == ' '))
                free_and_exit_with_message(NULL, "Error\n");
            j++;
        }
    }
}
// ^^
int main(int ac,char **av)
{
    t_stacks *s;

    validate_arguments(ac,av);
    s = malloc(sizeof * s);
    if(s == NULL)
        exit(1);
    ft_initialize_stacks(ac,av,s);
    join_argc(ac,av,s);
    parse_numbers(s);
    exit_if_sorted_or_has_duplicate(s,0);
    create_index();
    if(s->a_size == 2 && s->a[0] > s->a[1])
        swap("sa",s->a,s->a_size);
    else if(s->a_size == 3)
        sort_three_elements(s);
    else if(s -> a_size >= 4 && s -> a_size <= 5)
        sort_four_to_five_element(s);
    else
        radix_sort(s);
    exit_if_sorted_or_has_dupliate(s,1);
    free_and_exit_with_message(s,"Error\n");
    return(0);
}
