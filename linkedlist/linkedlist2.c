#include "lists.h"
#include <stdio.h>


// Task 1
size_t print_listint(const listint_t *h){
    size_t num_of_nodes = 0;


    for (; h !=NULL; num_of_nodes++, h = h->next){
        printf("%d\n", h->n);
    }

    return num_of_nodes;
}

// Task 2
size_t listint_len(const listint_t *h){
    size_t num_el = 0;

    for (; h !=NULL; num_el +=1){
        h = h->next;
    }
    return num_el;
}

// Task 3
listint_t *add_nodeint(listint_t **head, const int n){
    listint_t *new_list;

    new_list= malloc(sizeof(listint_t));

    if (new_list != NULL){
        new_list->n=n;
        new_list->next=(*head);
        (*head)=new_list;
        return new_list;
    }
    return NULL;
}
int show_it(){
    listint_t *head;

    head = NULL;
    add_nodeint(&head, 0);
    add_nodeint(&head, 1);
    add_nodeint(&head, 2);
    add_nodeint(&head, 3);
    add_nodeint(&head, 4);
    add_nodeint(&head, 98);
    add_nodeint(&head, 402);
    add_nodeint(&head, 1024);
    print_listint(head);
    return 0;
}