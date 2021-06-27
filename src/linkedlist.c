#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "include/linkedlist.h"

/**
 * @brief Initialized linked list struct, returns null pointer if
 * memory allocation failed.
 * 
 * @return LinkedList* 
 */
LinkedList *init_linkedlist()
{

    // Attempt the allocation of the list
    LinkedList *list = (LinkedList *)malloc(sizeof(LinkedList));
    if (list == NULL)
        return NULL;

    list->head = NULL;
    list->tail = NULL;
    list->length = 0;

    return list;
}

/**
 * @brief Initializes node struct, returns null pointer if
 * memory allocation failed.
 * 
 * @return Node* 
 */
Node *init_node()
{
    // Attempt to allocate memory for node.
    Node *new_node = (Node *)malloc(sizeof(Node));
    if (new_node == NULL)
        return NULL;

    new_node->next = NULL;
    new_node->payload = NULL;

    return new_node;
}

/**
 * @brief Printes the contents of the list.
 * 
 * @param list 
 */
void print_list(LinkedList *list)
{
    printf("Printing list:\n");
    Node *temp = list->head;

    if (list->length == 0)
    {
        printf("List is empty!\n");
        return;
    }

    for (int i = 0; temp != NULL; i++)
    {
        my_payload_t *payload = (my_payload_t *)temp->payload;
        printf("%i\t%i\t%s\n", i, payload->age, payload->name);
        temp = temp->next;
    }

    // while (temp != NULL)
    // {
    // }
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
    Node *new_node = init_node();
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

/**
 * @brief Removes element of list at the head.
 * 0    -> Successful
 * 1    -> Empty list error.
 * 
 * @param list 
 * @param destination 
 * @return int 
 */
int pop_node(LinkedList *list)
{
    if (list == NULL || list->length == 0)
        return 1;

    // Unlink head from list.
    Node *to_free = list->head;
    list->head = to_free->next;
    list->length--;

    free(to_free);
    free(to_free->payload);

    if (list->length == 0)
        list->tail == NULL;

    return 0;
}

/**
 * @brief Inserts node onto end of list.
 * 0    -> Success
 * 1    -> Failed to allocate memory.
 * -1   -> Null pointers were given.
 * 
 * @param list 
 * @param new_node 
 * @return int 
 */
int append_node(LinkedList *list, void *payload)
{
    if (list == NULL, payload == NULL)
        return -1;

    // Allocate memory
    Node *new_node = init_node();
    new_node->payload = payload;

    if (new_node == NULL)
    {
        free(new_node);
        return 1;
    }

    if (list->length == 0)
        list->head = new_node;
    else
        list->tail->next = new_node;

    list->tail = new_node;

    list->length++;

    return 0;
}

/**
 * @brief Allows seaching list by name in payload. Returns pointer to node
 * if target is found and returns null id target is not found.
 * 
 * @param list 
 * @param age_target 
 * @return Node* 
 */
Node* search_by_age(LinkedList* list, int age_target)
{
    printf("Searching list!\n");

    Node *temp = list->head;

    while (temp != NULL)
    {
        my_payload_t *current_payload = (my_payload_t*) temp->payload;
        if (current_payload->age == age_target)
        {
            return temp;
        }
        temp = temp->next;
    }
    printf("Not found!\n");
    // free(temp);
    return NULL;
}

/**
 * @brief Allows searching list by age. Returns pointer to node
 * if target is found and returns null id target is not found.
 * 
 * @param list 
 * @param name_target 
 * @return Node* 
 */
Node* search_by_name(LinkedList* list, char* name_target)
{
    printf("Searching list!\n");

    Node *temp = list->head;

    while (temp != NULL)
    {
        my_payload_t *current_payload = (my_payload_t*) temp->payload;
        int rc = strcmp(current_payload->name, name_target);
        if (rc == 0)
        {
            return temp;
        }
        temp = temp->next;
    }
    // free(temp);
    printf("Not found!\n");
    return NULL;
}