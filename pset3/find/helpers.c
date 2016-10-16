/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>
#include "helpers.h"
#include <math.h>
/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int values[], int n)
{
    int first = 0;
    int last = n - 1;
    
    while (first <= last)
    {
        int middle = (first+last)/2;
        if (values[middle] == value)
        {
            return true;
        }
        else if (values[middle] < value)
        {
            first = middle + 1;    
        }
        else
        {
            last = middle - 1;
        }
    }
    return false;
}


/**
 * Sorts array of n values.
 */
void bubble_sort(int values[], int n)
{
    for (int i = 0 ; i < n ; i++)
    {
        for (int j = 1 ; j < n - i ; j++)
        {
            if (values[j] < values[j-1])
            {
                int temp = values[j];
                values[j] = values[j-1];
                values[j-1] = temp;
            }
        }
    }
    return;
}

void selection_sort(int values[], int n)
{
    int i, j, smallest, temp;
    for (i = 0 ; i < n ; i++)
    {
        smallest = i;
        for (j = i+1 ; j < n  ; j++)
        {
            if (values[j] < values[smallest])
            {
                smallest = j;
            }
        }
        temp = values[i];
        values[i] = values[smallest];
        values[smallest] = temp;
    }
    return;
}

void sort(int values[], int n)
{
    int i, p, temp;
    for (i = 1 ; i < n ; i++)
    {
        p = i;
        while (p > 0 && values[p] < values[p-1])
        {
            temp        = values[p];
            values[p]   = values[p-1];
            values[p-1] = temp;
            p--;
        }
    }
    return;
}
