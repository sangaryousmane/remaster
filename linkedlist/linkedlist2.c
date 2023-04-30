#include "lists.h"
#include <stdio.h>

size_t print_listint(const listint_t *h){
    size_t num_of_nodes = 0;


    while (h !=NULL){
        printf("%d\n", h->n);
        num_of_nodes +=1;
        h = h->next;
    }

    return num_of_nodes;
}


int show_it(){
    listint_t *head;
    listint_t *new;
    listint_t hello = {8, NULL};
    size_t n;

    head = &hello;
    new = malloc(sizeof(listint_t));
    if (new == NULL)
    {
        printf("Error\n");
        return (1);
    }
    new->n = 9;
    new->next = head;
    head = new;
    n = print_listint(head);
    printf("-> %zu elements\n", n);
    free(new);
    return 0;
}