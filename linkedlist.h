//
// Created by Patrick on 26/06/2021 - 12:56.
//
#include <stddef.h>
#ifndef JSON_PARSER_LINKEDLIST_H
#define JSON_PARSER_LINKEDLIST_H

typedef struct Node
{
    struct Node *next;
    size_t alloc;
    void *payload;
} Node;

typedef struct
{
    struct Node *head;
    struct Node *tail;
    int length;
} LinkedList;

typedef struct my_payload {
        int age;
        char* name;
} my_payload_t;

LinkedList* init_linkedlist();
void print_list(LinkedList* list);
int push_node(LinkedList *list, void *payload, size_t n);
int pop_node(LinkedList *list);

#endif //JSON_PARSER_LINKEDLIST_H
