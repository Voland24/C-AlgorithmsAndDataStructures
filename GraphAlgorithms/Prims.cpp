//creates a minimum spannig tree
// this is a greedy algorithm
// that's a minimum weight, connected graph with no cycles


//works on an undirected graph

// visited array is empty

//pick one random node
// add it to the visited array
//choose the out edge from that node to its unvisited neighbour with the smallest weight 
//add it to the visited array

// considering all edges coming from the nodes in the visited array, pick the 
//one with the smallest weight that connects to an unvisited node. If there are more than one minimum i.e. all have same weight
//pick one at random
//add that node to the visited array

//repeat

// the MST is unique


#include <iostream>
#include <vector>
#include <queue> // To set up priority queue
#include <functional> // To use std::greater<T> -> This will prove to be useful in picking the minimum weight
using namespace std;

typedef pair <int,int> Pair; // weight, destination vertex
const int numVertices = 4;
vector<bool> visitedVertex(numVertices, false);

void createAndAddEdge(vector<Pair> adjList[], int u, int weight, int v)
{
    adjList[u].push_back(make_pair(weight, v));
    adjList[v].push_back(make_pair(weight, u));
}

void PrimsAlgorithm(vector<Pair> adjList[], int source)
{
    priority_queue<Pair, vector<Pair>, greater<Pair>> PQ;
    Pair info;
    int minCost = 0;
    PQ.push(make_pair(0, source)); // source has weight 0
    while(!PQ.empty())
    {
        info = PQ.top();
        source = info.second;
        PQ.pop();
        if(visitedVertex.at(source))
            continue;
        visitedVertex.at(source) = true;
        minCost += info.first;
        for(vector<Pair>::iterator it = adjList[source].begin(); it != adjList[source].end(); it++)
        {
            if (!visitedVertex[it->second])
                PQ.push(make_pair(it->first, it->second));
        }
    }

    cout << minCost << endl;
}