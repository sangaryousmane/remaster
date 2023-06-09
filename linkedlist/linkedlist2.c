#include "lists.h"
#include <stdio.h>

// DEAF FINDER

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

    if (new_list == NULL) {
        return NULL;
    } else {
        new_list->n = n;
        new_list->next = (*head);
        (*head) = new_list;
        return new_list;
    }
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

// TODO: DAY 24, DELETE NODE IN A LIST
int delete_node(listint_t **head) {
    int new_data;
    listint_t *temp_var = NULL;
    if (!*head)
        return 0;
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
            for (; slow != fast; count++, slow = slow->next, fast = fast->next);
            slow = slow->next;
            for (; slow != fast; count++, slow = slow->next);
            return (count);
        }
    }
    return (0);
}

// Task 13
size_t free_listint_safe(listint_t **head) {
    listint_t *tmp = NULL, *current = *head;
    size_t nodes = loop_once(*head), index = 0;
    if (nodes == 0) {
        while (head != NULL && *head != NULL) {
            tmp = (*head)->next;
            free(*head);
            *head = tmp;
            nodes++;
        }
    } else {
        while (index < nodes) {
            tmp = current->next;
            free(current);
            current = tmp;
            index++;
        }
        *head = NULL;
    }
    head = NULL;
    return nodes;
}

size_t print_listint_safe(const listint_t *head) {
    size_t count = 0, nodes = loop_once(head);
    if (nodes == 0) {
        while (head != NULL) {
            printf("[%p] %d\n", (void *) head, head->n);
            count++;
            head = head->next;
        }
    } else {
        while (count < nodes) {
            printf("[%p] %d\n", (void *) head, head->n);
            count++;
            head = head->next;
        }
        printf("-> [%p] %d\n", (void *) head, head->n);
    }
    return (count);
}

// Task 14
listint_t *find_listint_loop(listint_t *head) {
    listint_t *slow = head, *fast = head;
    while (fast && fast->next) {
        slow = slow->next;
        fast = fast->next->next;
        if (slow == fast) {
            slow = head;
            for (; slow != fast; slow = slow->next, fast = fast->next);
            return slow;
        }
    }
    return NULL;
}

// Task 7
listint_t *get_nodeint_at_index(listint_t *head, unsigned int index) {
    unsigned int n = 0;
    while (n < index && head != NULL) {
        head = head->next;
        n++;
    }
    return (head);
}

// Task 9
listint_t *insert_nodeint_at_index(listint_t **head, unsigned int idx, int n) {
    listint_t *new, *t = *head;;

    new = malloc(sizeof(listint_t));
    if (!new)
        return (NULL);
    new->n = n;
    if (!idx) {
        new->next = t;
        return *head = new, new;
    }
    while (--idx && t)
        t = t->next;
    if (!t)
        return (free(new), NULL);
    new->next = t->next;
    return (t->next = new, new);
}

// Task 10
int delete_nodeint_at_index(listint_t **head, unsigned int index) {
    int n = 0;
    listint_t *list, *t = *head;

    if (!t)
        return (-1);

    if (index == 0) {
        *head = (*head)->next;
        free(t);
        return (1);
    }

    for (n = 0; n < (index - 1); n++) {
        if (t->next == NULL)
            return (-1);

        t = t->next;
    }

    list = t->next;
    t->next = list->next;
    free(list);
    return (1);
}

int show_it() {
    listint_t *head;

    head = NULL;
    add_nodeint(&head, 0);
    add_nodeint(&head, 1);
    add_nodeint(&head, 2);
    print_listint(head);
    delete_node( &head);
    return (0);
}