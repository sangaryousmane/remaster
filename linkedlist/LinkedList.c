#include <stdio.h>
#include <stdlib.h>

/**
 * Implementing a singly list
 */
struct Node{
    int data; /* The data of the current element */
    struct Node *next; /* A pointer to the next node */
};


// Print linked list elements
void printList(struct Node* n){

    while (n != NULL){
        printf(" %d ", n->data);
        n = n->next;
    }
}

// Driver's code
void show_linkedList(){
    struct Node* head = NULL;
    struct Node* second = NULL;
    struct Node* third = NULL;


    // Allocate three nodes in the heap
    head = (struct Node*) malloc(sizeof(struct Node));
    second = (struct Node*) malloc(sizeof(struct Node));
    third = (struct Node*) malloc(sizeof(struct Node));

    head->data=1;  /* Store data in the first element */
    head->next=second; /* points as the second element */

    second->data=2;
    second->next=third;

    third->data=3;
    third->next=NULL;  /* Last element points to null */


    /* Call the function to print the list */
    printList(head);
}