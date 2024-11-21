/* COP 3502C Programming Assignment 6
This program is written by: Ayaan Khan */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#define MAXLEN 100000

// Trie structure
typedef struct Trie {
    int freq;
    int sum_freq;
    int cur_max_freq;
    struct Trie *children[26];
} Trie;

// Creating the node to add to the trie
Trie *createNode() {

    Trie *temp = (Trie *)malloc(sizeof(Trie));

    temp->freq = 0;
    temp->sum_freq = 0;
    temp->cur_max_freq = 0;

    for (int i = 0; i < 26; i++) {
        temp->children[i] = NULL;
    }

    return temp;
}

// Adding a node to the trie
Trie* insertNode(Trie *root, char *word, int frequency) {
    if (root == NULL) {
        root = createNode();
    }

    Trie *temp = root;
    for (int i = 0; word[i] != '\0'; i++) {
        // making word lowercase
        int index = tolower(word[i]) - 'a';
        if (temp->children[index] == NULL) {
            temp->children[index] = createNode();
        }
        temp = temp->children[index];
        temp->sum_freq += frequency;
    }

    temp->freq += frequency;
    return root;
}

// Searching for the prefix in the trie
void searchPrefix(Trie *root, char *prefix) {
    Trie *temp = root;
    for (int i = 0; prefix[i] != '\0'; i++) {
        int index = tolower(prefix[i]) - 'a';

        // if prefix does not exist we say unrecognized prefix
        if (temp->children[index] == NULL) {
            printf("unrecognized prefix\n");
            return;
        }

        temp = temp->children[index];
    }

    // Finding the most likely letter
    int max_freq = 0;
    char most_likely_letters[26];
    int count = 0;

    for (int i = 0; i < 26; i++) {
        if (temp->children[i] != NULL) {

            // if the frequency is greater than the max frequency we update the max frequency
            if (temp->children[i]->sum_freq > max_freq) {
                max_freq = temp->children[i]->sum_freq;
                count = 0;
                most_likely_letters[count++] = 'a' + i;
            // if equal we add the most likely letter to the array
            } else if (temp->children[i]->sum_freq == max_freq) {
                most_likely_letters[count++] = 'a' + i;
            }
        }
    }

    // if not found we say unrecognized prefix
    if (count == 0) {
        printf("unrecognized prefix\n");
    } else {
        // if found we print the most likely letters
        // if more than 1 that means their frequency is the same (both equally as likely)
        most_likely_letters[count] = '\0';
        printf("%s\n", most_likely_letters);
    }
}

void freeMemory(Trie *root) {
    if (root == NULL) {
        return;
    }

    for (int i = 0; i < 26; i++) {
        freeMemory(root->children[i]);
    }

    free(root);
}

int main() {
    int n;
    scanf("%d", &n);
    Trie *root = NULL;

    while (n--) {
        int num;
        scanf("%d", &num);

        if (num == 1) {
            int frequency;
            char word[MAXLEN];

            scanf("%s %d", word, &frequency);

            for (int i = 0; word[i] != '\0'; i++) {
                word[i] = tolower(word[i]);
            }

            root = insertNode(root, word, frequency);

        } else if (num == 2) {
            char prefix[MAXLEN];
            scanf("%s", prefix);

            for (int i = 0; prefix[i] != '\0'; i++) {
                prefix[i] = tolower(prefix[i]);
            }

            searchPrefix(root, prefix);
        }
    }
    freeMemory(root);
    return 0;
}