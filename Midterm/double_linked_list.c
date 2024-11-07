#include <stdio.h>
#include <stdlib.h>

typedef struct node {

    int data;
    node* prev;
    node* next;

}node;



node* insert_front(node* head, int data){

    node* temp = malloc(sizeof(node));
    temp->data = data;
    temp->prev = NULL;
    temp->next = head;

    if(head != NULL){
        head->prev = temp;
    }
    head = temp;

}


node* insert_end(node* head, int data){

    node* temp = malloc(sizeof(node));
    temp->data = data;
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


    return head;

}


