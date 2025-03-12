#include <stdio.h>
int main ()
{
    int m;
    m = 100;
    int *ptr;
    ptr = &m;

    printf("The Value of Variable m is : %d\n",m);
    printf("The Memory Address of Variable m is: %p\n",&m);
    printf("The Memory Address of Variable m is using ptr: %p\n",ptr);

    return(0);
}