
// annie hayes cpsc 2120
// ahayes5@g.clemson.edu
// review assignment 7

#include "review.h"

int Fibonacci(int num)
{
    //set number to 0
    int finalNum = 0;
    if (num < 1)
    {
        finalNum = 1;
    }
     if (num > 1)
    {
        //finonacci sequence
        int counter = 1;
        int val1 = 1;
        int val2 = 1;
        while (counter < num)
        {
            finalNum = val1 + val2;
            val1 = val2;
            val2 = finalNum;
            counter++;
            
            
        }
        
    }
   //return final number
   return finalNum; 
}