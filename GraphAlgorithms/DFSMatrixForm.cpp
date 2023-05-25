#include <iostream>
using namespace std;

int M[128][128]; // adj matrix
bool seen[128]; // visited Verticies
int n; // number of vertices

void dfs(int u)
{
    seen[u] = true;
    cout << u << endl;
    for(int v = 0; v < n; v++)
        if (!seen[v] && M[u][v])
            dfs(v);
}