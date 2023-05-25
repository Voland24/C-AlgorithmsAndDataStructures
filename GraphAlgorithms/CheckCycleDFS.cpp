using namespace std;

#define WHITE -1 // undiscovered state
#define BLACK 1 // done
#define GRAY 2 // discovered

#include <vector>

vector<int> g[10000];
int color[1000];
int parent[1000];
int flag = 0;

void dfs(int u)
{
    color[u] = GRAY; //found, working on it
    for(int j = 0; j <(int)g[u].size(); j++)
    {
        int v = g[u][j];
        if (color[v] == WHITE) //never seen before node
        {
            parent[v] = u;
            dfs(v);
        }
        else if(color[v] == GRAY && v != parent[u]) // v was seen before and u is not it's parent, meaning it's not a bidirectional graph and there is a cycle
        {
            flag = 1;
        }
    }
    color[u] = BLACK;
}

