#include <stdio.h>
#include <stdlib.h>


typedef struct node {

    node *next, *prev;
    int data;

}node;



node* insert_front(node* head, int item){

    node* temp = malloc(sizeof(node));
    temp->next = head;
    temp->data = item;
    temp->prev = NULL;

    if(head == NULL){
        head->prev = temp;
    }
    head = temp;
    return head;

}


node* insert_end(node* head, int item){

    node* temp = malloc(sizeof(node));
    temp->data = item;
    temp->next = NULL;

    if(head == NULL){
        temp->prev = NULL;
        head = temp;
    } else {
        node* walker = head;

        while(walker->next != NULL){
            walker = walker->next;
        }
        walker->next = temp;
        temp->prev = walker;
    }

}