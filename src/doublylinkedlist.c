#include "include/doublylinkedlist.h"


doubly_linked_list_t* init_doubly_linked_list()
{
    doubly_linked_list_t* list = (doubly_linked_list_t*) malloc(sizeof(doubly_linked_list_t));
    
    if(list == NULL) 
        return NULL;

    list->head = NULL;
    list->tail = NULL;
    list->length = 0;

    return list;
}

int push_node(doubly_linked_list_t* list, void* payload, size_t n)
{
    if(list == NULL || payload == NULL) 
        return -1;
    
    node_t* new_node = init_node(payload);

    if(list->head == NULL)
    {
        list->head = new_node;
    }
    else
    {
        list->head = new_node;
        
    }
}

int pop_node(doubly_linked_list_t* list)
{
}

node_t* init_node(void* payload)
{
    node_t* new_node = (node_t*) malloc(sizeof(node_t));

    if(new_node == NULL)
        return NULL;

    new_node->next = NULL;
    new_node->prev = NULL;
    new_node->payload = payload;

    return new_node;
