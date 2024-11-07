#include <stdio.h>
#include <stdlib.h>



typedef struct node {

    node *next;
    int data;

}node;



node* createNode(int item){
    node* temp = malloc(sizeof(node));
    temp->data = item;
    temp->next = NULL;
    return temp;
}


node* insert_front(node* head, int item){

    node* temp = createNode(item);

    if(head == NULL){
        head = temp;
    } else {
        temp->next = head;
        head = temp;
    }

    return head;
}




node* insert_end(node* head, int item){

    node* temp = createNode(item);

    if(head == NULL){
        head = temp;
    } else {
        node* walker = head;
        while(walker->next != NULL){
            walker = walker->next;
        }
        walker->next = temp;
    }

    return head;

}


node* insert_sorted(node* head, int item){

    node* temp = createNode(item);

    if(head == NULL || item < head->data){
        temp->next = head;
        head = temp;
    } else {
        node* walker = head;
        while(walker->next != NULL && item < walker->next->data){
            walker = walker->next;
        }
        temp->next = walker->next;
        walker->next = temp;
        
    }

}

node* delete(node* head, int item){

    if(head == NULL && item == head->data){
        node* temp = head;
        head = head->data;
        free(temp);
        return head;
    } else {
        node* t;
        while(t != NULL && item != t->data){
            t = t->next;
            node* temp = t->next;
            t->next = t->next->next;
            free(temp);
        }
    }


}