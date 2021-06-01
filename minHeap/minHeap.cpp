/*
 * Name: Annie Hayes
 * Date Submitted: 04/13/2021
 * Lab Section: 004 
 * Assignment Name: Min-Heap
 */
 
#include <iostream>
#include "minHeap.h"
using namespace std;

void minHeap::siftUp(int pos)
{
     // child
    int child = pos;
    // parent
    int parent = (pos - 1) / 2;
    
    // keep comparing with parents
    while(child != 0 && (heap[parent] > heap[child]))
    {
        //switching child & parent
        int temp = heap[parent];
        heap[parent] = heap[child];
        heap[child] = temp;
        // set child as the current parent
        child = parent;
        // create new parent
        parent = (parent-1) / 2;
    }
}

void minHeap::siftDown(int pos)
{
    //initialize variables
    int parent = pos;
    int swapValue = -1;
    int rightChild = (2 * parent) + 2;
    int leftChild = (2 * parent) + 1; 
    //left 
    if((int)heap.size() > leftChild && heap[parent] > heap[leftChild])
    {
        swapValue = leftChild;
        
    }
    
    //right 
    if((int)heap.size() > rightChild && heap[parent] > heap[rightChild])
    {
        if (swapValue == -1)
        {
            swapValue = rightChild;
        }
        else
        {
            if (heap[rightChild] < heap[leftChild])
            {
                swapValue = rightChild;
            }
        }
        
    
    }
    
    if(swapValue == -1)
    {
        return;
    }
    
    //swap
    int temp = heap[parent];
    heap[parent] = heap[swapValue];
    heap[swapValue] = temp;
    
    siftDown(swapValue);
}

minHeap::minHeap(vector<int> data)
{
    //clear the heap
    
    heap.resize(0);
    
    for(int i = 0; i < (int)data.size(); i++)
    {
        heap.push_back(data[i]);
    }
    
    for(int i = heap.size() - 1; i >= 0; i--)
    {
        siftDown(i);
    }
    
}
void minHeap::insert(int value)
{
    //insert at the end
    heap.push_back(value);
    
    int position = heap.size() - 1;
    
    siftUp(position);
}
int minHeap::removeMin()
{
    if(heap.size() == 0) 
    {
        return -1;
    }
    
    int temp = heap[0];
    
    heap[0] = heap[heap.size() - 1];
    
    heap[heap.size() - 1] = temp;
    
    heap.pop_back();
    
    siftDown(0);
    
    return temp;
}

int main()
{
    return 0;

}
