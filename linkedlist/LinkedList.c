#include <stdio.h>
#include <stdlib.h>

/**
 * struct Node - Implementing a singly linked list
 *
 * Description: takes a data and a pointer to the next node
 */

// TODO: DAY 21, LINKED LIST IN C 🎉🎇
typedef struct Node{
    int data; /* The data of the current element */
    struct Node *next; /* A pointer to the next node */
} Node;

// Print linked list elements
void printList(Node *n){

    for (; n != NULL; n = n->next){
        printf(" %d ", n->data);
    }
}

// TODO: DAY 23, LINKED LIST CONTINUE 🎉🎉
// TODO: ADD AND RETURN A NEW LIST USING C 🎉✨
Node *add_new_node(Node **head, const int data){
    Node *newNode;
    newNode= malloc(sizeof(Node));

    if(newNode){
        newNode->data=data;
        newNode->next=(*head);
        (*head) = newNode;
        return newNode;
    }
    return NULL;
}

void accessList(){
    Node *node;

    node=NULL;
    add_new_node(&node, 2);
    add_new_node(&node, 3);
    add_new_node(&node, 4);
    printList(node);
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
    head->next=second; /* points at the second element */

    second->data=2;
    second->next=third;

    third->data=3;
    third->next=NULL;  /* Last element points to null */


    /* Call the function to print the list */
    printList(head);
}