/**
 * dictionary.c
 *
 * Computer Science 50
 * Problem Set 5
 *
 * Implements a dictionary's functionality.
 */
 
#include "dictionary.h"

// Initialize Counters
int dictionary_counter = 0;

// Initialize Hashtable
sllnode* hashtable[TABLESIZE];


// Hash Function
unsigned int hash(const char *str)
{
    unsigned int hash = 5381;
    int c;

    while ((c = *str++))
    {
        hash = ((hash << 5) + hash) + c; /* hash * 33 + c */
    }
    return hash % TABLESIZE;
}



/**
 * Loads dictionary into memory.  Returns true if successful else false.
 */
bool load(const char* dictionary)
{
    FILE* dic = fopen(dictionary, "r");
    if (dic == NULL)
    {
        printf("ERROR: Couldn't open dictionary");
        return false;
    }
    
    char str[LENGTH + 2];
    
    while (fgets(str, LENGTH + 2, dic) != NULL && str[0] != '\n')
    {
        // Increment word counter
        dictionary_counter++;

        // Remove tail and determine hash value
        strtok(str, "\n");
        unsigned int hashvalue = hash(str);
        
        // Make a temporary Node
        sllnode* temp = malloc(sizeof(sllnode));
        temp -> word = malloc(LENGTH + 2);
        if (temp == NULL || temp -> word == NULL)
        {
            printf("ERROR: couldn't malloc word");
            return false;
        }
        strcpy(temp -> word, str);
        
        // Insert in the HashTable
        temp -> next = hashtable[hashvalue];
        hashtable[hashvalue] = temp;
    }
    return true;
}



/**
 * Returns true if word is in dictionary else false.
 */
bool check(const char* word)
{

    char temp_word[strlen(word)];
    strcpy(temp_word, word);
    
    for(int i = 0 ; i < strlen(word) ; i++)
    {
        temp_word[i] = tolower(temp_word[i]);
    }

    unsigned int hashvalue = hash(temp_word);
    
    if (hashtable[hashvalue] != NULL)
    {
        sllnode* crawler = hashtable[hashvalue];
        
        while (crawler != NULL)
        {
            if (strcmp(crawler -> word, temp_word) == 0)
                return true;
            else
                crawler = crawler -> next;
        }
    }
    return false;
}



/**
 * Returns number of words in dictionary if loaded else 0 if not yet loaded.
 */
unsigned int size(void)
{
    return dictionary_counter;
}

/**
 * Unloads dictionary from memory.  Returns true if successful else false.
 */
bool unload(void)
{
    for (int i = 0 ; i < TABLESIZE ; i++)
    {
        if (hashtable[i] != NULL)
        {
            sllnode* crawler = hashtable[i];
            while (crawler != NULL)
            {
                sllnode* temp = crawler;
                crawler = crawler -> next;
                free(temp -> word);
                free(temp);
            }
        }
    }
    return true;
}
