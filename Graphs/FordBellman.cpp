#include <bits/stdc++.h>

using namespace std;

struct Edge
{
    int a, b, w;
};

void FordBellman (int v)
{
    vector <int> dist (n, inf);
    dist[v] = 0;
    for (int k = 0; k < n - 1; k++)
        for (auto it : data)
            if (dist[it.a] != inf)
                dist[it.b] = min (dist[it.b], dist[it.a] + it.w);
}
