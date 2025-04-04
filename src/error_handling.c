#include <push_swap.h>
int search_same_number_and_coodinate_compression(int argc,char **argv) 
{
    int i;
    int j;
    int order;
    int *tmp;

    i = 0;
    j = 0;
    order = 0;
    tmp = malloc(sizeof(int)*(argc));
    if(!tmp)
    {  
        free(tmp);
        exit(1);
    }
    while (i < argc) {
        tmp[i] = ft_atoi(argv[i]);
        i++;
    }
    while(i < argc) {
        j = 0;
        while (j < argc) {
            if (tmp[i] == tmp[j] && i != j) 
            {
                printf("===================Error===================\n");
                printf("===== Please write different numbers =====\n");
                printf("===========================================\n");
                exit(1);
            }
            j++;
        }            
        coodinate_compression(tmp,&order,i);
        i++;
    }
    return (tmp);
}


void coodinate_compression(int *tmp,int *order,int i)
{
    if(tmp[i] == i)
    {
        tmp[i] = *order;
        *(order)++;
    }
}

int *error_handling_and_coodinate_compression(int argc,char **argv)
{
    if (argc < 2)
    {
        printf("===================Error===================\n");
        printf("==== Please write more than 2 numbers ====\n");
        printf("===========================================\n");
        exit(1);
    }
    return search_same_number_and_coodinate_compression(argc,argv);
}
