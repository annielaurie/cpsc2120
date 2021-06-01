/*
 * Name: Annie Hayes
 * Date Submitted: 03/03/2021
 * Lab Section: 004
 * Assignment Name: Lab 5
 */

#include "stringset.h"

Stringset::Stringset() : table(4), num_elems(0), size(4) {}

//Used in test cases and testStringset() in main.cpp, do not modify
vector<list<string>> Stringset::getTable() const
{
    return table;
}

//Used in test cases and testStringset() in main.cpp, do not modify
int Stringset::getNumElems() const
{
    return num_elems;
}

//Used in test cases and testStringset() in main.cpp, do not modify
int Stringset::getSize() const
{
    return size;
}

void Stringset::insert(string word)
{
    //if the word is not already in list
    if (find(word) == false) 
    {
        //initialize variables
        string myWord = " ";
        std::hash<std::string> str_hash;
        
        //if the number of elements is bigger than the size
        if (num_elems >= size) 
        {
            //asssign size variables
            int prevSize = size;
            size = size * 2; 
            
            //make a new vector list
            vector<list<string>> newTable(size);
            
            //increment through size of list
            for (int i = 0; i < prevSize; i++) 
            {
                //set start to beginning of variables
                list<string>::const_iterator myList = table[i].begin();
                
                //while list isnt at the end of the table
                while(myList != table[i].end()) 
                {
                    //insert word
                    myWord = *myList;
                    newTable[(str_hash(myWord) % size)].push_back(myWord);
                    table[i].remove(word);
                    myList++;
                }
            }
            //set table equal to new table
            table = newTable;
        }
        table[(str_hash(word) % size)].push_back(word);
        num_elems++;
    }
    
}

bool Stringset::find(string word) const
{
    //make string hash
    std::hash<std::string> myHash;
    
    //assign index of word
    int index = myHash(word) % size;
    
    //create list 
    list<string>::const_iterator myList = table[index].begin();
    
    //while the list is not at the end of the names
    while (myList != table[index].end()) 
    {
        if (*myList == word)
        {
            return true;
            
        }
            myList++;
    }
    return false;
}

void Stringset::remove(string word)
{
    //if word is in list
   if (find(word) == true) 
   {
       //create hash
       std::hash<std::string> myHash;
       //find word & remove it
       table[(myHash(word) % size)].remove(word);
       //decrement variabls
       num_elems--;
    }
}

