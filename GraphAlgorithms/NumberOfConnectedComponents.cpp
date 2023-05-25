#include <vector>
#include <iostream>
#define M 100
#define N 10
vector<int> G[M];
int seen[M];

void dfs(int u)
{
    seen[u] = 1;
    for(int i = 0; i < G[u].size(); i++)
        if (!seen[G[u][i]])
            dfs(G[u][i]);
}

void populateGraph()
{
    for(int i = 0; i < M; i++)
    {
        int u, v;
        cin >> u >> v;
        G[u].push_back(v);
        G[v].push_back[u];
    }
}



int numberOfConnectedComps()
{
    populateGraph();
    int count = 0;

    for (int i = 0; i < N; i++)
    {
        if(!seen[i]){
            dfs(i);
            count++;
        }
    }

    return count;
}
