#include <stdlib.h>
#include <stdio.h>
#include "linkedlist.h"

/**
 * @brief Initialized linked list struct, returns null pointer if
 * memory allocation failed.
 * 
 * @return LinkedList* 
 */
LinkedList* init_linkedlist()
{

	// Attempt the allocation of the list
	LinkedList* list = (LinkedList*) malloc(sizeof(LinkedList));
	if(list == NULL)
		return NULL;

	// Assign 
	list->head = NULL;
	list->tail = NULL;
	list->length = 0;

	// Return pointer
	return list;

}

/**
 * @brief Printes the contents of the list.
 * 
 * @param list 
 */
void print_list(LinkedList* list) {
    printf("Printing list:\n");
    Node* temp = list->head;

    while(temp != NULL) {
        my_payload_t* payload = (my_payload_t*) temp->payload;
        printf("%i\t%s\n", payload->age, payload->name);
        temp = temp->next;
    }
    free(temp);
}

/**
 * @brief Pushes payload onto front of list.
 * 0    -> success
 * 1    -> failed to allocate memory.
 * -1   -> null pointers given.
 * 
 * @param list 
 * @param payload 
 * @param n 
 * @return int 
 */
int push_node(LinkedList *list, void *payload, size_t n)
{
    printf("Pushing node onto list!\n");

    // If null pointer given return -1.
    if (list == NULL || payload == NULL)
        return -1;

    // Allocate memory
    Node *new_node = malloc(sizeof(Node));
    new_node->payload = payload;

    // Check if mem allocation was successful.
    if (new_node == NULL)
    {
        free(new_node);
        return 1;
    }

    // Link node to head.
    new_node->next = list->head;
    list->head = new_node;

    if (list->length == 0)
        list->tail = new_node;

    list->length++;
    return 0;
}

int pop_node(LinkedList *list, void *destination)
{
}