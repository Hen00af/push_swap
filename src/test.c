#include <stdio.h>
#include <stdlib.h>

typedef struct stack_s
{
    int value;              // ノードの値
    struct stack_s *next;   // 次のノードへのポインタ
    struct stack_s *prev;   // 前のノードへのポインタ
} stack_t;

typedef struct stack_info_s
{
    stack_t *head;  // リストの先頭
    stack_t *tail;  // リストの末尾
    int length;     // ノードの数
} stack_info_t;

stack_t *create_node(int value){
    stack_t *new_node = (stack_t *)malloc(sizeof(stack_t));
    if(!new_node) return NULL;
    new_node->value = value;
    new_node->next = NULL;
    new_node->prev = NULL;
    return new_node;
}

int main() {
    stack_info_t *list = create_dlist();

    add_front(list, 10);
    add_front(list, 20);
    add_back(list, 30);
    add_back(list, 40);

    print_list_forward(list);
    print_list_behind(list);
    printf("\n");

    free_list(list);
    return 0;
}
