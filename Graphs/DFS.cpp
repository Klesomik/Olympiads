#include <bits/stdc++.h>

using namespace std;

vector <vector <int>> data;
vector <int> tin, fup;
vector <bool> used;
int timer = 0;

// Find bridges
void DFS1 (int v, int p, int edge)
{
    used[v] = true;
    fup[v] = tin[v] = timer++;
    for (auto it : data[v])
    {
        if ((it.first == p) && (edge == it.second))
            continue;
        if (used[it.first])
            fup[v] = min (fup[v], tin[it.first]);
        else
        {
            DFS (it.first, v, it.second);
            fup[v] = min (fup[v], fup[it.first]);
            if (fup[it.first] > tin[v])
            {
            }
        }
    }
}

// Find cutpoint
void DFS2 (int v, int p)
{
    used[v] = true;
    fup[v] = tin[v] = timer++;
    for (auto it : data[v])
    {
        if (it == p)
            continue;
        if (used[it])
            fup[v] = min (fup[v], tin[it]);
        else
        {
            DFS (it, v);
            fup[v] = min (fup[v], fup[it]);
            if (fup[it] >= tin[v])
            {
            }
        }
    }
    if ((p == -1) && (data[v].size () > 1))
    {
    }
}
