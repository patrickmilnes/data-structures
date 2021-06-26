#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

int main(int argc, char* argv[])
{
    my_payload_t* stuff = (my_payload_t*) malloc(sizeof(my_payload_t));
    stuff->age = 3;
    stuff->name = "Sasha";

    LinkedList* list = init_linkedlist();
    Node* new_node = (Node*) malloc(sizeof(Node));
    new_node->payload = stuff;
    int rc = push_node(list, new_node, sizeof(new_node));
    printf("%i\n", rc);
    print_list(list);
}