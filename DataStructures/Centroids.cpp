vector <vector <int>> data;
vector <int> sz;
vector <bool> used;

void GetResult (int v)
{
}

int Size (int v, int p)
{
    sz[v] = 1;
    for (int u : data[v])
        if ((u != p) && (!used[u]))
            sz[v] += Size (u, v);
    return sz[v];
}

int Centroid (int v, int p, int size)
{
    for (int u : data[v])
        if ((u != p) && (!used[u]) && (sz[u] > size / 2))
            return Centroid (u, v, size);
    return v;
}

void Build (int v)
{
    Size (v, -1);
    int c = Centroid (v, -1, sz[v]);
    GetResult (c);
    used[c] = true;
    for (int u : data[c])
        if (!used[u])
            Build (u);
}

// запуск
Build (0);
