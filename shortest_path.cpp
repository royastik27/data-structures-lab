#include <iostream>

using namespace std;

#define INF 1000000

int adj[100][100], path[100][100], n;

void shortest_path()
{
    int i, j, k;

    for(i = 1; i <= n; ++i)
        for(j = 1; j <= n; ++j)
            path[i][j] = (i == j || adj[i][j]) ? adj[i][j] : INF;

    for(k = 1; k <= n; ++k)
    {
        for(i = 1; i <= n; ++i)
        {
            for(j = 1; j <= n; ++j)
            {
                path[i][j] = min(path[i][j], path[i][k] + path[k][j]);
            }
        }
    }

    return;
}

int main()
{
    cout << "Enter number of nodes: ";
    cin >> n;

    int m, i, j, weight;
    cout << "Enter number of edges: ";
    cin >> m;

    cout << "Enter the nodes:\n";
    while(m--)
    {
        cin >> i >> j >> weight;
        adj[i][j] = adj[j][i] = weight;
    }

    shortest_path();

    cout << "Enter two nodes: ";
    cin >> i >> j;

    if(path[i][j] == INF)
        cout << "No way\n";
    else cout << path[i][j] << '\n';

    return 0;
}
