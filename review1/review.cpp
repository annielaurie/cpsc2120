
// annie hayes cpsc 2120
// ahayes5@g.clemson.edu
// review assignment 1

#include <iostream>
#include <string>
#include <sstream> 
using namespace std;

void ReadStdIn(string test)
{
    //decared variables int, double, string

    int num1 = 0;

    double num2 = 0;

    string word = "";

   //save input string as values
    stringstream geek(test);

    geek >> num1;

    geek >> num2;

    geek >> word;

   
    //print values
    cout << num1 << endl;

    cout << num2 << endl;

    cout << word << endl;
}
