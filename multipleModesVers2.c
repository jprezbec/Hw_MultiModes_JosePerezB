#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "mode.h"
#include "maximum.h"
#define SIZE 30

int main()
{
    int i,n;
    i=0;

    double number[30];
    FILE* in_file = fopen("data.txt", "r"); //only open a pre-exisiting file in read mode. 
         
    if (! in_file ) // equivalent to saying if ( in_file == NULL ) 
    {  
        printf("oops, file can't be read\n"); 
        exit(-1); 
    } 
    // attempt to read the next line and store 
    // the value in the "number" variable 
    while ( fscanf(in_file, "%lf", &number[i] ) == 1 )  
    { 
        printf("Scores read: %lf\n", number[i]);
        i++; 
    } 


    //POPULATE THE ARRAY WITH RESPONSES:
    for(i=0; i<SIZE; i++)
        printf("Position [%d] = %lf\n", i+1, number[i]);

    //Now we compute the maximum

    double max;

    max = findMax(number, SIZE);
    
    printf("Maximum value is : %lf\n", max);

    int intMax = (int)max;

    //Now we compute the frequencies
    int *frequencies = calloc(intMax, sizeof(int)); // 

    if (frequencies == NULL) 
    {
        perror("Error in assigning memory");
        exit(EXIT_FAILURE);
    }
   
    for(i=0; i<SIZE; i++) //Go to all the original array (size n)
    {
        //printf("Value of number[%d] = %d\n", i, (int)number[i]);
        frequencies[(int)number[i]] = frequencies[(int)number[i]] + 1;
        //printf("frequencies[%d] = %d\n", (int)number[i], frequencies[(int)number[i]]);
    }

    printf("\n\nFREQUENCIES\n");
    for(i=0; i<=intMax;i++)
        printf("%d   %d\n", i, frequencies[i]);

    findModes(frequencies, intMax, number, n);

}