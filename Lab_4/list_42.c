#include <stdio.h>
#include <stdlib.h>

typedef struct node{

  int data;
  struct node *next;

}node;


void list_42(struct node *list){

    node *temp;

    if(list == NULL){
        return;
    }
    while(list != NULL){

        if(list->data == 4){
            temp = list->next;
            list->next = malloc(sizeof(node));
            list->next->data = 2;
            list = list->next;
        }

        list = list->next;
    }


}



int main(){



    return 0;
}