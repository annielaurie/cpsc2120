/*
 * Name: Annie Hayes
 * Date Submitted: 04/25/21
 * Lab Section: 004
 * Assignment Name: Lab 11
 */

#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <map>
using namespace std;

const int N = 14; //Number of cities in cities.txt
typedef pair<double,double> Point; //<latitude,longitude> of a city
vector<Point> P(N), best; //P - current solution, best - best solution
map<Point, int> cities; //Point (latitude,longitude) -> index of city in cities.txt order
string cityNames[] = {"New York City",
                      "Chicago",
                      "Los Angeles",
                      "Toronto",
                      "Houston",
                      "Montreal",
                      "Mexico City",
                      "Vancouver",
                      "Atlanta",
                      "Denver",
                      "San Juan",
                      "New Orleans",
                      "Miami",
                      "Kansas City"}; //Index of a city -> city name

//Calculates "distance"
//Units are lat./long. "degrees" on an x-y plane
//to simplify calculations (not mi/km on globe)
double dist(int i, int j)
{
  double dx = P[(i+N)%N].first - P[(j+N)%N].first;
  double dy = P[(i+N)%N].second - P[(j+N)%N].second;
  return sqrt(dx*dx + dy*dy);
}

bool refine(double &len)
{
    //initialize variable 
    int size = P.size();
    int startEdgeA;
    int startEdgeB;
    int endEdgeA;
    int endEdgeB;
    double startSize;
    double newSize;
    Point wait;
    bool swap = false;
    map<double,int> swapping;
   
    //parse though to find solutions 
    for(int i = 0; i < size; i++)
    {
        endEdgeA = (i + 1) % size;
        startEdgeA = i;
        
        for (int j = 2; j < size; j++)
        {
            startEdgeB = (i + j) % size;
            endEdgeB = (i + j + 1) % size;
            newSize =  dist(endEdgeA, endEdgeB) + dist(startEdgeA, startEdgeB);
            startSize = dist(startEdgeB, endEdgeB) + dist(startEdgeA, endEdgeA);
            
            if (0.001 < (startSize - newSize))
            {
                swap = true;
                swapping[startSize - newSize] = startEdgeB;
            }
        }
        
        //store shortest function
        if(swap == true)
        {
            wait = P[swapping.rbegin() -> second];
            P[swapping.rbegin() -> second] = P[endEdgeA];
            P[endEdgeA] = wait;
            break;
        }
    }
        
        //store new length
        if (swap == true)
        {
            len = 0;
            for(int i = 0; i < size; i++)
            {
                len = dist(i, (i + 1) % size) + len;
            }
        }
        return swap;
    }

//Returns best length for test case
double tspRefine()
{
  double best_len = 999999999;
  ifstream fin("cities.txt");
  for (int i=0; i<N; i++)
  {
    fin >> P[i].first >> P[i].second;
    cities[P[i]] = i;
  }
  
  //initialize variables 
  int size = P.size();
  int random = 3;
  Point wait;
  double len = 0;
  
  for (int i = 0; i < size; i++)
  {
      wait = P[random];
      P[random] = P[i];
      P[i] = wait;
  }
  //find length
  for(int i = 0; i < size; i++)
  {
      len = len + dist(i, (i + 1) % size);
  }
  if (len < best_len)
  {
      best_len = len;
      best = P;
  }
  while(refine(len))
  {
      if(len < best_len)
      {
          //store length
          best = P;
          best_len = len;
      }
  }
  
  for (auto p : best) cout << cityNames[cities[p]] << endl;
  cout << "\nTotal length: " << best_len << "\n";
  return best_len;
}

int main(void)
{
  double best_len = 999999999;
  best_len=tspRefine();
  return 0;
}
