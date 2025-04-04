#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main (int ac,char **av)
{
    char *tmp;

    tmp = malloc(sizeof(char) * (ac - 5 ));
    if (!tmp)
    {
        free(tmp);
        exit(1);
    }

    printf("ac: %d\n", ac);

    for(int i = 0; i < ac; i++)
    {
        tmp[i] = av[i][0];
    }
    for(int i = 0; i < ac; i++)
    {
        printf("tmp[%d]: %c\n", i, tmp[i]);
    }

    free(tmp);
    return (0);
}