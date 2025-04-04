#include "../libft/libft.h"
//base is the pointer to the array to be sorted
//num is the number of elements in the array
//size is the size of each element in the array
//cmp is the comparison function that takes two pointers to elements and returns an integer
// void ft_qsort(void *base, size_t num, size_t size, int (*cmp)(const void *, const void *))

void ft_swap(void *a, void *b, size_t size) {
    unsigned char tmp[size];
    ft_memcpy(tmp, a, size);
    ft_memcpy(a, b, size);
    ft_memcpy(b, tmp, size);
}

int ft_compare_int(const void *a, const void *b) {
    return (*(int *)a - *(int *)b);
}
size_t partition(void *base, size_t num, size_t size, int (*cmp)(const void *, const void *)) {
    char *arr = (char *)base;
    void *pivot = arr + (num - 1) * size;
    size_t i = 0;

    for (size_t j = 0; j < num - 1; j++) {
        if (cmp(arr + j * size, pivot) < 0) { 
            ft_swap(arr + i * size, arr + j * size, size);
            i++;
        }
    }
    ft_swap(arr + i * size, pivot, size);
    return i;
}

void ft_qsort(void *base, size_t num, size_t size, int (*cmp)(const void *, const void *)) {
    if (num < 2) return;
    size_t pivot_index = partition(base, num, size, cmp);
    ft_qsort(base, pivot_index, size, cmp);
    ft_qsort((char *)base + (pivot_index + 1) * size, num - pivot_index - 1, size, cmp);
}

int  main()
{
    int data[] ={ 5, 2, 9, 1, 5, 6 };
    int i;

    ft_qsort(data, sizeof(data) / sizeof(data[0]), sizeof(int), ft_compare_int);
    for(int i = 0;i < sizeof(data) / sizeof(data[0]); i++)
    printf("%3d",data[i]);
    printf("\n");
    return 0;
}   