/*
 * Name: Annie Hayes
 * Date Submitted: Feb 10th
 * Lab Section: 004
 * Assignment Name: Lab 3
 */

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

//Represents an occupied square in the grid
//Do not modify the GridSquare class or its member functions
class GridSquare
{
    private:
        int row, col;
    public:
        GridSquare() : row(0), col(0) 
        {
            
        } //Default constructor, (0,0) square
        GridSquare(int r, int c) : row(r), col(c) 
        {
            
        } //(r,c) square
        //Compare with == operator, used in test cases
        bool operator== (const GridSquare r) const
        {
            if ((row == r.row) && (col == r.col))
            {
                return true;
            }
            return false;
        }
        int getRow() 
        {
            return row; 
            
        } //return row value
        int getCol() 
        {
            return col; 
            
        } //return column value
        //Output using << operator, used in Grouping::printGroups()
        friend ostream& operator<< (ostream& os, const GridSquare obj);
};

//Function definition for <ostream> << <GridSquare>
ostream& operator<< (ostream& os, const GridSquare obj)
{
    os << "(" << obj.row << "," << obj.col << ")";
    return os;
}

/*
Groups squares in 10x10 grid upon construction
Additional private helper functions may be added
Need to implement the constructor that takes a file name
as well as findGroup
The findGroup function's parameter list may be changed based
on how the function is implemented
*/
class Grouping
{
    private:
        int grid[10][10];
        vector<vector<GridSquare>> groups;
    public:
        Grouping() : grid{},groups() {} //Default constructor, no groups
        Grouping(string fileName); //Implement this function
        void findGroup(int r, int c, vector <GridSquare> &a); //Implement this function (recursive)
        void printGroups() //Displays grid's groups of squares
        {
            for(int g=0; g<groups.size(); g++)
            {
                cout << "Group " << g+1 << ": ";
                for(int s=0; s<groups[g].size(); s++)
                {
                    cout << " " << groups[g][s];
                }
                cout << endl;
            }
        }
        vector<vector<GridSquare>> getGroups() //Needed in unit tests
        {
            return groups;
        }
};

//Implement the (parameterized) constructor and findGroup functions below
Grouping :: Grouping(string fileName)
{
    ifstream infile;
    infile.open(fileName);
    vector<GridSquare> vectGrid;
    char temp;
    for(int i = 0; i < 10; i++) 
    {
        int j = 0;
        while(j < 10)
        {
            infile>>temp;
            if(temp =='.')
            {
                grid[i][j]=0;
            }
            else
            {
                grid[i][j]=1;
            }
            j++;
        }
    }
  
    for(int i = 0; i < 10; ++i)
    {
        int j = 0;
        while(j < 10)
        {
            if(grid[i][j]==1)
            {
                findGroup(i, j, vectGrid);
                groups.push_back(vectGrid);
                vectGrid.clear();
            }
            j++;
        }
    }
}
void Grouping :: findGroup(int r, int c, vector<GridSquare> &vectGrid)
{
    if (r >= 10 | r<0) return; 
    if (c >= 10 | c<0) return; 
    if(grid[r][c]==1)
    {
        GridSquare temp(r, c);
        vectGrid.push_back(temp);
        grid[r][c] = 0;
            
        //call findGroup for all the ones around it 
        findGroup(r+1, c, vectGrid); 
        findGroup(r-1, c, vectGrid); 
        findGroup(r, c+1, vectGrid); 
        findGroup(r, c-1, vectGrid); 
        
    }
}

//Simple main function to test Grouping
int main()
{
    Grouping input1("input3.txt");
    input1.printGroups();
  
    return 0;
}