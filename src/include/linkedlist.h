//
// Created by Patrick on 26/06/2021 - 12:56.
//
#include <stddef.h>
#ifndef DATA_STRUCTURES_LINKEDLIST_H
#define DATA_STRUCTURES_LINKEDLIST_H

typedef struct Node
{
    struct Node* next;
    void* payload;
} Node;

typedef struct
{
    struct Node* head;
    struct Node* tail;
    int length;
} LinkedList;

typedef struct my_payload
{
    int age;
    char *name;
} my_payload_t;

LinkedList* init_linkedlist();
Node* init_node();
void print_list(LinkedList *list);
int push_node(LinkedList *list, void* payload, size_t n);
int pop_node(LinkedList *list);
int append_node(LinkedList *list, void* payload);
Node* search_by_age(LinkedList* list, int age_target);
Node* search_by_name(LinkedList* list, char* name_target);

#endif //DATA_STRUCTURES_LINKEDLIST_H
