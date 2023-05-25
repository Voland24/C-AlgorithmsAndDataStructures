// shortest path from source to all other nodes
// weighted, directed graph

// init distance from source to all others
// source to source is 0, all others are +inf

// next, get distance from source to all it's neighbours

//then we check the distance chart and take the node with the smallest distance from source
// that is still unvisited

//we update the chart by taking into account new distances through the newly chosen node

#include <iostream>
#include <vector>
#include <queue> // To set up priority queue
#include <functional> // To use std::greater<T> -> This will prove to be useful in picking the minimum weight
using namespace std;

//we are using a min priority queue

typedef pair<int, int> Pair; // <weight, vertex>

const int numVertices = 6; // vertices are 0,1,2,3,4,5
vector<bool> visitedVertex(numVertices, false);
int ShortestPath[numVertices];

void createAndAddEdge(vector<Pair> adjList[], int u, int weight, int v)
{
    adjList[u].push_back(make_pair(weight, v)); // from u -> v with weight w
}

void DijkstraAlgortihm(vector<Pair> adjList[], int source)
{
    priority_queue<Pair, vector<Pair>, greater<Pair>> PQ; 
    Pair info;
    int weight;
    ShortestPath[source] = 0;

    for (int i = 0; i < numVertices; i++)
    {
        if (i != source)
            ShortestPath[i] = _MAX_INT_DIG;
    }

    PQ.push(make_pair(0, source));

    while(!PQ.empty())
    {
        info = PQ.top(); // get minimum weight
        PQ.pop();
        source = info.second;
        weight = info.first;

        if (visitedVertex.at(source)) //check for cycle, first we must pop before checking
            continue;
        
        visitedVertex.at(source) = true; // mark so we don't visit it again

        for (vector<Pair>::iterator it = adjList[source].begin(); it != adjList[source].end(); it++)
        {
            if( (weight + (it->first)) < ShortestPath[it->second])
            {
                ShortestPath[it->second] = weight + it->first;
                PQ.push(make_pair(ShortestPath[it->second], it->second));
            }
        }
    }
}