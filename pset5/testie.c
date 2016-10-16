#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>
#include <stdbool.h>
#include <string.h>

// Linked List Building Block
typedef struct sllist
{
    char* word;
    struct sllist* next;
}
sllnode;



// Initialize Hashtable
static const int tablesize = 10000;
sllnode* hashtable[tablesize];
void initable(void)
{
    for (int i = 0 ; i < tablesize ; i++)
    {
        hashtable[i] = NULL;
    }
}



// Hash Function
unsigned long
int hash(char *str)
{
    unsigned long hash = 5381;
    int c;

    while ((c = *str++))
    {
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    }
    return hash % tablesize;
}



int main(void)
{
    char str[47];
    int counter =0;
    
    FILE* dic = fopen("dictionaries/small", "r");
    while (fgets(str, 47, dic) != NULL && str[0] != '\n')
    {
        counter++;
        
        strtok(str, "\n");
        unsigned long hashvalue = hash(str);
        // Make a temporary Node
        sllnode* temp = malloc(sizeof(sllnode));
        temp -> word = malloc(47);
        if (temp == NULL || temp -> word == NULL)
        {
            printf("problemo");
        }
        strcpy(temp -> word, str);
        
        // Insert in the HashTable
        temp -> next = hashtable[hashvalue];
        hashtable[hashvalue] = temp;
    }
    printf("%i\n", counter);
}

