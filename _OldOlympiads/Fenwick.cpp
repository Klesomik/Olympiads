#include <bits/stdc++.h>

using namespace std;

struct Fenwick
{
    vector <int> tree;
    Fenwick (): tree () {}
    int f (int x) { return (x & (x + 1)); }
    int h (int x) { return (x | (x + 1)); }
    void build (vector <int>& data);
    int query (int right);
    int query (int left, int right);
    void update (int i, int value);
};

void Fenwick::build (vector <int>& data)
{
    tree.resize (data.size ());
    for (int i = 0; i < tree.size (); i++)
        update (i, data[i]);
}

int Fenwick::query (int right)
{
    int result = 0;
    for (; right >= 0; right = f (right) - 1)
        result += tree[right];
    return result;
}

int Fenwick::query (int left, int right)
{
    if (left == 0)
        return query (right);
    return query (right) - query (left - 1);
}

void Fenwick::update (int i, int value)
{
    for (; i < tree.size (); i = h (i))
        tree[i] += value;
}
