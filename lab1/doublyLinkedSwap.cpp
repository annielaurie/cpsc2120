/*
 * Name: Annie Hayes
 * Date Submitted: Feb 10th
 * Lab Section: 004
 * Assignment Name: swapping nodes
 */
#include "doublyLinkedSwap.h"

void swapWithNext(Node * p)
{
    //if p is NULL, the head node, tail node, or  
    //the node before tail, then doing nothing & exiting method
    if(p != nullptr && p->next != nullptr && p->prev != nullptr && p->next->next != nullptr)
    {
        //set temp ptr of next & prev
        Node* tempNext = p->next;
        Node* tempPrev = p->prev;
        
        //set new next equal to next of next
        p->next=p->next->next;
        
        //set p equal to the prev node of new next node
        p->next->prev = p;
        
        //set tempNext equal to the tempPrev next
        tempPrev->next = tempNext;
        
        //set tempPrev equal to tempNext prev
        tempNext->prev = tempPrev;
        
        //set tempNext equal to new prev
        p->prev = tempNext;
        
        //set p equal to tempNext next
        tempNext->next = p;
    }
}

int main()
{
    return 0;
}