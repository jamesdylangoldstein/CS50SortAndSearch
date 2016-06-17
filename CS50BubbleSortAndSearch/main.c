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
int searchForInt(int intToFind, int startValue, int halfSize, int sizeOfArray, int arrayOfInts[]);

int main(int argc, const char * argv[])
{
    printf("How many integers would you like sorted:");
    int sizeOfArray = GetInt();
    int arrayOfInts[sizeOfArray + 1];
    int intToFind;
    int halfSize = sizeOfArray;
    
    for (int populateCounter = 0; populateCounter < sizeOfArray; populateCounter++)
    {
        printf("Enter int #%i:", populateCounter + 1);
        arrayOfInts[populateCounter] = GetInt();
    }
    
    printf("Unsorted: ");
    for (int printCounter = 0; printCounter < sizeOfArray; printCounter++)
    {
        printf("%i ", arrayOfInts[printCounter]);
    }
    printf("\n");
    
    sortInts(sizeOfArray, arrayOfInts);
    
    printf("Sorted: ");
    for (int printCounter = 0; printCounter < sizeOfArray; printCounter++)
    {
        printf("%i ", arrayOfInts[printCounter]);
    }
    printf("\n");
    printf("Enter the integer you'd like to find\n");
    intToFind = GetInt();
    searchForInt(intToFind, 0, halfSize, sizeOfArray, arrayOfInts);
    
    return 0;
}

int sortInts(int sizeOfArray, int arrayOfInts[])
{
    int lastPositionArray = sizeOfArray - 1;
    int smallestInt;
    int testAllDigits;
    int comparisonCounter;
    int loopIterations = lastPositionArray;
    int lastPositionDup = lastPositionArray;
    int testAllDigitsUppedCounter = 0;
    
    testAllDigits = 0;
    
    comparisonCounter = 0;
    
    int startingPoint = 1;

    while (loopIterations > 0)
    {
        for (int arrayCounter = 0; arrayCounter < sizeOfArray; arrayCounter++)
        {
            if (arrayOfInts[testAllDigits] > arrayOfInts[testAllDigits + startingPoint])
            {
                smallestInt = arrayOfInts[testAllDigits + startingPoint];
                arrayOfInts[testAllDigits + startingPoint] = arrayOfInts[testAllDigits];
                
                arrayOfInts[testAllDigits] = smallestInt;
                
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

int searchForInt(int intToFind, int startValue, int halfSize, int sizeOfArray, int arrayOfInts[])
{
    halfSize = halfSize/2;
    printf("halfSize = %i \n", halfSize);
    printf("startValue = %i \n", startValue);
    
    if (halfSize == 0)
    {
        printf("%i not found!\n", intToFind);
        return 0;
    }
    int left = startValue + halfSize - 1;
    int right = startValue + halfSize;
    
    printf("comparing %i to %i\n", arrayOfInts[left], arrayOfInts[right]);
    if (intToFind < arrayOfInts[left])
    {
        // Left side
        printf("It's on the left side\n");
        searchForInt(intToFind, 0, halfSize, sizeOfArray, arrayOfInts);
    }
    else if (intToFind > arrayOfInts[right])
    {
        // Right side
        printf("It's on the right side\n");
        searchForInt(intToFind, halfSize, halfSize, sizeOfArray, arrayOfInts);
    }
    else if (intToFind == arrayOfInts[left])
    {
        // We found it
        printf("%i found in position %i!\n", intToFind, startValue + halfSize);
        
    }
     else if (intToFind == arrayOfInts[right])
    {
        // We found it
        printf("%i found in position %i!\n", intToFind, startValue + halfSize + 1);
        return 0;
    }
    
    if (halfSize == 1)
    {
        printf("%i not found!\n", intToFind);
        return 0;
    }
    
    
    return 0;
}
