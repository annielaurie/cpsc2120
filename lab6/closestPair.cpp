/*
 * Name: Annie Hayes
 * Date Submitted: 04/08/2021
 * Lab Section: 004
 * Assignment Name: Lab 6
 */

#include <iostream>
#include <iomanip>
#include <fstream>
#include <vector>
#include <cmath>

using namespace std;

struct point
{
    double x;
    double y;
};

/*Implement the following function
  Reads in a file specified by the parameter
  Format of file: #of points on first line
                  remaining (#of points) lines: x-value and y-value of point
                  one point per line
                  x-value and y-value are double-precision values and
                  bounded by the unit square 0.0 <= x,y < 1.0
  Should use "spatial hashing" where the #of cells scales with the #of points
  and find the distance between the closest pair of points which will be
  returned as a double type value
*/

//finds distance 
double distCalc(point one, point two)
{
    double twoNum = 2.0;
    double xDist = one.x - two.x;
    double yDist = one.y - two.y;
    double dist = sqrt(pow(xDist, twoNum) + pow(yDist, twoNum));
    return dist;
}

//finds shorter distance
double shorter(double newDist, double oldDist)
{
    if (newDist < oldDist)
    {
        return newDist;
    }
    return oldDist;
}

double closestPair(string filename)
{
    //initialize variables
    int xPos = 0;
    int yPos = 0;
    double pointDist = 0.0;
    double shortestDist = 2.0;
    int num_points = 0;
    int b = 0;
    point value;
    
    //open file & read data
    ifstream input;
    input.open(filename);
    if (input.is_open())
    {
        input >> num_points;
        b = sqrt(num_points);
        
    }
   
    //declares vector for points
    vector<vector<vector<point>>> points(b, vector<vector<point>>(b));
   
    //places all points in respective spots 
    for (int i = 0; i < num_points; i++)
    {
        // from input file
        input >> value.x;
        input >> value.y;
        
        // two points 
        xPos = (int)(value.x * b);
        yPos = (int)(value.y * b);
       
        points[xPos][yPos].push_back(value);
       
    }
    //declare variables 
    int x, y;
    
    //go through points 
    for (int i = 0; i < points.size(); i++)
    {
        for (int j = 0; j < points.size(); j++)
        {
            for (int n = 0; n < points[i][j].size(); n++)
            {
                //set value equal to a specific point
                point value = points[i][j][n];
                 
                for (int m = 0; m < points[i][j].size(); m++)
                {
                    //set two equal to a specific point
                    point two = points[i][j][m];
                    
                    //if values are the same, do nothing
                    if (two.x == value.x && two.y == value.y) 
                    {
                    
                       //do nothing 
                    } 
                    
                    //set pointDist & check for shortest distance
                    else
                    {
                        pointDist = distCalc(points[i][j][m], value);
                        shortestDist = shorter(pointDist, shortestDist); 
                    }
                }
                //check all points
                if (i != b - 1)
                {
                    for(int z = 0; z < points[i + 1][j].size(); z++)
                    {
                        x = i + 1;
                        y = j;
                        pointDist = distCalc(points[x][y][z], value);
                        shortestDist = shorter(pointDist, shortestDist);
                        //checks if the distance is smaller 
                    }
                }
                if (j != b - 1)
                {
                    for(int z = 0; z < points[i][j + 1].size(); z++)
                    {
                        pointDist = distCalc(points[i][j + 1][z], value);
                        shortestDist = shorter(pointDist, shortestDist);
                    }
                }
                if (i != b - 1 && j != 0)
                {
                    for(int z = 0; z < points[i + 1][j - 1].size(); z++)
                    {
                        pointDist = distCalc(points[i + 1][j - 1][z], value);
                        shortestDist = shorter(pointDist, shortestDist);
                    }
                }
                if (i != b - 1 && j != b - 1)
                {
                    for(int z = 0; z < points[i + 1][j + 1].size(); z++)
                    {
                        pointDist = distCalc(points[i + 1][j + 1][z], value);
                        shortestDist = shorter(pointDist, shortestDist);
                       
                    }
                }
            }
        } 
    }
    // returns shortest distance  
    return shortestDist;
}


int main()
{
    double min;
    string filename;
    cout << "File with list of points within unit square: ";
    cin >> filename;
    min = closestPair(filename);
    cout << setprecision(16);
    cout << "Distance between closest pair of points: " << min << endl;
    return 0;
}