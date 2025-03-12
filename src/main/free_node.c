#include "libft.h"

void free_node(DList *list) {
    DNode *current = list->head;
    while (current){
        DNode *next = current->next;
        free(current);
        current = next;
    }
    free(list);
}