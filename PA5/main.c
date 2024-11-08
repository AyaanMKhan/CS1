#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

#define MAXLEN 25

typedef struct tree_node {
    int data;
    struct tree_node *left;
    struct tree_node *right;
    char name[MAXLEN];
} tree_node;

tree_node *create_node(int fine, char name[]) {
    tree_node *temp = malloc(sizeof(tree_node));
    temp->data = fine;
    strcpy(temp->name, name);
    temp->left = NULL;
    temp->right = NULL;
    return temp;
}


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


tree_node *find_min(tree_node *root) {
    while (root->left != NULL) {
        root = root->left;
    }
    return root;
}

tree_node *delete(tree_node *root, int deduct, char name[]) {
    if (root == NULL) {
        return NULL;
    }

    if (strcmp(name, root->name) < 0) {
        root->left = delete(root->left, deduct, name);
    } else if (strcmp(name, root->name) > 0) {
        root->right = delete(root->right, deduct, name);
    } else {
        if (deduct >= root->data) {
            // Node to be deleted
            if (root->left == NULL) {
                tree_node *temp = root->right;
                printf("%s removed\n", root->name);
                free(root);
                return temp;
            } else if (root->right == NULL) {
                tree_node *temp = root->left;
                printf("%s removed\n", root->name);
                free(root);
                return temp;
            }

            // Node with two children
            tree_node *temp = find_min(root->right);
            root->data = temp->data;
            strcpy(root->name, temp->name);
            root->right = delete(root->right, temp->data, temp->name);
        } else {
            root->data -= deduct;
        }
    }

    return root;
}

void search(tree_node *root, char name[]){

    if (root == NULL) {
        printf("%s not found\n", name);
        return;
    }

    if (strcmp(name, root->name) == 0) {
        printf("%s %d\n", root->name, root->data);
        return;
    }

    if (strcmp(name, root->name) < 0) {
        search(root->left, name);
    } else {
        search(root->right, name);
    }


}


void calculateAverage(tree_node *root, float *sum, int *count) {
    if (root == NULL) {
        return;
    }

    calculateAverage(root->left, sum, count);
    *sum += root->data;
    (*count)++;
    calculateAverage(root->right, sum, count);
}

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

int height(tree_node *root) {
    if (root == NULL) {
        return 0;
    }

    int left_height = height(root->left);
    int right_height = height(root->right);

    return (left_height > right_height ? left_height : right_height) + 1;
}

void height_balance(tree_node *root) {
    if (root == NULL) {
        return;
    }

    int left_height = height(root->left);
    int right_height = height(root->right);

    int balance_factor = left_height - right_height;

    

    height_balance(root->left);
    height_balance(root->right);

    if(balance_factor == 0){
        printf("left height = %d right height = %d balanced\n", left_height, right_height);
    } else {
        printf("left height = %d right height = %d not balanced\n", left_height, right_height);
    }
}


int total(tree_node *root) {
    if (root == NULL) {
        return 0;
    }

    return total(root->left) + total(root->right) + root->data;
}


int calc_below(tree_node *root, char name[]) {
    
    
}


void printAll(tree_node *root) {
    if (root == NULL) {
        return;
    }

    printAll(root->left);
    printf("%s %d\n", root->name, root->data);
    printAll(root->right);
}

int main() {
    int n;

    printf("Enter the number of commands: ");
    scanf("%d", &n);
    
    char command[MAXLEN];
    char name[MAXLEN];
    tree_node *root = NULL;

    while (n--) {
        scanf("%s", command);
        for (int i = 0; command[i]; i++) {
            command[i] = tolower(command[i]);
        }

        if (strcmp(command, "add") == 0) {
            int fine;
            scanf("%s %d", name, &fine);
            for (int i = 0; name[i]; i++) {
                name[i] = tolower(name[i]);
            }
            root = insert(root, fine, name);
        } else if (strcmp(command, "deduct") == 0) {
            int deduct;
            scanf("%s %d", name, &deduct);
            for (int i = 0; name[i]; i++) {
                name[i] = tolower(name[i]);
            }

            root = delete(root, deduct, name);
        } else if(strcmp(command, "search") == 0) {
            scanf("%s", name);
            for (int i = 0; name[i]; i++) {
                name[i] = tolower(name[i]);
            }

            search(root, name);
        } else if(strcmp(command, "average") == 0) {
            float mean;
            mean = average(root);
            printf("%.2f\n", mean);
        } else if(strcmp(command, "height_balance") == 0) {

            height_balance(root);
        
        // change the function call to calc below
        } else if(strcmp(command, "calc_below") == 0) {
            scanf("%s", name);
            int total_below = calc_below(root, name);
            printf("%d\n", total_below);
        }
    }

    printAll(root);

    return 0;
}