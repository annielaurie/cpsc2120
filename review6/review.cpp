/*DESCRIPTION
This will test your ability to use loops to modify arrays.  Your function will be passed a double array by reference (with the length as a second parameter.  See starter code).  When your array finishes execution, all values in the array must be incremented by one.

Your function should be named LoopThrough.  A main should not be necessary, but if it is, name it testerMain.cpp.*/

#include "review.h"
void LoopThrough(double * data, int size)
{
    int counter;
   for(int i = 0; i < size; i++)
    {
        data[i]++;
    }
}