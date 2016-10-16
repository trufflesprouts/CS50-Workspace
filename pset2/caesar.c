#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cyperize(int letter, int k);


int main(int argc, string argv[])
{
    if (argc != 2)
    {
        printf("Where's the damn key?\n");
        return 1;
    }
    
    int k = atoi(argv[1]);
    string text = GetString();  
    
    for (int i = 0, n = strlen(text); i < n; i++)
    {
        printf("%c", cyperize(text[i], k));
    }
    printf("\n");
    
    return 0;
}



int cyperize(int letter, int k)
{
    if (letter >= 65 && letter <= 90)
    {
        letter = letter + k;
        while (letter > 90)
        {
            letter = letter - 26;
        }
    }
    else if (letter >= 97 && letter <= 122)
    {
        letter = letter + k;
        while (letter > 122)
        {
            letter = letter - 26;
        }
    }
    return letter;
}