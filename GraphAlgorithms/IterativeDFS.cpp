// Depth first search but iterative

#include <iostream>
#include <vector>
#include <stack>

using namespace std;

void createAndAddEdge(vector<int> adjList[], int u, int v)
{
    adjList[u].push_back(v);
    adjList[v].push_back(u);
}

void DFS(vector<int> adjList[], vector<bool> visitedVertex, int source)
{
    stack<int> S;
    S.push(source);
    int v;
    while(!S.empty())
    {
        v = S.top();
        visitedVertex.at(v) = true;
        S.pop();
        cout << v << endl;
        for (vector<int>::iterator it = adjList[v].begin(); it != adjList[v].end(); it++ )
        {
            if (!visitedVertex.at(*it))
            {
                S.push(*it);
                visitedVertex.at(*it) = true;
            }
        }
    }

    cout << endl;
}