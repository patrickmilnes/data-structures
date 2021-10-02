#include <stdio.h>
#include <stdlib.h>
#include "include/linkedlist.h"
#include "include/utils.h"

void test_linked_list()
{
    LinkedList* list = init_linkedlist();
    my_payload_t* item1 = (my_payload_t*) malloc(sizeof(my_payload_t));
    item1->age = 21;
    item1->name = "Patrick";

    my_payload_t* item2 = (my_payload_t*) malloc(sizeof(my_payload_t));
    item2->age = 23;
    item2->name = "Sasha";

    size_t payload_size = sizeof(my_payload_t);

    push_node(list, item1, payload_size);
    push_node(list, item2, payload_size);

    Node* current = list->head;
    while(current != NULL)
    {
        my_payload_t* item = (my_payload_t*) current->payload;
        printf("Name: %s\n", item->name);
        current = current->next;
    }
}

int main(int argc, char *argv[])
{
    test_linked_list();
    // my_payload_t *stuff = (my_payload_t *)malloc(sizeof(my_payload_t));
    // stuff->age = 3;
    // stuff->name = "I love S.H";

    // my_payload_t *stuff1 = (my_payload_t *)malloc(sizeof(my_payload_t));
    // stuff1->age = 33;
    // stuff1->name = "I <3 S.H";

    // my_payload_t *stuff2 = (my_payload_t *)malloc(sizeof(my_payload_t));
    // stuff2->age = 56;
    // stuff2->name = "David";

    // LinkedList *list = init_linkedlist();
    // int rc = push_node(list, stuff, sizeof(stuff));
    // printf("rc: %i\n", rc);
    // print_list(list);
    // // pop_node(list);
    // // print_list(list);
    // rc = append_node(list, stuff1);
    // printf("%i\n", rc);
    // print_list(list);
    // push_node(list, stuff2, sizeof(stuff2));
    // print_list(list);
    // Node* result = search_by_name(list, "Davids");
    // if (result != NULL)
    // {
    //     my_payload_t *result1 = (my_payload_t *)result->payload;
    //     printf("Name: %s\n", result1->name);
    // }


    // char string[] = "Hello, this is a string with whitespaces.";
    // remove_whitespace(string);
    // printf("%s\n", string);
}