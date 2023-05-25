// DFS but recursive

#include <iostream>
#include <vector>
using namespace std;

// Recursive DFS Traversal of an undirected and unweighted graph.
void createAndAddEdge(vector <int> adjList[], int u, int v){
  adjList[u].push_back(v);
  adjList[v].push_back(u); // do this because undirected graph
} //

void RecursiveDFS(vector<int> adjList[], vector<bool> visitedVertex, int source)
{
    visitedVertex.at(source) = true;
    cout << source << endl;
    for (vector<int>::iterator it = adjList[source].begin(); it != adjList[source].end(); it++)
    {
        if (!visitedVertex.at(*it))
            RecursiveDFS(adjList, visitedVertex, *it);
    }
}