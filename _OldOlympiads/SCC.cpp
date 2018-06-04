#include <bits/stdc++.h>

using namespace std;

vector <vector <int>> data, data_t;
vector <bool> used;
vector <int> order, components;

void DFS1 (int v)
{
    used[v] = true;
    for (auto it : data[v])
        if (!used[it])
            DFS1 (it);
    order.push_back (v);
}

void DFS2 (int v, int color)
{
    used[v] = true;
    components[v] = color;
    for (auto it : data_t[v])
        if (!used[it])
            DFS2 (it);
}

int main ()
{
    for (int i = 0; i < n; i++)
        if (!used[i])
            DFS1 (i);
    reverse (order.begin (), order.end ());
    used.assign (n, false);
    for (auto it : order)
        if (!used[it])
            DFS2 (it);
    return 0;
}
