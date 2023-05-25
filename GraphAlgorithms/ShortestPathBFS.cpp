// find shortest path from source to all other nodes
// this works for unweighted or equally weighted graphs
// and for graphs that have no cycles

#include <iostream>
#include <vector>
#include <queue>
using namespace std;


void createAndAddEdge(vector <int> adjList[], int u, int v){
  adjList[u].push_back(v);
  adjList[v].push_back(u); 
} 

void ShortestPath(vector<int> adjList[], vector<bool> visitedVertex, int source)
{
    int v;
    queue<int> Q;
    vector<int> ShortestPaths(visitedVertex.size()); //keep track of the path lenghts
    ShortestPaths.at(source) = 0; // distance between source and source is 0

    for (int i = 0; i < ShortestPaths.size(); i++)
    {
        if(i != source)
        {
            ShortestPaths.at(i) = INT_MAX; // + inf, INT_MAX
        }
    }
    Q.push(source);

    while(!Q.empty())
    {
        v = Q.front();
        visitedVertex.at(v) = true;
        Q.pop();
        for(vector<int>::iterator it = adjList[v].begin(); it != adjList[v].end(); it++)
        {
            if (!visitedVertex.at(*it))
                Q.push(*it);
            
            if (ShortestPaths.at(v) + 1 < ShortestPaths.at(*it))
                ShortestPaths.at(*it) = ShortestPaths.at(v) + 1; //new shortest path
            
            visitedVertex.at(*it) = true;
        }
    }

    //print ShortestPath
}