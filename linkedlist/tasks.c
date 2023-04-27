#include "lists.h"


/* TASK 1 */
// Write a function that prints all the elements of a list_t list.
size_t print_list(const list_t *h) {
    size_t node_count = 0;

    while (h) {
        if (h->str == NULL)
            printf("[0] (nil)\n");
        else
            printf("[%d] %s\n", h->len, h->str);

        h = h->next;
        node_count++;
    }
    return node_count;
}

int test_me() {
    list_t *head;
    list_t *new;
    list_t hello = {"World", 5, NULL};
    size_t n;

    head = &hello;
    new = malloc(sizeof(list_t));
    if (new == NULL) {
        printf("Error\n");
        return (1);
    }
    new->str = strdup("Hello");
    new->len = 5;
    new->next = head;
    head = new;
    n = print_list(head);
    printf("-> %zu elements\n", n);

    printf("\n");
    free(new->str);
    new->str = NULL;
    n = print_list(head);
    printf("-> %zu elements\n", n);

    free(new);
    return 0;
}