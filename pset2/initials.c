#include <cs50.h>
#include <stdio.h>
#include <string.h>

int capitalize(int letter);


int main(void)
{
    string name = GetString();
    printf("%c", capitalize(name[0]));
    int s = 32;
    for (int i=0, n = strlen(name) ; i < n ; i++)
    {
        if (name[i] == s)
        {
            printf("%c", capitalize(name[i+1]));
        }
    }
    printf("\n");
}

int capitalize(int letter)
{
    if (letter > 95)
    {
        letter = letter - 32;
    }
    return letter;
}