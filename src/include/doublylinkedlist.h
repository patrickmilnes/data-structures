#include <stddef.h>

typedef struct node
{
    struct node* next;
    struct node* prev;
    void* payload;
} node_t;

typedef struct
{
    struct Node* head;
    struct Node* tail;
    int length;
} doubly_linked_list_t;

doubly_linked_list_t* init_doubly_linked_list();
int push_node(doubly_linked_list_t* list, void* payload, size_t n);
int pop_node(doubly_linked_list_t* list);
node_t* init_node(void* payload);
