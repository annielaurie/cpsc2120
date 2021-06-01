/*
 * Name:Annie Hayes
 * Date Submitted: 04/12/21
 * Lab Section: 004
 * Assignment Name: Lab 9
 */

#include <iostream>
#include <vector>

using namespace std;

void recursiveFunct(int rowCount, int n, vector<vector<bool>>&board, int& count)
{
    int colCount = n;
    
    if(rowCount == 0)
    {
        colCount = (n + 1)/2;
    }
    else
    {
        colCount = n;
    }
    if(rowCount == n)
    {
        if (n % 2 == 1 && board[0][n/2])
        {
            count++;
            return;
        }
        count = count + 2;
        return;
    
    }

    for(int i = 0; i < colCount; i++)
    {
        bool test = true;

        for(int j = rowCount - 1; j >= 0; j--)
        {
            if(board[j][i] == true)
            {
                test = false;
            }
            
            int r = (rowCount-j) + i;
            int l = -(rowCount-j) + i;

            if(l >= 0)
            {
                if(board[j][l] == true)
                {
                    test = false;
                }
            }
            if(r < n)
            {
                if(board[j][r] == true)
                {
                    test = false;
                }
            }
        }

        if(test == true)
        {
            board[rowCount][i] = true;
            recursiveFunct((rowCount + 1), n, board, count);
            board[rowCount][i] = false;
        }
    }
}

//Uses recursion to count how many solutions there are for
//placing n queens on an nxn chess board
int nQueens(int n)
{
    //Implement int nQueens(int n)
    //Feel free to implement any recursive helper functions
    
    vector<vector<bool>> board(n, vector<bool>(n,false));
    int queenCount = 0;
    
    recursiveFunct(0, n, board, queenCount);
    
    return queenCount;
}

int main()
{
    cout << "1: " << nQueens(1) << endl;
    cout << "2: " << nQueens(2) << endl;
    cout << "3: " << nQueens(3) << endl;
    cout << "4: " << nQueens(4) << endl;
    cout << "5: " << nQueens(5) << endl;
    cout << "6: " << nQueens(6) << endl;
    cout << "7: " << nQueens(7) << endl;
    cout << "8: " << nQueens(8) << endl;
    cout << "9: " << nQueens(9) << endl;
    cout << "10: " << nQueens(10) << endl;
    cout << "11: " << nQueens(11) << endl;
    cout << "12: " << nQueens(12) << endl;
    return 0;
}