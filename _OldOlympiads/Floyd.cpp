#include <bits/stdc++.h>

using namespace std;

// If there is not edge between vertexes -> inf
// data[i][i] = 0
vector <vector <int>> data;

void Floyd ()
{
    vector <vector <int>> dist (data);
    for (int k = 0; k < n; k++)
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if ((dist[i][k] != inf) && (dist[k][j] != inf))
                    dist[i][j] = min (dist[i][j], dist[i][k] + dist[k][j]);
}
