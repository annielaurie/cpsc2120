#include <iostream>
#include <fstream>
#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

vector<string> V; //words from wordlist05.txt
//Global variables for bfs distance, bfs predecessor, and neighboring nodes
//Should be unordered_map type
unordered_map<string, bool> visitDone;
unordered_map<string, vector<string>> neighbors;
unordered_map<string, int> dist;
unordered_map<string, string> predecessor;


int pathFinder(string, string, vector<string>&);
void buildGraph();

//Implement breadth-first search, refer to Lab 10

void wordLadder(string s, string t, int &steps, vector<string> &p)
{
    buildGraph();
    queue<string> visitNext;
    dist[s] = 0;
    visitNext.push(s);
    visitDone[s] = true;
    
    //go through 
    while (!visitNext.empty()) 
    {
        string current = visitNext.front();
        visitNext.pop();
        for (string newStr : neighbors[current])
        {
            if (visitDone[newStr] == false) 
            {
                predecessor[newStr] = current;
                dist[newStr] = dist[current] + 1;
                visitDone[newStr] = true;
                visitNext.push(newStr);
                
            }
        }
        
    }

   steps = pathFinder(s, t, p);

}

void buildGraph(void)   
{
   ifstream fileChosen ("wordlist05.txt");
   string currentWord;
   
   //parse through file
   while(fileChosen >> currentWord)
   {
       V.push_back(currentWord);
   }
   
   for(auto word : V)   
   {
       //parse through word
       for(int i = 0; i < word.length(); i++)
       {
           for(char alphabet = 'a'; alphabet <= 'z'; alphabet++)   
           {
               if(alphabet == word.at(i))
               {
                   continue;
               }

               string temp = word;
               temp.at(i) = alphabet;
               neighbors[word].push_back(temp);
               
           }
       }
   }
}
   
   int pathFinder(string startString, string endString, vector<string> &path)
   {
       // Check that the end node has a node before it
       if(predecessor.end() == predecessor.find(endString))
       {
            return 0;
           
       }
       //check if = to 0
       if(startString.compare(endString) != 0)   
       {
           int next = pathFinder(startString, predecessor[endString], path) + 1;
           path.push_back(endString);
           return next;
           
       }
       else
       {
           path.push_back(endString);
           return 0;
           
       }
       
   }


int main(void)
{
  int steps = 0;
  string s, t;
  vector<string> path;
  
  cout << "Source: ";
  cin >> s;

  cout << "Target: ";
  cin >> t;

  wordLadder(s, t, steps, path);

  if (steps == 0)
  {
      cout << "No path!\n";
  }
  else
  {
      cout << "Steps: " << steps << "\n\n";
      for (int i=0; i<path.size(); i++)
      {
          cout << path[i] << endl;
      }
  }
  return 0;
}
