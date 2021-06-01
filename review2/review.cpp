
// annie hayes cpsc 2120
// ahayes5@g.clemson.edu
// review assignment 2


#include "review.h"
using namespace std;

//function for string
int WriteOut(std::string output)
{
    int returnValue = 1;
    int num;
    stringstream geek(output);
    geek >> num;
    cout << num << endl;    //print int
    return returnValue;     //return 1
}

//function for int
int WriteOut(int output)
{
    int returnValue = 2;
    int num = output;
    cout << num << endl;    //print int
    return returnValue;     //return 2
    
}

//function for double
int WriteOut(double output)
{
    int returnValue = 3;
    int num = output;
    cout << num << endl;    //print int
    return returnValue;     //return 3
}






