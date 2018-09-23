struct DSU
{
    vector <int> prev, sz;
    DSU (int sz0 = 0): prev (sz0), sz (sz0) { for (int i = 0; i < sz0; i++) make (i); }
    void make (int x);
    int get (int x);
    void unite (int x, int y);
};

void DSU::make (int x)
{
    prev[x] = x;
    sz[x] = 1;
}

int DSU::get (int x)
{
    if (prev[x] == x)
        return x;
    return (prev[x] = get (prev[x]));
}

void DSU::unite (int x, int y)
{
    x = get (x);
    y = get (y);
    if (x == y)
        return;
    if (sz[x] < sz[y])
        swap (x, y);
    prev[y] = x;
    sz[x] += sz[y];
}
