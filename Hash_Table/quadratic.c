#include <stdio.h>
#include <string.h>

// Note: This constrains the limits of static memory allocation...
#define MAX_SIZE 29
#define TABLE_SIZE 59999

struct htable {
    char entries[TABLE_SIZE][MAX_SIZE+1];
};

// Hash Table Functions.
void initTable(struct htable *h);
int hashvalue(char word[]);
void insertTable(struct htable *h, char word[]);
int searchTable(struct htable *h, char word[]);
void deleteTable(struct htable *h, char word[]);

int main() {

    char filename[MAX_SIZE+1], temp[MAX_SIZE+1];
    FILE *ifp;
    int numwords, i;
    struct htable mytable;
    int ans;

    // Get the file name.
    printf("What is the name of the dictionary file?\n");
    scanf("%s", &filename);
    ifp = fopen(filename, "r");

    fscanf(ifp, "%d", &numwords);

    // Read in all of the words from a file into the table.
    // This is only done once.
    printf("get here\n");
    initTable(&mytable);
    printf("init table\n");

    for (i=0; i<numwords; i++) {
        fscanf(ifp, "%s", temp);
        insertTable(&mytable, temp);
    }

    // Allow the user to make changes to the hash table and search for words.
    do {

        printf("Do you want to 1)search word, 2) add word, 3) delete a word?\n");
        scanf("%d", &ans);

        // Search for a word.
        if (ans == 1) {

            printf("What word are you looking for?\n");
            scanf("%s", temp);
            if (searchTable(&mytable, temp))
                printf("%s was found.\n", temp);
            else
                printf("%s was NOT found.\n", temp);
        }

        // Add a word.
        else if (ans == 2) {

            printf("What word do you want to add?\n");
            scanf("%s", temp);
            if (searchTable(&mytable, temp))
                printf("%s was ALREADY in the table\n", temp);
            else
                insertTable(&mytable, temp);
        }

        // Delete a word.
        else if (ans == 3) {

            printf("What word do you want to delete?\n");
            scanf("%s", temp);
            deleteTable(&mytable, temp);

        }

    } while (ans < 4); // Not very user friendly, just quits for any number > 3.

    system("PAUSE");
    return 0;
}

// Pre-condition: none
// Post-condition: Sets each entry in the hash table pointed to by h to the
//                 empty string.
void initTable(struct htable *h) {
     int i;

     // Our marker for an empty entry is the empty string.
     for (i=0; i<TABLE_SIZE; i++)
         strcpy(h->entries[i], "");
}

// Pre-condition: none
// Post-condition: Calculates a hash value for word.
int hashvalue(char word[]) {

    int i, sum=0;

    // Basically represents the value of word in base 128 (according to ascii
    // values) and returns its value mod the TABLE_SIZE.
    for (i=0; i<strlen(word); i++)
        sum = (128*sum + (int)(word[i]))%TABLE_SIZE;

    return sum;
}


void insertTable(struct htable *h, char word[]) {

    int hashval;
    int i = 0;
    hashval = hashvalue(word);

    // Find the first blank spot using quadratic probing.
    while (strcmp(h->entries[hashval], "") != 0) {
        i++;
        // quadratic probing using i^2
        hashval = (hashval + i*i) % TABLE_SIZE;
    }

    strcpy(h->entries[hashval], word);
}


int searchTable(struct htable *h, char word[]) {

    int hashval;
    int i = 0;
    hashval = hashvalue(word);

    // Finding the word using quadratic probing or until we find a blank spot.
    while (strcmp(h->entries[hashval], "") != 0 &&
           strcmp(h->entries[hashval], word) != 0) {
        i++;
        // quadratic probing using i^2
        hashval = (hashval + i*i) % TABLE_SIZE;
    }

    
    if (strcmp(h->entries[hashval], word) == 0)
        return 1;

    
    return 0;
}


void deleteTable(struct htable *h, char word[]) {

    int hashval;
    int i = 0;
    hashval = hashvalue(word);

    
    while (strcmp(h->entries[hashval], "") != 0 &&
           strcmp(h->entries[hashval], word) != 0) {
        i++;
        hashval = (hashval + i*i) % TABLE_SIZE;
    }

    // Reset the word to be the empty string.
    if (strcmp(h->entries[hashval], word) == 0)
        strcpy(h->entries[hashval], "");

    
}
