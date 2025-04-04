#include <stdio.h>
#include <stdlib.h>
int main(int argc,char **argv) 
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
    while (i < argc - 1) {
        tmp[i] = atoi(argv[i+1]);
        i++;
    }
    while(i < argc-1) {
        j = 0;
        while (j < argc-1) {
            if (tmp[i] == tmp[j] && i != j) 
            {
                printf("===================Error===================\n");
                printf("===== Please write different numbers =====\n");
                printf("===========================================\n");
                exit(1);
            }
            j++;
        }            
        i++;
    }
    i = 0;
    while (i < argc - 1) {
        printf("tmp[%d]: %d\n", i, tmp[i]);
        i++;
    }
    return (0);
}
