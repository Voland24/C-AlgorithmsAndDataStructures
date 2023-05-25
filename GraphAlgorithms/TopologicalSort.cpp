// many things can be graphs in the real world

// imagine enrolling in classes, some classes have prerequisites, some don't.
// top sort would give us an order of enrollement so don't we never enroll in a course
//we don't have a prerequisites for

// or program dependencies. We must first build programs with no dependencies, and then those
//which have, in a valid order. Top sort would help


// it is used on Directed acyclic graphs
// it is such an order that for every directed edge A from B, A appears before B in the order

// top sorts orders are not unique

 
// cycles are not allowed, since this is an infinite loop of dependencies

//Check for cycles? Use Tarjan strongly connected component algorithm to find cycles

// every tree has a topological ordering


//ALGORITHM

//pick an unvisited node

// do a DFS exploring only unvisited nodes

// on the recursive callback of the DFS, 
// i.e when you hit a leaf, that leaf gets added
//add current node to the topological ordering in reverse order 
//i.e. at the end of the order

// a random starting point will not guarantee that all nodes will be visited,
// so we repeat the process at an univisted node until we have visited all nodes


#include <iostream>
#include <vector>
#include <queue>
using namespace std;


const int numVertices = 6;
int source;
vector<bool> visitedVertex(numVertices, false);
vector<int> inDegree(numVertices, 0); // number of edges entering a given node
vector<int> T; // this will be the top sort order

void createAndAddEdge(vector<int> adjList[], int u, int v)
{
    adjList[u].push_back(v);
}

void TopologicalSort(vector<int> adjList[])
{
    queue<int> Q;
    int v;

    for (int i = 0; i < numVertices; i++)
        for(vector<int>::iterator it = adjList[i].begin(); it != adjList[i].end(); it++)
            inDegree.at(*it)++;
    
    for (int i = 0; i < numVertices; i++)
    {
        if(inDegree.at(i) == 0) // no way to reach the node
        {
            source = i;
            Q.push(source); // make it starting point for BFS
            visitedVertex.at(source) = true;
            break;
        }
    }

    while(!Q.empty())
    {
        v = Q.front();
        Q.pop();
        T.push_back(v);

        // we remove the vertex and all it's edges, that means that all of its neighbour's inDegrees will lessen by 1

        for (vector<int>::iterator it = adjList[v].begin(); it != adjList[v].end(); it++)
        {
            if(!visitedVertex.at(*it))
            {
                inDegree.at(*it)--; // lessen that childs node inDegree by 1 since we will delete it's parent
                if (inDegree.at(*it) == 0) // pick the next node with no more edges entering it as the next entry in the topological order array
                {
                    Q.push(*it);
                    visitedVertex.at(*it) = true;
                }
            }
        }
    }
}

