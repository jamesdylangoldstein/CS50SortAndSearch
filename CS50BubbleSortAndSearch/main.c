//
//  main.c
//  CS50BubbleSortAndSearch
//
//  Created by James Dylan Goldstein on 6/15/16.
//  Copyright © 2016 James Dylan Goldstein. All rights reserved.
//

#include <stdio.h>
#include "cs50.h"

int sortInts(int sizeOfArray, int arrayOfInts[]);
int loopIterationsFunc(int sizeOfArray);

int main(int argc, const char * argv[])
{
    printf("How many integers would you like sorted:");
    int sizeOfArray = GetInt();
    int arrayOfInts[sizeOfArray + 1];
    int bufferArrayInts[sizeOfArray + 1];
    int lastPositionArray = sizeOfArray - 1;
    
    for (int populateCounter = 0; populateCounter < sizeOfArray; populateCounter++)
    {
        printf("Enter int #%i:", populateCounter + 1);
        arrayOfInts[populateCounter] = GetInt();
    }
    
    sortInts(sizeOfArray, arrayOfInts);

    for (int printCounter = 0; printCounter < sizeOfArray; printCounter++)
    {
        printf("%i\n", arrayOfInts[printCounter]);
    }
    
    return 0;
}

int sortInts(int sizeOfArray, int arrayOfInts[])
{
    int lastPositionArray = sizeOfArray - 1;
    
    int sortCounterOne = 0;
    int sortCounterReset = 0;
    int startSort = 0;
    int startSortCounter = 0;
    int loopIterations;
    int maxcomparisons = sizeOfArray - 2;
    int negativeIterCounter = lastPositionArray;
    
    loopIterations = loopIterationsFunc(sizeOfArray);
    
    while(loopIterations >= 0)
    {
        printf("DOING THIS LOOP %i TIMES\n", loopIterations);
        if (arrayOfInts[startSort] > arrayOfInts[lastPositionArray - sortCounterOne])
        {
            int bufferInt = arrayOfInts[sortCounterOne];
            arrayOfInts[sortCounterOne] = arrayOfInts[lastPositionArray - sortCounterOne];
            arrayOfInts[lastPositionArray = sortCounterOne] = bufferInt;
            sortCounterOne++;
        }
        sortCounterReset++;
        sortCounterOne++;
        startSortCounter++;
        
        if (negativeIterCounter == 0)
        {
            return 0;
        }
        else if (startSortCounter % negativeIterCounter == 0)
        {
            startSort++;
            startSortCounter = 0;
            negativeIterCounter--;
        }
        
        if (maxcomparisons == 0)
        {
            return 0;
        }
        else if (sortCounterOne % maxcomparisons == 0)
        {
            sortCounterOne = 0;
            maxcomparisons--;
        }
        
        loopIterations--;
    }
    
    return 0;
}

int loopIterationsFunc(int sizeOfArray)
{
    int loopIterations = 0;
    
    for(int loopIterCounter = 1; loopIterCounter < sizeOfArray; loopIterCounter++)
    {
        loopIterations += sizeOfArray - loopIterCounter;
    }
    
    return loopIterations;
}