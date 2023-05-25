#include <iostream>

#define M 100
#define inf INT64_MAX;
int dist[M][M];
int no, edge;

void init_graph()
{
    for (int i = 0; i <=no; i++)
    {
        for(int j = 1; j <=no; j++)
        {
            if (i == j)
                dist[i][j] = 0;
            else 
                dist[i][j] = inf;
            
        }
    }
}

void populate_graph()
{
     for(i = 1; i <= edge; i++)
    {
        int u, v, w;
        cin >> u >> v >> w;
        dist[u][v] = w;
    }
}

void calculate_distance()
{
    int i, j, k;
    init_graph();
    populate_graph();

    for(k = 1; k <= no; k++)
        for(i = 1; i <= no; i++)
            for(j = 1; j <= no; j++)
                dist[i][j]  = min(dist[i][j], dist[i][k] + dist[k][j]);

}