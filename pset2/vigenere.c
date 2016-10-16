#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <ctype.h>


int cyperize_letter(int letter, int k);
int realkey(int k);

int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Where's the damn key?\n");
        return 1;
    }
    
    string key = argv[1];
    
    for (int i = 0, n = strlen(key); i < n; i++)
    {
        if (!isalpha(key[i]))
        {
             printf("Keyword must only contain letters A-Z and a-z\n");
             return 1;
        }
    }
    
    string text = GetString();  
    
    for (int i = 0, j = 0, t = strlen(text) ; i < t ; )
    {
        if (j == strlen(key))
        {
            j = 0;
        }
        
        if (!isalpha(text[i]))
        {
            printf("%c", text[i]);
            i++;
        }
        if (isalpha(text[i]))
        {
            printf("%c", cyperize_letter(text[i], key[j]));
            j++;
            i++;
        }

    }
    printf("\n");
    
    return 0;
}


int cyperize_letter(int letter, int k)
{
    if (letter >= 65 && letter <= 90)
    {
        letter = letter + realkey(k);
        while (letter > 90)
        {
            letter = letter - 26;
        }
    }
    else if (letter >= 97 && letter <= 122)
    {
        letter = letter +realkey(k);
        while (letter > 122)
        {
            letter = letter - 26;
        }
    }
    return letter;
}

int realkey(int k)
{
    if (k >= 65 && k <= 90)
    {
        k = k - 65;
    }
    else if (k >= 97 && k <= 122)
    {
        k = k - 97;
    }
    return k;
}
