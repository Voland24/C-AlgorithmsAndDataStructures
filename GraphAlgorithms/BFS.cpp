#include <iostream>
#include <vector>
#include <queue>
using namespace std;


//BFS traversal of an undirected and unweighted graph

void createAndAddEgde(vector<int> adjList[], int u, int v)
{
    adjList[u].push_back(v);
    adjList[v].push_back(u); //do both since this is an undirected graph
}

void BFStraversal(vector<int> adjList[], vector<bool> visitedVertex, int source)
{
    queue<int> Q;
    int v;
    Q.push(source);
    while(!Q.empty())
    {
        v = Q.front();
        visitedVertex.at(v) = true;
        Q.pop();
        cout << v << endl;
        for( vector<int>::iterator it = adjList[v].begin(); it != adjList[v].end(); it++) // visit all children
        {
            if (!visitedVertex.at(*it)) // child not yet visited
            {
                Q.push(*it);
                visitedVertex.at(*it) = true;
            }
        }
    }
    cout << endl;
}