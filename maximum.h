#include <stdio.h>

double findMax(double arr[], int n)
{
    int i;
    double max = arr[0];

    for(i=1; i<n; i++)
    {
        if (arr[i] > max)
            max = arr[i];
    }

    return max;

}