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
    } else {
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
void free_listint(listint_t *head) {
    listint_t *list;

    for (; head != NULL; list = head->next) {
        free(head);
        head = list;
    }
}

// Task 6
void free_listint2(listint_t **head) {
    listint_t *tmp;
    if ((*head) == NULL)
        return;
    for (listint_t *current = *head; current != NULL; current = tmp) {
        tmp = current->next;
        free(current);
    }
    *head = NULL;
}

// Task 7
int pop_listint(listint_t **head) {
    int new_data = 0;
    listint_t *temp_var = NULL;

    if (*head == NULL) {
        return 0;
    }
    else {
        temp_var = *head;
        new_data = temp_var->n;
        *head = (*head)->next;
        free(temp_var);
        return new_data;
    }
}

// Task 11
listint_t *reverse_listint(listint_t **head) {
    listint_t *ahead, *tail, *current;
    if (head == NULL || *head == NULL)
        return (NULL);
    tail = NULL;
    for (current = *head; current != NULL; current = ahead) {
        ahead = current->next;
        current->next = tail;
        tail = current;
    }
    *head = tail;
    return (*head);
}

// Task 12
size_t loop_once(const listint_t *head) {
    const listint_t *slow, *fast;
    size_t count = 1;
    if (head == NULL || head->next == NULL)
        return (0);
    slow = head->next;
    fast = (head->next)->next;
    for (; fast; slow = slow->next, fast = (fast->next)->next) {
        if (slow == fast) {
            slow = head;
            for (; slow != fast; count++, slow = slow->next, fast = fast->next)
                ;
            slow = slow->next;
            for (; slow != fast; count++, slow = slow->next)
                ;
            return (count);
        }
    }
    return (0);
}

size_t print_listint_safe(const listint_t *head) {
    size_t count = 0, nodes = loop_once(head);
    if (nodes == 0) {
            while (head != NULL) {
                printf("[%p] %d\n", (void *)head, head->n);
                count++;
                head = head->next;
            }
    } else {
        while (count < nodes) {
            printf("[%p] %d\n", (void *)head, head->n);
            count++;
            head = head->next;
        }
        printf("-> [%p] %d\n", (void *)head, head->n);
    }
    return (count);
}
int show_it() {
    listint_t *head;
    listint_t *head2;
    listint_t *node;

    head2 = NULL;
    add_nodeint(&head2, 0);
    add_nodeint(&head2, 1);
    add_nodeint(&head2, 2);
    add_nodeint(&head2, 3);
    add_nodeint(&head2, 4);
    add_nodeint(&head2, 98);
    add_nodeint(&head2, 402);
    add_nodeint(&head2, 1024);
    print_listint_safe(head2);
    head = NULL;
    node = add_nodeint(&head, 0);
    add_nodeint(&head, 1);
    add_nodeint(&head, 2);
    add_nodeint(&head, 3);
    add_nodeint(&head, 4);
    node->next = add_nodeint(&head, 98);
    add_nodeint(&head, 402);
    add_nodeint(&head, 1024);
    print_listint_safe(head);
    return (0);
}