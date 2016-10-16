#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    // Ask for a variable (change in dollars)
    printf("O hai! How much change is owed?\n");
    int change = round(GetFloat()*100);
    
    // Check that it's not negative
    if (change <= 0)
    {
        do
        {
            printf("Seriously?!\n");
            change = round(GetFloat()*100);
        }
        while (change < 1);
    }
    
    // Calculate total coinds spent
    int coins = 0;
    
    while (change >= 25)
    {
        change = change - 25;
        coins++ ;
    }
    
    while (change >= 10)
    {
        change = change - 10;
        coins++ ;
    }
    
    while (change >= 5)
    {
        change = change - 5;
        coins++ ;
    }
    
    while (change >= 1)
    {
        change = change - 1;
        coins++ ;
    }

    // Return answer
    printf("%d\n", coins);
}