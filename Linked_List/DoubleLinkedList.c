#include <stdio.h>
#include <stdlib.h>

typedef struct node{
    // Gotta make it point forward and back
    node *next, *prev;
    int data;

}node;


node* insert_front(node *head, int item){

    node* temp = malloc(sizeof(node));
    temp->data = item;
    temp->prev = NULL;
    temp->next = head;

    if(head != NULL){
        head->prev = temp;
    }
    temp->next = head;
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

    return head;

}

node* insert_sorted(node* head, int item){

    node* temp = malloc(sizeof(node));
    temp->next = NULL;
    temp->prev = NULL;
    temp->data = item;

    if(head == NULL || item < head->data){
        if(head != NULL){
            head->prev = temp;
        }
        temp->next = head;
        head = temp;
        return head;
    } else {
        node* walker = head;
        while(walker->next != NULL && item > walker->next->data){
            walker = walker->next;
        }
        temp->next = walker->next;
        if(walker->next != NULL){
            walker->next->prev = temp;
        }
        walker->next = temp;
        temp->prev = walker;
    }
    return head;

}

