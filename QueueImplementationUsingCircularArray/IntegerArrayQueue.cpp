/*
 * Name: Annie Hayes
 * Date Submitted: Feb 10th
 * Lab Section: 004
 * Assignment Name: Circular Array
 */
#include "IntegerArrayQueue.h"
using namespace std;

bool IntegerArrayQueue::enqueue(int value)
{
    if (back == front - 2 || (front == 0 && back == size - 2))
    {
        //queue is full
        //cout << "queue is full" <<endl;
        return false;
        
    } 
        int temp;
        //back is at max size, set to 0
        if (back == size - 1)
        {
            temp = 0;
            
        } 
        else
        {
           // cout << "temp != 0" << endl;
            temp = back + 1;
        }
        back = temp;
        array[temp] = value;
        return true;
        
    
}

int IntegerArrayQueue::dequeue()
{
   if(back == front - 1 || back == 0 && front == size - 1)
   {
       //queue is empty 
      //cout << "queue is empty" << endl;
       return 0;
   }
   else 
   {
       int temp;
       int value;
       value = array[front];
       array[front] = 0;
       if (front == size)
       {
           //if front is at max size, set to zero
           front = 0;
       }
       else
       {
           front = front + 1;
       }
       return value;
   }
}

int main ()
{
    
    IntegerArrayQueue queue(3); 
   
    queue.enqueue(2);
    queue.printArrayQueue();
    cout << endl;
    queue.dequeue();
 
    return 0;
}

