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


/* TASK 2 */
// Write a function that returns the number of elements in a linked list_t list.
size_t list_len(const list_t *h){

    size_t num_elements = 0;

    while (h != NULL){
        if (h->str != NULL && (*h).len > 0)
            num_elements +=1;

        h = h->next;
    }
    return num_elements;
}

// TASK 3 */
// Write a function that adds a new node at the beginning of a list_t list.
list_t *add_node(list_t **head, const char *str){

    list_t *new_list;
    int i;
    unsigned int length = 0;

    for (i = 0; str[i] !='\0'; i++){
        length++;
    }

    new_list = malloc(sizeof(list_t));

    if(new_list){
        new_list->str= strdup(str);
        new_list->len=length;
        new_list->next=(*head);
        (*head)=new_list;
        return new_list;
    } else{
        return NULL;
    }
}

// Task 5
// Write a function that prints before the main function
void first(void) __attribute__ ((constructor));

/**
 * first - executes before the main function
 *
 * Return: void.
 */
void first(void)
{
    printf("You're beat! and yet, you must allow,\n");
    printf("I bore my house upon my back!\n");
}

// Task 6
list_t *add_node_end(list_t **head, const char *str){
    list_t *my_new_list, *temporary = *head;
    int counter = 0;
    int i = 0;

    for (; str[i] != '\0'; i++){
        counter++;
    }

    my_new_list = malloc(sizeof(list_t));

    if (my_new_list){
        my_new_list->len=counter;
        my_new_list->str= strdup(str);
        my_new_list->next=NULL;

        if (!*head){
            *head=my_new_list;
            return (my_new_list);
        }

        while (temporary->next){
            temporary = temporary->next;
        }
        temporary->next=my_new_list;
        return my_new_list;
    }
    else{
        return NULL;
    }

}


// Task 7
// Write a function that frees a list_t list.
void free_list(list_t *head){
    list_t *t;

    while(head){
        t = head->next;
        free(head->str);
        free(t);
        head=t;
    }
}
int test_me() {
    list_t *head;

    head = NULL;
    add_node(&head, "Alexandro");
    add_node(&head, "Asaia");
    add_node(&head, "Augustin");
    add_node(&head, "Bennett");
    add_node(&head, "Bilal");
    add_node(&head, "Chandler");
    add_node(&head, "Damian");
    add_node(&head, "Daniel");
    add_node(&head, "Dora");
    add_node(&head, "Electra");
    add_node(&head, "Gloria");
    add_node(&head, "Joe");
    add_node(&head, "John");
    add_node(&head, "John");
    add_node(&head, "Josquin");
    add_node(&head, "Kris");
    add_node(&head, "Marine");
    add_node(&head, "Mason");
    add_node(&head, "Praylin");
    add_node(&head, "Rick");
    add_node(&head, "Rick");
    add_node(&head, "Rona");
    add_node(&head, "Siphan");
    add_node(&head, "Sravanthi");
    add_node(&head, "Steven");
    add_node(&head, "Tasneem");
    add_node(&head, "William");
    add_node(&head, "Zee");
    print_list(head);
    return 0;
}