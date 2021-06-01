/*n this project, you will demonstrate that you know how to use loops to initialize an array.

Create a function called InitializeArray that takes a single integer as a parameter (the length of the array).  The return value should be an integer vector ("vector" is a data type from the C++ Standard Template Library).

This vector should be the length which was passed in, and initialize all values to zero.*/
#include "review.h"
using namespace std;

std::vector<int> InitializeArray(int size)
{
    vector<int> test(size, 0);
    
    return test;
}