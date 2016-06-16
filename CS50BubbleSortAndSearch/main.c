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
    int arrayOfInts[sizeOfArray];
    
    for (int populateCounter = 0; populateCounter < sizeOfArray; populateCounter++)
    {
        printf("Enter int #%i:", populateCounter + 1);
        arrayOfInts[populateCounter] = GetInt();
    }
    
    sortInts(sizeOfArray, arrayOfInts);
    
    return 0;
}

int sortInts(int sizeOfArray, int arrayOfInts[])
{
    int lastPositionArray = sizeOfArray - 1;
    int smallestInt;
    int forwardShiftCounter;
    int testAllDigits;
    int comparisonCounter;
    int loopIterations = loopIterationsFunc(sizeOfArray);
    int lastPositionDup = lastPositionArray;
    
    printf("Unsorted: ");
    for (int printCounter = 0; printCounter < sizeOfArray; printCounter++)
    {
        printf("%i ", arrayOfInts[printCounter]);
    }
    printf("\n");
    
    printf("Loop iterations = %i \n", loopIterations);
    
    testAllDigits = 0;
    comparisonCounter = 1;

    while (loopIterations > 0)
    {
        for (int arrayCounter = testAllDigits; arrayCounter < sizeOfArray; arrayCounter++)
        {
            if (arrayOfInts[testAllDigits] > arrayOfInts[arrayCounter + 1])
            {
                printf("%i COMP %i.\n", testAllDigits, arrayCounter + 1);
                /*
                // Step 1
                // ArrayCounter = 0
                smallestInt = arrayOfInts[arrayCounter + 1];
                arrayOfInts[arrayCounter + 1] = arrayOfInts[arrayCounter];
                arrayOfInts[0] = smallestInt;
                
                // Step 2
                // ArrayCounter = 1
                smallestInt = arrayOfInts[arrayCounter + 1];
                arrayOfInts[arrayCounter + 1] = arrayOfInts[arrayCounter];
                arrayOfInts[arrayCounter] = arrayOfInts[arrayCounter - 1];
                arrayOfInts[0] = smallestInt;
                
                // Step 3
                // ArrayCounter = 2
                smallestInt = arrayOfInts[arrayCounter + 1];
                arrayOfInts[arrayCounter + 1] = arrayOfInts[arrayCounter];
                arrayOfInts[arrayCounter] = arrayOfInts[arrayCounter - 1];
                arrayOfInts[arrayCounter - 1] = arrayOfInts[arrayCounter - 2];
                arrayOfInts[0] = smallestInt;
                
                // Step 4
                // ArrayCounter = 3
                smallestInt = arrayOfInts[arrayCounter + 1];
                arrayOfInts[arrayCounter + 1] = arrayOfInts[arrayCounter];
                arrayOfInts[arrayCounter] = arrayOfInts[arrayCounter - 1];
                arrayOfInts[arrayCounter - 1] = arrayOfInts[arrayCounter - 2];
                arrayOfInts[arrayCounter - 2] = arrayOfInts[arrayCounter - 3];
                arrayOfInts[0] = smallestInt;
                */
                
                //WORKING
                smallestInt = arrayOfInts[arrayCounter + 1];
                arrayOfInts[arrayCounter + 1] = arrayOfInts[arrayCounter];
                
                // Shifts digits forward
                forwardShiftCounter = 0;
                if (arrayCounter > 0)
                {
                    for (int whatToShiftCounter = 1; whatToShiftCounter < sizeOfArray; whatToShiftCounter++)
                    {
                        arrayOfInts[arrayCounter + forwardShiftCounter] = arrayOfInts[arrayCounter - whatToShiftCounter];
                        forwardShiftCounter--;
                    }
                }
            
                comparisonCounter++;
                
                arrayOfInts[0] = smallestInt;
                
                if (lastPositionDup == 0)
                {
                    
                }
                else if (comparisonCounter % lastPositionDup == 0)
                {
                    testAllDigits++;
                    comparisonCounter = 1;
                    lastPositionDup--;
                }
            }
        }
        loopIterations--;
    }
    
    printf("Sorted: ");
    for (int printCounter = 0; printCounter < sizeOfArray; printCounter++)
    {
        printf("%i ", arrayOfInts[printCounter]);
    }
    printf("\n");
    
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
