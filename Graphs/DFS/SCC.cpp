vector <vector <int>> data, data_t;
vector <bool> used;
vector <int> order, comp;

void DFS1 (int v)
{
    used[v] = true;
    for (int u : data[v])
        if (!used[u])
            DFS1 (u);
    order.push_back (v);
}

void DFS2 (int v, int color)
{
    used[v] = true;
    comp[v] = color;
    for (int u : data_t[v])
        if (!used[u])
            DFS2 (u, color);
}

int main ()
{
    for (int i = 0; i < n; i++)
        if (!used[i])
            DFS1 (i);
    reverse (all (order));
    used.assign (n, false);
    int color = 0;
    for (int v : order)
        if (!used[v])
            DFS2 (v, color++);
    return 0;
}
