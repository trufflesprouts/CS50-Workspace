#include <cs50.h>
#include <stdio.h>

int main(void)
{
    printf("minutes: ");
    int n = GetInt();
    printf("bottles: %d\n", n*12);
}

