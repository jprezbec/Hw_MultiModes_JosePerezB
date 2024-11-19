#include <stdio.h>


void findModes(int frequencies[], int m, double arr[], int n)
{
    int i, mode, maxFrequency;

    mode = (int) (arr[0]);

    maxFrequency = frequencies[mode];

    for(i=0; i<m; i++)
    {
        if (frequencies[i] > maxFrequency)
        {
            maxFrequency = frequencies[i];
            mode = (int) i;
        }
    }

    //printf("\nThe mode is %d\n", mode);
    int modes[m];
    //printf("The value of m is %d\n",m);
    int j =0;
    //printf("Mode[%d] = %d\n", j, modes[j]);
    for(i=0; i<m+1; i++)
    {
        //printf("\nfrequencies[%d] = %d\n", i, frequencies[i]);
        if (frequencies[i] == maxFrequency)
        {
            //printf("\nThe value of j is %d\n",j);
            modes[j] = i;
            printf("\nWe find a mode that is %d\n ",i);
            printf("Mode[%d] = %d\n", j, modes[j]);
            j++;
        }
    }


    int counter = j;

    printf("\nThere are %d modes\n", counter);
    
    printf("The array of modes ! \n");
    for(j=0; j<counter; j++)
    {
         printf("Mode[%d] = %d\n", j, modes[j]);
    }

    printf("The number of times that this %d modes appear is:  %d !\n", counter, maxFrequency);

}