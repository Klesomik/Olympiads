#include <bits/stdc++.h>

using namespace std;

struct DSU
{
    vector <int> prev, rang;
    DSU (int sz = 0): prev (sz), rang (sz) {}
    void make (int x);
    int find (int x);
    void unite (int x, int y);
};

void DSU::make (int x)
{
    prev[x] = x;
    rang[x] = 0;
}

int DSU::find (int x)
{
    if (prev[x] == x)
        return x;
    return (prev[x] = find (prev[x]));
}

void DSU::unite (int x, int y)
{
    int a = find (x), b = find (y);
    if (a == b)
        return;
    if (rang[a] < rang[b])
        swap (a, b);
    prev[b] = prev[a];
    if (rang[a] == rang[b])
        rang[a]++;
}
