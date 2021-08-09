#include <stddef.h>

typedef struct Node
{
    struct Node* next;
    struct Node* prev;
    void* payload;
} Node;

typedef struct
{
    struct Node* head;
    struct Node* tail;
    int length;
} DoublyLinkedList;

DoublyLinkedList* init_doubly_linked_list();
int push_node(DoublyLinkedList* list, void* payload, size_t n);
int pop_node(DoublyLinkedList* list);
