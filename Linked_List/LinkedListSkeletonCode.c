
#include<stdio.h>
#include<stdlib.h>

typedef struct node
{
  int data;
  struct node* next;

}node;


node* create_node(int item){

	node* temp = malloc(sizeof(node));
	temp->data = item;
	temp->next = NULL;

	return temp;
}


//this function takes an item and insert it in the linked list pointed by root.
node* insert_front(node* head, int item){	

	node *temp = create_node(item);
	
	if(head == NULL){
		head = temp; // will not change the head 

		return head;
	} else {
		temp->next = head;
		head = temp;
		return head;
	}

	
}

node* insert_sorted(node* head, int item)
{
	node *temp = malloc(sizeof(node));
	temp->data = item;
	temp->next = NULL;


	if(head == NULL || item < head->data){
		temp->next = head;
		head = temp;
		return head;
	} else {
		node *walker = head;
		while(walker->next != NULL && item < walker->next->data){
			walker = walker->next;
		}
		temp->next = walker->next;
		walker->next = temp;
	}

	return head;
}


//this function takes an item and insert it in the end of the linked list
node* insert_end(node* head, int item){

	node *temp = create_node(item);

	if(head == NULL){
		head = temp;
		return head;
	} else {
		node *walker = head;

		while(walker->next != NULL){
			walker = walker->next;
		}

		walker->next = temp;

		return head;
	}
  
}






/*this function deletes the first occurrence of a given item from linked list.
it returns the updated/original root
*/
node* DelList(node* head, int item)
{

	if(head != NULL && head->data == item){
		node* temp = head;
		head = head->next;
		free(temp);		
	} else {

		node* walker = head;
		while(walker->next != NULL && walker->data != item){
			walker = walker->next;
			node* temp = walker->next;
			walker->next = walker->next->next;
			free(temp);
		}

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
			insert_sorted(root, ele);

     //call appropriately  
      display(root);	

		}
	}
  return 0;
}
