#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

int main(int argc, char* argv[])
{
    my_payload_t* stuff = (my_payload_t*) malloc(sizeof(my_payload_t));
    stuff->age = 3;
    stuff->name = "I love S.H";

    LinkedList* list = init_linkedlist();
    int rc = push_node(list, stuff, sizeof(stuff));
    printf("rc: %i\n", rc);
    print_list(list);
    pop_node(list);
    print_list(list);
}