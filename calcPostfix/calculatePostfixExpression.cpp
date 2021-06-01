#include <string>
#include <stack>
#include <iostream>
using namespace std;

//Calculates a postfix expression with integer operands using a stack
//The expression is represented using an array of strings
//Each string is either an operand or operator symbol
//Operator symbols:
//"+" addition
//"-" subtraction
//"*" multiplication
//"/" divison
//"%" remainder
//Example expression: "8", "5", "-" evaluates to a result of 3:
//1: push 8, 2: push 5,
//3: "-"-> pop top two values, earlier value is the left-side operand: 8 - 5
//The result of the operation (8-5) is 3, push 3 onto stack
//After evaluation of the expression, the final result should be
//the only value on the stack, return 0 if the stack is
//non-empty after popping the result
//Return 0 if expression is zero-length or if there are insufficient operands
//for an operation
//The STL Stack class can be used
//To easily convert a numeric string to an int you may use the stoi() function
//which takes a string as a parameter and returns a string
int calculatePostfixExpression(string expression[], int length)
{
    stack<int> info;
    int result = 0;
    info.push('X');
    if (length == 0 || length == 1 || length == 2)
    {
        if (length == 0 || length == 2)
        {
            return 0;
        }
        if(length == 1 && atoi(expression[0].c_str()))
        {
            info.push(stoi(expression[0]));
            result = info.top();
            return result;
        } 
        else if(length ==1)
        {
            return 0;
        }
    }
    for (int i = 0; i < length; i++)
    {
        if (expression[i] == "+"|| expression[i] == "-" || expression[i] == "*" || expression[i] == "/" || expression[i] == "%")
        {
           cout << "operation: " << expression[i] << endl;
            int second = info.top();
            info.pop();
            
            int first = info.top();
            info.pop();
            
            if (expression[i] == "+")
            {
                result = first + second;
            }
            if (expression[i] == "-")
            {
                result = first - second;
            }
            if (expression[i] == "*")
            {
                result = first * second;
            }
            if (expression[i] == "/")
            {
                result = first / second;
            }
            if (expression[i] == "%")
            {
                result = first % second;
            }
           cout << "answer: " << result << endl;
            info.push(result);
        }
        else
        {
            int newDigit = stoi(expression[i]);
            cout << "digit: " << newDigit << endl;
            info.push(newDigit);
            
        }
        
    }
    
    int returnValue = info.top();
    info.pop();
    if (info.top() != 'X')
    {
        cout << "value is zero" << endl;
        result = 0;
    }
    return result;
}

int main()

{
    string expression[] = {"+"};
    int len = sizeof(expression)/sizeof(expression[0]); //calculate length of expression
   cout << calculatePostfixExpression(expression, len) << endl; //calling calculatePostfixExpression()
    return 0;

}