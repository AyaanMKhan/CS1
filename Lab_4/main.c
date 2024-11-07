/*
This code implements some basic operations of singly linked list like inserting in the beginning and end, delete operation, and display operation
*/

#include<stdio.h>
#include<stdlib.h>
typedef struct node{
  int data;
  struct node *next;
}node;

//this function takes an item and insert it in the linked list pointed by root.
node*  insert_front(node *root, int item)
{

  //create a new node and fill-up the node
  //if there is no node in the linked list
  node* temp = malloc(sizeof(node));
	temp->data = item;
	temp->next = NULL;


  if(root == NULL){

    root = temp;
    return root;

  } else {
    //there is an existing linked list, so put existing root after temp
    //put the existing root after temp
    //make the temp as the root!

    temp->next = root;
		root = temp;
		return root;

  }
  

}

void display(node* t)
{
  printf("\nPrinting your linked list.......");

  while(t!=NULL)
  {
    printf("%d ",t->data);
    t=t->next;
  }

}
node* reverse(node* head)
{
  // no need to reverse if head is null
  // or there is only 1 node.

  if(head == NULL || head->next == NULL){
    return head;
  }

  node *main_list = head->next;
  node * reversed_list = head;
  reversed_list->next = NULL;

  while(main_list != NULL){
    node *temp = main_list;
    main_list = main_list->next;
    temp->next = reversed_list;
    reversed_list = temp;
  }


  return reversed_list;
  
}

void insertToPlace(node* list, int val, int place) {
    // Create the new node.
    node* temp = malloc(sizeof(node));
    temp->data = val;
    temp->next = NULL;

    // If place is invalid (i.e., list is NULL and place > 1), print an error.
    if (list == NULL && place > 1) {
        printf("The list is empty, and place is out of bounds.\n");
        free(temp); // Avoid memory leak
        return;
    }

    // Traverse the list to find the node just before the insertion point.
    node* current = list;
    int count = 1;

    while (current != NULL && count < place - 1) {
        current = current->next;
        count++;
    }

    // If place is out of bounds, handle it.
    if (current == NULL) {
        printf("The place is out of bounds.\n");
        free(temp); // Avoid memory leak
        return;
    }

    // Patch the new node into the list.
    temp->next = current->next;
    current->next = temp;
}


int main()
{
  node *root=NULL; //very important line. Otherwise all function will fail
  node *t;
  int ch,ele,v, del;
  while(1)
  {
    printf("\nMenu: 1. insert at front, 2. reverse list 3. Insert to place 0. exit: ");
      scanf("%d",&ch);
    if(ch==0)
    {
      printf("\nGOOD BYE>>>>\n");
      break;
    }
    if(ch==1)
    {
      printf("\nEnter data (an integer): ");
      scanf("%d",&ele);
      root = insert_front(root, ele);

            display(root);

    }
    if(ch==2)
    {
      root = reverse(root);
      printf("List reversed.\n");
      display(root);

    }
    if(ch==3)
    {
        int place;
      printf("\nEnter data (an integer) and place (>1) separated by space: ");
      scanf("%d %d",&ele, &place);
      insertToPlace(root, ele, place);

            display(root);

    }

  }
  return 0;
}

