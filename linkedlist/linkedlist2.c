#include "lists.h"
#include <stdio.h>


// Task 1
size_t print_listint(const listint_t *h) {
    size_t num_of_nodes = 0;


    for (; h != NULL; num_of_nodes++, h = h->next) {
        printf("%d\n", h->n);
    }

    return num_of_nodes;
}

// Task 2
size_t listint_len(const listint_t *h) {
    size_t num_el = 0;

    for (; h != NULL; num_el += 1) {
        h = h->next;
    }
    return num_el;
}

// Task 3
listint_t *add_nodeint(listint_t **head, const int n) {
    listint_t *new_list;

    new_list = malloc(sizeof(listint_t));

    if (new_list != NULL) {
        new_list->n = n;
        new_list->next = (*head);
        (*head) = new_list;
        return new_list;
    }
    return NULL;
}

// Task 4
listint_t *add_nodeint_end(listint_t **head, const int n) {
    listint_t *new_list;
    listint_t *temp_var = (*head);

    new_list = malloc(sizeof(listint_t));

    if (new_list == NULL) {
        return NULL;
    }
    else {
        new_list->n = n;
        new_list->next = NULL;
        if (*head == NULL) {
            (*head) = new_list;
            return new_list;
        }

        while (temp_var->next) {
            temp_var = temp_var->next;
        }
        temp_var->next = new_list;
        return new_list;
    }

}

// Task 5
void free_listint(listint_t *head){
    listint_t *list;

   for(; head !=NULL; list=head->next){
       free(head);
       head=list;
   }
}

// Task 6
void free_listint2(listint_t **head){
    listint_t *t;

    if ((*head) !=NULL) {
        for (; *head != NULL; t = (*head)->next) {
            free(*head);
            *head = t;
        }
        head = NULL;
    } else {
        return;
    }

}
int show_it() {
    listint_t *head;

    head = NULL;
    add_nodeint_end(&head, 0);
    add_nodeint_end(&head, 1);
    add_nodeint_end(&head, 2);
    add_nodeint_end(&head, 3);
    add_nodeint_end(&head, 4);
    add_nodeint_end(&head, 98);
    add_nodeint_end(&head, 402);
    add_nodeint_end(&head, 1024);
    print_listint(head);
    free_listint2(&head);
    printf("%p\n", (void *)head);
    return (0);
}