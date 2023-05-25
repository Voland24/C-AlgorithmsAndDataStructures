#include <iostream>
#include <vector>
#include <queue>
using namespace std;

#define mx 20010

vector<int> edge[mx], cost[mx];
const int inf = INT_MAX;

typedef struct data
{
    int city, dist;
    bool operator < (const data& p) const {
        return dist > p.dist;
    }
};

int dijkstra(int source, int destination)
{
    int d[mx];
    for(int i =0; i < mx; i++)
        d[i] = inf;
    
    priority_queue<data> q;
    data u, v;
    u.city = source, u.dist = 0;
    q.push(u);
    d[source] = 0;

    while(!q.empty())
    {
        u = q.top();
        q.pop();
        int ucost = d[u.city];
        for (int i = 0; i < edge[u.city].size(); i++)
        {
            v.city = edge[u.city][i];
            v.dist = cost[u.city][i] + ucost;
            if (d[v.city] > v.dist)
            {
                d[v.city] = v.dist;
                q.push(v);
            }
        }
    }
    return d[destination];
}