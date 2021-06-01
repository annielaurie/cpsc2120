
// annie hayes cpsc 2120
// ahayes5@g.clemson.edu
// review assignment 1

#include <iostream>
#include <vector>
#include <string>
using namespace std;

int main()
{
    void ReadStdIn(string); //declare function
    
    string input; //declare string
    
    getline(cin, input);  //take input and store in string
    
    ReadStdIn(input);   //call function
 
    return 0;
 
}