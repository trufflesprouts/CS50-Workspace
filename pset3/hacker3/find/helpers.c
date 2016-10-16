/**
 * helpers.c
 *
 * Computer Science 50
 * Problem Set 3
 *
 * Helper functions for Problem Set 3.
 */
       
#include <cs50.h>
#include <stdio.h>
#include "helpers.h"

// maximum amount of hay
const int MAXX = 65536;


/**
 * Returns true if value is in array of n values, else false.
 */
bool search(int value, int array[], int n)
{
    int first = 0;
    int last = n-1;
    while (first <=last)
    {
        int middle = (first + last) / 2;
        if (array[middle] == value)
        {
            return true;
        }
        else if (value < array[middle])
        {
            last = middle - 1;
        }
        else
        {
            first = middle + 1;
        }
    }
    return false;
}

/**
 * Sorts array of n values. (COUNTING SORT)
 */
void sort(int values[], int n)
{
    int second_array[MAXX];
    int third_array[n];
    for (int i = 0 ; i < n ; i++)
    {
        second_array[values[i]]++;
    }
    for (int i = 1 ; i <= n ; i++)
    {
        second_array[i] += second_array[i-1]; 
    }
    for (int i = 0 ; i < n ; i++)
    {
        int j = values[i];
        second_array[j] --;
        third_array[second_array[j]] = j;
    }
    for (int i = 0 ; i < n ; i++)
    {
        values[i] = third_array[i];
    }
    return;
}