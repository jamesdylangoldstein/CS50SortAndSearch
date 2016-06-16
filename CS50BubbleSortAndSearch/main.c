//
//  main.c
//  CS50SortAndSearch
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
    
    for (int populateCounter = 0; populateCounter < sizeOfArray; populateCounter++)
    {
        printf("Enter int #%i:", populateCounter + 1);
        arrayOfInts[populateCounter] = GetInt();
    }
    
    sortInts(sizeOfArray, arrayOfInts);
    
    printf("Sorted: ");
    for (int printCounter = 0; printCounter < sizeOfArray; printCounter++)
    {
        printf("%i ", arrayOfInts[printCounter]);
    }
    printf("\n");
    
    return 0;
}

int sortInts(int sizeOfArray, int arrayOfInts[])
{
    int lastPositionArray = sizeOfArray - 1;
    int smallestInt;
    int forwardShiftCounter;
    int testAllDigits;
    int comparisonCounter;
    int loopIterations = lastPositionArray;
    int lastPositionDup = lastPositionArray;
    int testAllDigitsUppedCounter = 0;
    
    printf("Unsorted: ");
    for (int printCounter = 0; printCounter < sizeOfArray; printCounter++)
    {
        printf("%i ", arrayOfInts[printCounter]);
    }
    printf("\n");
    
    testAllDigits = 0;
    
    comparisonCounter = 0;
    
    int startingPoint = 1;

    while (loopIterations > 0)
    {
        for (int arrayCounter = 0; arrayCounter < sizeOfArray; arrayCounter++)
        {
            if (arrayOfInts[testAllDigits] > arrayOfInts[testAllDigits + startingPoint])
            {
                printf("%i COMP %i.\n", testAllDigits, (testAllDigits + startingPoint));
        
                smallestInt = arrayOfInts[testAllDigits + startingPoint];
                arrayOfInts[testAllDigits + startingPoint] = arrayOfInts[testAllDigits];
                
                arrayOfInts[testAllDigits] = smallestInt;
                
            }
            else
            {
                printf("%i COMP %i.\n", testAllDigits, (testAllDigits + startingPoint));
            }

            startingPoint++;
            comparisonCounter++;

            if (testAllDigitsUppedCounter == (lastPositionArray - 1))
            {
                return 0;
            }
            else if (comparisonCounter % lastPositionDup == 0)
            {
                testAllDigits++;
                comparisonCounter = 0;
                lastPositionDup--;
                testAllDigitsUppedCounter++;
                startingPoint = 1;
            }
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
