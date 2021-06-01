/*
 * Name: Annie Hayes
 * Date Submitted: 02/17
 * Lab Section: 004
 * Assignment Name: Lab 4
 */

#pragma once

#include <vector>

template <class T>
int linearSearch(std::vector<T> data, T target)
{
    //for loop to search data
    for( int i = 0; i < data.size(); i++)
    {
        //compares data to find needed value
        if(data[i] == target)
        {
            //returns the position num
            return i;
        }
    }
    //if value not found return -1
    return (-1);
}


template <class T>
int binarySearch(std::vector<T> data, T target)
{
    int start = 0;
    int end = data.size() - 1;
    int middle;
    
    // loops through both sides
    while (start <= end)
    {
        middle = (start + end) / 2; 
       
      // returns the needed one
      if (target == data[middle])
      {
            return middle; 
      }
      if (data[middle] < target)
      {
          //start becomes closer to middle
          start = middle + 1;
      }
      else if(data[middle] > target)
      {
          //end becomes closer to middle
          end = middle - 1;
      }
      
    }
    //if value not found return -1
    return -1;
    
}
