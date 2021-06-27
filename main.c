#include <stdio.h>
#include <stdlib.h>
#include "linkedlist.h"

int main(int argc, char* argv[])
{
    my_payload_t* stuff = (my_payload_t*) malloc(sizeof(my_payload_t));
    stuff->age = 3;
    stuff->name = "I love S.H";

    my_payload_t* stuff1 = (my_payload_t*) malloc(sizeof(my_payload_t));
    stuff1->age = 33;
    stuff1->name = "I <3 S.H";

    my_payload_t* stuff2 = (my_payload_t*) malloc(sizeof(my_payload_t));
    stuff2->age = 56;
    stuff2->name = "David";

    LinkedList* list = init_linkedlist();
    int rc = push_node(list, stuff, sizeof(stuff));
    printf("rc: %i\n", rc);
    print_list(list);
    // pop_node(list);
    // print_list(list);
    rc = append_node(list, stuff1);
    printf("%i\n", rc);
    print_list(list);
    push_node(list, stuff2, sizeof(stuff2));
    print_list(list);
}