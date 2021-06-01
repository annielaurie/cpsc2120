/*
 * Name: Annie Hayes
 * Date Submitted: 04.19.2021
 * Lab Section: 003
 * Assignment Name: lab 10
 */

#include <iostream>
#include <vector>
#include <map>
#include <queue>
using namespace std;

// Reflects what each node represents...
// First value units of water in A, second units of water in B
typedef pair<int,int> state;

// Each string in edge_label must be one of the following:
const string actions[] = {"Fill A",
                          "Fill B",
                          "Empty A",
                          "Empty B",
                          "Pour A->B",
                          "Pour B->A"};

// GENERIC -- these shouldn't need to be changed...
map<state, bool> visited;         // have we queued up this state for visitation?
map<state, state> pred;           // predecessor state we came from
map<state, int> dist;             // distance (# of hops) from source node
map<state, vector<state>> nbrs;   // vector of neighboring states

map<pair<state,state>, string> edge_label;

// GENERIC (breadth-first search, outward from source_node)
void search(state source_node)
{
  queue<state> to_visit;
  to_visit.push(source_node);
  visited[source_node] = true;
  dist[source_node] = 0;
  
  while (!to_visit.empty()) {
    state curnode = to_visit.front();
    to_visit.pop();
    for (state n : nbrs[curnode])
      if (!visited[n]) {
	pred[n] = curnode;
	dist[n] = 1 + dist[curnode];
	visited[n] = true;
	to_visit.push(n);
      }
  }
}

// GENERIC
void print_path(state s, state t)
{
  if (s != t) {
    print_path(s, pred[t]);
    cout << edge_label[make_pair(pred[t], t)] << ": " << "[" << t.first << "," << t.second << "]\n";
  } else {
    cout << "Initial state: " << "[" << s.first << "," << s.second << "]\n";
  }
}

void build_graph(void)
{
  //Implement this function
   int a = 3;
   int b = 4;
   state current = make_pair(0,0);
  
  
   while(current != make_pair(a,b))   
   {
       //action 1 
       state next;
       next = make_pair(a,current.second);

       if(next != current)
       {
           pair<state,state> side = make_pair(current,next);
           nbrs[current].push_back(next);
           edge_label[side] = actions[0];
       }
       
       //action 2
       next = make_pair(current.first, b);

       if(next != current)
       {
           pair<state,state> side = make_pair(current,next);
           nbrs[current].push_back(next);
           edge_label[side] = actions[1];
       }

       //3 - completely empty A
       next = make_pair(0, current.second);

       if(next != current)   
       {
           pair<state,state> side = make_pair(current,next);
           nbrs[current].push_back(next);
           edge_label[side] = actions[2];
       }

       //4 - completely empty B
       next = make_pair(current.first, 0);

       if(next != current)   
       {
           pair<state,state> side = make_pair(current,next);
           nbrs[current].push_back(next);
           edge_label[side] = actions[3];
       }

       //5 - A is put into B
       int newA = current.first;
       int newB = current.second;
       if(b > current.second)   
       {
           while(0 < newA && b > newB)   
           {
               newA--;
               newB++;
           }
           next = make_pair(newA,newB);

           if(next != current)   {
               pair<state,state> side = make_pair(current,next);
               nbrs[current].push_back(next);
               edge_label[side] = actions[4];
           }
       }
      
       //6 - B is put into A
       newA = current.first;
       newB = current.second;
       if(a > current.first) 
       {
           while(a > newA && 0 < newB)   
           {
               newA++;
               newB--;
           }
           next = make_pair(newA,newB);

           if(next != current)
           {
               pair<state,state> side = make_pair(current,next);
               nbrs[current].push_back(next);
               edge_label[side] = actions[5];
           }
       }

       if(current.second != b)
       {
           current = make_pair(current.first, current.second + 1);
       }
       else
       {
           current = make_pair(current.first + 1,0);
       }
   }
}

int main(void)
{
  build_graph();

  state start = make_pair(0,0);
  
  for (int i=0; i<5; i++)
    nbrs[make_pair(i,5-i)].push_back(make_pair(-1,-1));
  search (start);
  if (visited[make_pair(-1,-1)]) 
    print_path (start, pred[make_pair(-1,-1)]);
  else
    cout << "No path!\n";
  
  return 0;
}
