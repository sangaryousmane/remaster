#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#ifndef __LISTS__
#define __LISTS__


typedef struct list_s{
    char *str;
    unsigned int len;
    struct list_s *next;
} list_t;



#include <stdio.h>
/**
 * struct listint_s - singly linked list
 * @n: integer
 * @next: points to the next node
 *
 * Description: singly linked list node structure
 *
 */
typedef struct listint_s
{
    int n;
    struct listint_s *next;
} listint_t;

/* Function Prototypes */
size_t print_list(const list_t *h);
size_t list_len(const list_t *h);
list_t *add_node_end(list_t **head, const char *str);
list_t *add_node(list_t **head, const char *str);
void free_list(list_t *head);
#endif /* __LISTS__ */