/*
 * Name: Annie Hayes
 * Date Submitted: 02/17
 * Lab Section: 004
 * Assignment Name: Lab 4
 */

#pragma once
#include <iostream>
#include <vector>

using namespace std;

template <class T>
void printArray(std::vector <T> &lst)
{
    for(int i = 0; i < lst.size(); i++)
    {
        std::cout << " " << lst[i];
        
    }
    std::cout << endl;
}

template <class T>
void swap(std::vector <T> &lst, int first, int second)
{
    //switches positions
    T temp = lst[first];
    lst[first] = lst[second];
    lst[second] = temp;
}

template <class T>
int pivot(std::vector<T> &lst, int start, int end){
    //initiate variables 
    int pivot = ((end-start)/2)+start;
    T pivotVal = lst[pivot];
    int startCounter = start;
    int endCounter = end;
    
    //loop through index to find pivot
    while(startCounter <= endCounter)
    {
        while(lst[endCounter]>pivotVal)
        {
            endCounter--;
    
        }
        while(lst[startCounter]<pivotVal)
        {
            startCounter++;
        }
        
        //swap pivot
        if(startCounter <= endCounter)
        {
            swap(lst, startCounter, endCounter);
            startCounter++;
            endCounter--;
        }
    }
    //return pivot
    return startCounter;
}

template <class T>
void quickSort(std::vector<T> &lst, int start, int end)
{
    if(start < end)
    {
        //initialize variable
        int pivotNum = pivot(lst, start, end);
        
        //sort beginning
        quickSort(lst, start, pivotNum-1);
        //sort end
        quickSort(lst, pivotNum, end);
    }
    else 
    {
        return;
    }
}
      

template <class T>
std::vector<T> quickSort(std::vector<T> lst)
{
    //sort array
    quickSort(lst, 0, lst.size()-1);
    //return array
    return lst;
}

template <class T>
std::vector <T> merge(std::vector <T> lst)
{
    std::vector<T> endArray;
    //intiate variables 
    int size = lst.size();
    int start = 0;
    int halfSize = size/2;
    int finish = halfSize;
    
    //run through array
    for(int i = 0; i < size; i++)
    {
        //first half
        if(start < halfSize && finish < size)
        {
            if(lst[start] <= lst[finish])
            {
                //add to start
                endArray.push_back(lst[start++]);
            }
            else
            {
                //add to end
                endArray.push_back(lst[finish++]);
            }
        }
        //second half
        else if(start >= halfSize)
        {
            //add to end
            endArray.push_back(lst[finish++]);
        }
        else if (finish >= halfSize)
        {
            //add to start
            endArray.push_back(lst[start++]);
        }
    }
    //return new array
    return endArray;
}


template <class T>
std::vector<T> mergeSort(std::vector<T> lst)
{
    //first half
    quickSort(lst,0,(lst.size()/2)-1);
    //second half
    quickSort(lst, lst.size()/2, lst.size()-1);
    //merge lists
    return merge(lst);
}








