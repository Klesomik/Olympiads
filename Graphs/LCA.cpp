#include <bits/stdc++.h>

using namespace std;

vector <vector <int>> data;
vector <int> tin, tout;
vector <vector <int>> up;
int timer = 0;

void DFS (int v, int p)
{
    tin[v] = timer++;
    up[v][0] = p;
    for (int j = 1; j < up[v].size (); j++)
        up[v][j] = up[v][up[v][j - 1]][j - 1];
    for (auto it : data[v])
        if (it != p)
            DFS (it);
    tout[v] = timer++;
}

bool IsPrev (int a, int b)
{
    return (tin[a] <= tin[b]) && (tout[a] >= tout[b]);
}

int LCA (int a, int b)
{
    if (IsPrev (a, b))
        return a;
    if (IsPrev (b, a))
        return b;
    for (int j = up[a].size (); j >= 0; j--)
        if (!IsPrev (up[a][j], b))
            a = up[a][j];
    return up[a][0];
}

int main ()
{
    int sz = 1;
    while ((1 << sz) <= n) sz++;
    up.resize (n, vector <int> (sz + 1));
    DFS (0, -1);
    return 0;
}
