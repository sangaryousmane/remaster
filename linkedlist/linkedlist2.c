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
    n = listint_len(head);
    printf("-> %lu elements\n", n);
    free(new);
    return (0);
    return 0;
}