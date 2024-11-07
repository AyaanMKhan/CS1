#include <stdio.h>
#include <stdlib.h>


typedef struct node {

    int data;
    struct node* next;

}node;


node* create_node(int item){

    node* temp = malloc(sizeof(node));
    temp->data = item;
    temp->next = NULL;

}

node* insert_front(node* head, int item){

    node* temp = create_node(item);

    if(head == NULL){
        head = temp;
    } else {
        temp->next = head;
        head = temp;
    }

    return head;

}


node* insert_end(node* head, int item){

    node* temp = create_node(item);


    if(head == NULL){
        head = temp;
    } else {
        node* walker = head;
        if(walker->next != NULL){
            walker = walker->next;
        }
        
        walker->next = temp;
    }


    return head;
}


node* insert_sorted(node* head, int item){

    node* temp = create_node(item);

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

    return head;

}

void display(node* t)
{
  printf("\nPrinting your linked list.......");

  while(t!=NULL)
  {
    printf("%d ", t->data);
    t= t->next;
  }

  printf("\n");	

}

int main()
{	
  //declare root apprpriately
	
	node *root = NULL;



	int ch,ele,v, del;
	while(1)
	{
		printf("\nMenu: 1. insert at the front, 2. insert at the end, 3. Delete, 5.  sorted insert 4. exit: ");
	    scanf("%d",&ch);
		if(ch==4)
		{
			printf("\nGOOD BYE>>>>\n");
			break;
		}
		if(ch==1)
		{
			printf("\nEnter data(an integer): ");
			scanf("%d",&ele);
			insert_front(root, ele);

      //call the funtion appropriately 
      display(root);	

		}
		if(ch==2)
		{
			printf("\nEnter information(an integer): ");
			scanf("%d",&ele);
			insert_end(root, ele);

      //call the funtion appropriately 
      display(root);
			
		}
	  if(ch==3)
	  {
		  printf("\nEnter info which u want to DELETE: ");
		  scanf("%d",&del);
		
      ////call the funtion appropriately ______________________
      display(root);	  

		}

    if(ch==5)
		{
			printf("\nEnter data(an integer): ");
			scanf("%d",&ele);
			//insert_sorted(root, ele);

     //call appropriately  
      display(root);	

		}
	}
  return 0;
}