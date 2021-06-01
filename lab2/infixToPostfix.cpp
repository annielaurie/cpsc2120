/*
 * Name: Annie Hayes
 * Date Submitted: Feb 5th 2021
 * Lab Section: 004
 * Assignment Name: Lab 2
 */
#include <string>
#include <stack>
#include <iostream>

using namespace std;

// checks to see if parathesis match
int checkBrackets(string infix[], int length)
{
    //variables used:
    int counter = 0;    //counter for open & closed
    int returnValue;    //value to be reuturned
    
    //while the i is less than length of array
    for (int i=0; i<=length; i++)
    {
        if (infix[i] == "(")        //if char is an open parathesis
        {
            counter++;
        }
        else if (infix[i] == ")")   //if char is an closed parathesis   
        {
            counter--;
        }
        else
        {
            //do nothing
        }
        if (counter != 0)           //if paranthesis don't match
        {
            returnValue = 0;        //set returnValue to 0
        }
        else 
        {
            returnValue = length;   //set returnValue to length
        }
    }
    return returnValue;
}

//checks precedence
int symbols(string value)
{
    //-1 = number, 1 = high precedence, 2 = low precendece
    int returnValue;

    if  (value == "*" || value == "/" || value == "%")
    {
        returnValue = 2;  //check for high precedence
    }
    else if (value == "+" || value == "-" ) //check for low precedence
    {
        returnValue = 1;
    }
    else
    {
        returnValue = -1; //value is a number
    }
    return returnValue;
}

int infixToPostfix(string infix[], int length, string postfix[])
{
    //set returnValue using function
    int returnValue = checkBrackets(infix, length);
    //account for when returnValue is > 15
    if (returnValue > 15)
    {
        returnValue = 15;
    }
    
    //variable used:
    int counter = 0;    //counter 
    int cnt = 0;        //counter 2
    
    //intialize stack
    stack<string> opStack;
    
    //track end of stack bu using a character (|)
    opStack.push("|");
    
    for(int i = 0; i < length; i++)
    {
        //if char is a number
        if(isdigit(infix[i][0]))
        {
            postfix[counter++] = infix[i];
        }
        //if char is equal to a closed bracket
        else if (infix[i][0] == ')') //top is closed bracket
        {

            // Check for endChar or (
            while(opStack.top()[0] != '(' && opStack.top()[0] != '|')
            {
                string nextUp = opStack.top();
                opStack.pop();
                postfix[counter++] = nextUp;
                
            }
            
            // increases count
            cnt++;
            
            string temp = opStack.top();
            if (temp[0] == '(')
            {
                opStack.pop();
            }
        }
        else if (infix[i] == "(")
        {
            // adds character to stack
            opStack.push(infix[i]);
            cnt++;

        }
        else
        {
            //while stack is not empty 
           while(!(opStack.empty()))
            {
               if (symbols(infix[i]) <= symbols(opStack.top()) && opStack.top()[0] != '|')
                {
                    string next = opStack.top();    //set string to next value in stack
                    opStack.pop();                  //delete value on top of stack
                    postfix[counter++] = next;      //set array to string
                } else {
                    break;
                }
                
            }
            opStack.push(infix[i]);
        }
    }

    for(counter = counter; counter < (length - cnt); counter++)
    {
        postfix[counter] = opStack.top();  //set array valuse to top of stack
        opStack.pop();  //remove top od stack
    }

    return returnValue;
}

//Main function to test infixToPostfix()
//Should convert 2 + 3 * 4 + ( 5 - 6 + 7 ) * 8
//            to 2 3 4 * + 5 6 - 7 + 8 * +
int main()
{
    string infixExp[] = {"2", "+", "3", "*", "4", "+", "(",
                         "5", "-", "6", "+", "7", ")", "*",
                         "8"};
    string postfixExp[15];
    int postfixLength;

    cout << "Infix expression: ";
    for (int i=0; i<15; i++)
    {
        cout << infixExp[i] << " ";
    }
    cout << endl;
    cout << "Length: 15" << endl << endl;

    postfixLength = infixToPostfix(infixExp, 15, postfixExp);

    cout << "Postfix expression: ";
    for (int i=0; i<postfixLength; i++)
    {
        cout << postfixExp[i] << " ";
    }
    cout << endl;
    cout << "Length: " << postfixLength << endl;
   
    return 0;
}
