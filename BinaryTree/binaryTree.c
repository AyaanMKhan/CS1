#include <stdio.h>

typedef struct tree_node {
  int data;
  struct tree_node *left;
  struct tree_node *right;
};






void inOrder(struct tree_node *ptr) {

    if (ptr != NULL) {
        inOrder(ptr->left);
        printf("%d ", ptr->data);
        inOrder(ptr->right);
    }

}

struct tree_node *insert (struct tree_node *root, struct tree_node *element){

    if(root == NULL){
        return element;
    } else {
        // element should be inserted to the right
        if(element->data > root->data){
            // There is a right subtree to insert the node
            if(root->right != NULL){
                root->right = insert(root->right, element);
            // Place the node directly to the right of root
            } else {
                root->right = element;
            }
        } else {
            // element should be inserted to the left
            if(element->data < root->data){
                if(root->left != NULL){
                    root->left = insert(root->left, element);
                } else {
                    root->left = element;
                }
            }

    

    
        }
    // Return the root pointer of the updated tree
    return root;
}

struct tree_node* create_node(int val) {

  // Allocate space for the node, set the fields.
    struct tree_node* temp;
    temp = (struct tree_node*)malloc(sizeof(struct tree_node));
    temp->data = val;
    temp->left = NULL;
    temp->right = NULL;

    return temp; // Return a pointer to the created node.
}


int find(struct tree_node *ptr, int val){

    if(ptr != NULL){

        if(ptr->data == val){
            return val;
        } else if(ptr->data > val){
            return find(ptr->left, val);
        } else {
            return find(ptr->right, val);
        }
    } else {
        return 0;
    }
}


struct tree_node *minVal(struct tree_node *ptr){

    if(ptr->left == NULL){
        return ptr;
    } else {
        minVal(ptr->left);
    }
}

struct tree_node *maxVal(struct tree_node *ptr){

    if(ptr->right == NULL){
        return ptr;
    } else {
        maxVal(ptr->right);
    }

}

int isLeaf(struct tree_node *ptr){

    if(ptr->left == NULL && ptr->right == NULL){
        return 1;
    } else {
        return 0;
    }
}

int hasOnlyLeftChild(struct tree_node *ptr){

    if(ptr->left != NULL && ptr->right == NULL){
        return 1;
    } else {
        return 0;
    }
}

int hasOnlyRightChild(struct tree_node *ptr){

    if(ptr->left == NULL && ptr->right != NULL){
        return 1;
    } else {
        return 0;
    }
}

struct tree_node *findNode(struct tree_node *ptr, int val){

    if(ptr != NULL){
        if(ptr->data == val){
            return ptr;
        } else if(ptr->data > val){
            return findNode(ptr->left, val);
        } else {
            return findNode(ptr->right, val);
        }
    } else {
        return NULL;
    }

}


struct tree_node *delete(struct tree_node *root, int val){

    struct tree_node *delnode, *par, *save_node;

    delnode = findNode(root, val);
    par = parent(root, delnode);

    if(isLeaf(delnode)){
        if(par == NULL){
            free(root);
            return NULL;
        } else {
            if(val < par->data){
                free(par->left);
                par->left = NULL;
            } else {
                free(par->right);
                par->right = NULL;
            }
            return root;
        }
    }

    if(hasOnlyLeftChild(delnode)){
        if(par == NULL){
            save_node = delnode->left;
            free(delnode);
            return save_node;
        } else {
            if(val < par->data){
                save_node = par->left;
                par->left = par->left->left;
                free(save_node);
            } else {
                save_node = par->right;
                par->right = par->right->left;
                free(save_node);
            }
            return root;
        }
    }

    if(hasOnlyRightChild(delnode)){
        if(par == NULL){
            save_node = delnode->right;
            free(delnode);
            return save_node;
        } else {
            if(val < par->data){
                save_node = par->left;
                par->left = par->left->right;
                free(save_node);
            } else {
                save_node = par->right;
                par->right = par->right->right;
                free(save_node);
            }
            return root;
        }
    }

    return root;
}


int menu() {
  int choice;

  printf("\n1. Insert a node\n");
  printf("2. Delete a node\n");
  printf("3. Search for a node\n");
  printf("4. Add all nodes\n");
  printf("5. Print the tree\n");
  printf("6. Q6\n");
  printf("7. Exit\n");
  printf("Enter your choice: ");
  scanf("%d", &choice);

  return choice;
}


int main() {

  struct tree_node *my_root=NULL, *temp_node;
  int done = 0,ans=1, val, q6data;

  ans = menu();
  while (ans<8) {

    if (ans == 1) {

      // Get value to insert.
      printf("What value would you like to insert?");
      scanf("%d", &val);
      temp_node = create_node(val); // Create the node.

      // Insert the value.
      my_root = insert(my_root, temp_node);
    }

    if (ans == 2) {
      printf("What value would you like to delete?\n");
      scanf("%d", &val);
      if (!find(my_root, val))
        printf("Sorry that value isn't in the tree to delete.\n");
      else {
        my_root = delete(my_root, val);
      }
    }

    if (ans == 3) {
      printf("What value would you like to search for?\n");
      scanf("%d", &val);
      if (find(my_root, val))
        printf(" Found %d in the tree.\n", val);
      else
        printf(" Did not find %d in the tree.\n", val);
    }

    if (ans == 4)
      printf("The sum of the nodes in your tree is %d.\n", add(my_root));

    if (ans == 5) {
      // Print the resulting tree.
      printf("Here is an inorder traversal of your tree: ");
      inorder(my_root);
      printf("\n");
    }
    if (ans == 7) {
      // Print the resulting tree.
      printf("enter a value for q6: ");
      scanf("%d", &q6data);
      printf("Q6: ");
      q6(my_root, q6data );
      printf("\n");
    }

    // See if they want to insert more nodes.
    ans = menu();
  }
   /*
  printf("Testing what function.\n\n");
  what(my_root, 7);
  printf("\n");
  */

  int rank;
  printf("Which ranked item would you like to find?\n");
  scanf("%d", &rank);

  printf("The item is %d\n", findKthSmallest(my_root, rank));

  system("PAUSE");
  return 0;
}