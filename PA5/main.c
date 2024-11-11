/* COP 3502C Assignment 5
This program is written by: Ayaan Khan */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAXLEN 25

typedef struct tree_node {
    int data;
    struct tree_node *left;
    struct tree_node *right;
    char name[MAXLEN + 1];
} tree_node;


// Create a node for the tree
tree_node *create_node(int fine, char name[]) {

    tree_node *temp = malloc(sizeof(tree_node));
    temp->data = fine;
    strcpy(temp->name, name);

    temp->left = NULL;
    temp->right = NULL;

    return temp;

}


// Find the max of the tree
tree_node *find_max(tree_node* root) {
    
    if (root->right == NULL){
        return root;
    }

   
    return find_max(root->right);
}


// Find the parent of the node
tree_node* parent(tree_node* root, tree_node* node) {
    
    if (root == NULL || root == node){
        return NULL;
    }

    if (root->left == node || root->right == node){
        return root;
    }

    if (strcmp(node->name, root->name) < 0) {
        return parent(root->left, node);
    } else if (strcmp(node->name, root->name) > 0) {
        return parent(root->right, node);
    }


    return NULL;
}


// Check if the node is a leaf
int isLeaf(tree_node* node) {
    return (node->left == NULL && node->right == NULL);
}

// Check if the node has only right child
int hasOnlyRightChild(tree_node* node) {
    return (node->left == NULL && node->right != NULL);
}

// Check if the node has only left child
int hasOnlyLeftChild(tree_node* node) {
    return (node->left != NULL && node->right == NULL);
}


// Add to the tree
tree_node *insert(tree_node *root, int fine, char name[]) {
    if (root == NULL) {
        return create_node(fine, name);
    } else {
        if (strcmp(name, root->name) == 0) {
            root->data += fine;
            return root;
        }
    }

    if (strcmp(name, root->name) < 0) {
        root->left = insert(root->left, fine, name);
    } else if (strcmp(name, root->name) > 0) {
        root->right = insert(root->right, fine, name);
    }

    return root;
}


// Search for a node in the tree
tree_node* search(tree_node* root, char name[], int* depth) {
    
    // return if the name matches
    if (root != NULL){
        if (strcmp(name, root->name) == 0){
            return root;
        }

        // if name is less go left
        if (strcmp(name, root->name) < 0){
            (*depth)++;
            return search(root->left, name, depth);
        }

        // if name is greater go right
        if (strcmp(name, root->name) > 0){
            (*depth)++;
            return search(root->right, name, depth);
        }
    } else {
        return NULL;
    }

    return NULL;
}


// Delete a node from the tree
tree_node* delete(tree_node* root, char* name, int* data) {
   
    if (root == NULL){
        return NULL;
    }

    tree_node *temp, *new, *save, *par;
    char save_val[MAXLEN+1];
    int depth = 0;

    temp = search(root, name, &depth);

    
    if (temp != NULL){
        *data = 1;
    } else {
        *data = 0;
        return root;
    }

    par = parent(root, temp); 

    // Deleting if the node is a leaf
    if (isLeaf(temp)){
        
        if (par == NULL){
            free(temp);
            return NULL;
        }

        if (strcmp(name, par->name) < 0){
            free(par->left);
            par->left = NULL;
        } else {
            free(par->right);
            par->right = NULL;
        }
    } else if (hasOnlyLeftChild(temp)) { // Deleting if the node has only left child
        if (par == NULL){
            // Save node free and return
            save = temp->left;
            free(temp);
            return save; 
        }

        if (strcmp(name,par->name) < 0){
            save = par->left;
            par->left = par->left->left;
            free(save);
        } else {
            save = par->right;
            par->right = par->right->left;
            free(save);
        }
    } else if (hasOnlyRightChild(temp)) { // Same logic but if node has only right child
        if (par == NULL){
            save = temp->right;
            free(temp);
            return save;
        }

        if (strcmp(name,par->name) < 0){
            save = par->left;
            par->left = par->left->right;
            free(save);
        } else {
            save = par->right;
            par->right = par->right->right;
            free(save);
        }

    } else { // If node has two children

    new = find_max(temp->left); // Find the max of left subtree

    // Save name and fine
    strcpy(save_val, new->name);
    int save_fines = new->data; 

    // Delete the max of left subtree
    root = delete(root, save_val, data);

    // Replace
    strcpy(temp->name, save_val); 
    temp->data = save_fines;

    }

    return root;
}






// Gets max of two integers
int max(int x, int y){
    if(x > y)
    {
        return x;
    }

    return y;
}

// Gets the height of the tree
int height(tree_node* root) {
    if(root != NULL)
    {
        return 1 + max(height(root->left), height(root->right));
    }
    return -1;
}

// Checks if the tree is balanced
int height_balanced(tree_node* root) {
   if (root != NULL)
   {
       int leftHeight = height(root->left); // Gets the height of the left subtree
       int rightHeight = height(root->right); // Gets the height of the right subtree

       //Compares if its balanced or not
       if (leftHeight == rightHeight){
           printf("left height = %d right height = %d balanced\n", leftHeight, rightHeight);
       } else {
           printf("left height = %d right height = %d not balanced\n", leftHeight, rightHeight);
       }
   }
   return 0;
}


// Calculates the average of the fines
void calculateAverage(tree_node *root, float *sum, int *count) {
    if (root == NULL) {
        return;
    }

    calculateAverage(root->left, sum, count);
    *sum += root->data;
    (*count)++;
    calculateAverage(root->right, sum, count);
}


// Returns the average of the fines
float average(tree_node *root) {

    if(root == NULL){
        return 0;
    }

    float sum = 0;
    int count = 0;
    calculateAverage(root, &sum, &count);
    

    if(count == 0){
        return 0;
    } else {
        return sum / count;
    }
}


// Calculates the total amount of fines for alphabetically order of names behind the name specified (name does not need to exist in the tree
int calc_below(tree_node* root, char* name) {
    
    if (root == NULL){
        return 0;
    }

    
    if (strcmp(root->name, name) <= 0){
        return root->data + calc_below(root->left, name) + calc_below(root->right, name);
    }

    
    return calc_below(root->left, name) + calc_below(root->right, name);
}

// Free all the memory of the tree
void freeMem(tree_node* root) {

    if(root == NULL)
    {
       return;
    }

    // Start from the leaves to not leak memory (work your way up the tree)
    freeMem(root->left);
    freeMem(root->right);
    free(root);
}



int main() {
    // All variables we need
    int n;
    char command[MAXLEN + 1];
    char name[MAXLEN + 1];
    tree_node *root = NULL;
    int count = 0;
    

    scanf("%d", &n);
    while(n--){
        int depth = 0;
        scanf("%s", command);
        for(int i = 0; i < command[i]; i++){
            command[i] = tolower(command[i]);
        }

        if(strcmp(command, "add") == 0){
            
            int fine;
            char name[MAXLEN + 1];
            for(int i = 0; i < name[i]; i++){
                name[i] = tolower(name[i]);
            }
            scanf("%s %d", name, &fine);

            tree_node *flag = search(root, name, &depth);

            // we add the fine to the existing node else we create a new node
            if(flag != NULL){
                flag->data += fine;
                printf("%s %d %d\n", name, flag->data, depth);
            } else {
                root = insert(root, fine, name);
                printf("%s %d %d\n", name, fine, depth);
            }
        } else if(strcmp(command, "deduct") == 0) {
            int deduct;

            scanf("%s %d", name, &deduct); 
            for(int i = 0; i < name[i]; i++){
                name[i] = tolower(name[i]);
            }

            tree_node *found = search(root, name, &depth);

            // If the node is found we deduct the fine else we remove the node
            if(found != NULL) {
                if(found->data > deduct){
                    found->data -= deduct;
                } else {
                    found->data = 0;
                }

                if(found->data > 0)
                {
                    printf("%s %d %d\n", found->name, found->data, depth);
                } else {
                    int flag_del = 0;
                    root = delete(root, name, &flag_del);
                    printf("%s removed\n", name);
                }
            } else {
                printf("%s not found\n", name);
            }
        } else if(strcmp(command, "search") == 0) {

            // Search for the name and print the data and depth
            char name[MAXLEN + 1];
            scanf("%s", name);

            for(int i = 0; i < name[i]; i++){
                name[i] = tolower(name[i]);
            }

            tree_node* found = search(root, name, &depth);

            if (found == NULL) {
                printf("%s not found\n", name);
            } else {
                printf("%s %d %d\n", found->name, found->data, depth);
            }
        } else if(strcmp(command, "average") == 0) {

            // Print the average of the fines
            float avg;
            avg = average(root);
            printf("%.2f\n", avg);

        } else if(strcmp(command, "height_balance") == 0) {

            // Print if the tree is balanced or not (left an right subtree heights are equal)
            height_balanced(root);

        } else if(strcmp(command, "calc_below") == 0) {

            // Print the total amount of fines in alphabetically order of names behind the name specified
            // Name does not need to exist in the tree for this to work
            char name[MAXLEN + 1];
            scanf("%s", name);

            for(int i = 0; i < name[i]; i++){
                name[i] = tolower(name[i]);
            }
            
            printf("%d\n", calc_below(root, name));
        }
    }

    freeMem(root); //Frees Memory
    return 0;
}