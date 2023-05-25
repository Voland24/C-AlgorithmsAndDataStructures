// results in a MST

//pick the smallest edge
//pick next egde, so it doesn't create a cycle with the first one i.e. so 
// it doesn't connect nodes that are already in the same tree
// keep picking the smallest edge

//do this until all possible nodes are reached in the algorithm

#include <iostream>
#include <vector>
#include <queue> // To set up priority queue
#include <functional> // To use std::greater<T> -> This will prove to be useful in picking the minimum weight
using namespace std; 

struct Graph
{
    int V, E;
    vector<pair<int, pair<int, int>>> edges;
    Graph(int V, int E)
    {
        this->V = V;
        this->E = E;
    }
    void addEdge(int u, int w, int v)
    {
        edges.push_back({w, {u,v}});
    }

    int KruskalMst();
};

struct DisjointSets
{
    int *parent, *rnk;
    int n;

    DisjointSets(int n)
    {
        this->n = n;
        parent = new int[n];
        rnk = new int[n+1];
        for(int i = 0; i < n; i++)
        {
            rnk[i] = 0;
            parent[i] = i;
        }
    }
    int find(int u)
    {
        if (u != parent[u])
            parent[u] = find(parent[u]);
        return parent[u];
    }
    void merge(int x, int y)
    {
        x = find(x), y = find(y);
        if( rnk[x] > rnk[y])
            parent[y] = x;
        else parent[x] = y;

        if (rnk[x] == rnk[y])
            rnk[y]++;
    }
};


int Graph::KruskalMst()
{
    int mst_weight = 0;

    sort(edges.begin(), edges.end());
    DisjointSets ds(V);

    vector<pair<int, pair<int,int>>>::iterator it;
    for(it = edges.begin(); it != edges.end(); it++)
    {
        int u = it->second.first;
        int v = it->second.second;

        int set_u = ds.find(u);
        int set_v = ds.find(v);

        if (set_u != set_v)
        {
            mst_weight += it->first;
            ds.merge(set_u, set_v);
        }
    }

    return mst_weight;
}