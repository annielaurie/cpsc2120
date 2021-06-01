/*
 * Name: Annie Hayes
 * Date Submitted: 02/17
 * Lab Section: 004
 * Assignment Name: Lab 4
 */
 #include "Searches.h"
#include "Sorts.h"

//#pragma once
#include<vector>
#include <iostream>

using namespace std;

int main()
{
    std::vector<int> intTest2 {25, 55, 45, 30, 10, 1, 50, 35, 15, 5, 20, 40};
    std::vector<int> a = mergeSort(intTest2);
    std::cout << "return Array: " <<endl;
    printArray(a);
    return (0);
}
