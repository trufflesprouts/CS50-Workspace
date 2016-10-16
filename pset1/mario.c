#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int height;
    
    do
    {
        printf("Height: ");
        height = GetInt();
    }
    while(height > 23 || height < 0);


    
    for(int i = 0 ; i < height; i++) 
	{
        for (int q = 0 ; q < height-i-1 ; q++)
        {
        printf (" ");   
        }
        for (int w = 0 ; w < i+1 ; w++)
        {
        printf ("#");  
        }
        printf ("  ");
        for (int w = 0 ; w < i+1 ; w++)
        {
        printf ("#");  
        }
        printf ("\n");
	}	
	return 0;
  
   
}