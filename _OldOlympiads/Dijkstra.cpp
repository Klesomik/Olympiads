#include <bits/stdc++.h>

using namespace std;

vector <vector <pair <int, int>>> data;

void Dijkstra (int v)
{
    vector <int> dist (n, inf);
    vector <bool> used (n);
    dist[v] = 0;
    for (int k = 0; k < n; k++)
    {
        int current = -1;
        for (int i = 0; i < n; i++)
            if ((!used[i]) && ((current == -1) || (dist[j] < dist[current])))
                current = j;
        used[current] = true;
        for (auto it : data[current])
            dist[it.first] = min (dist[it.first], dist[current] + it.second);
    }
}

void DijkstraNLogN (int v)
{
    vector <int> dist (n, inf);
    set <pair <int, int>> next;
    dist[v] = 0;
    next.insert ({ 0, v });
    while (!next.empty ())
    {
        int current = next.begin ()->second;
        next.erase (next.begin ());
        for (auto it : data[current])
        {
            if (dist[it.first] > dist[current] + it.second)
            {
                next.erase ({ dist[it.first], it.first });
                dist[it.first] = dist[current] + it.second;
                next.insert ({ dist[it.first], it.first });
            }
        }
    }
}
