vector <int> LOG;

struct Sparse
{
    vector <vector <int>> sparse;
    Sparse (int sz): sparse (sz, vector <int> (LOG[sz] + 1)) {}
    void build (vector <int>& tmp);
    int query (int l, int r);
};

void Sparse::build (vector <int>& tmp)
{
    int sz = sparse.size ();
    for (int i = sz - 1; i >= 0; i--)
    {
        sparse[i][0] = tmp[i];
        for (int j = 1; j < sparse[i].size (); j++)
        {
            sparse[i][j] = sparse[i][j - 1];
            if (i + (1 << (j - 1)) < sz)
                sparse[i][j] = min (sparse[i][j], sparse[i + (1 << (j - 1))][j - 1]);
        }
    }
}

int Sparse::query (int l, int r)
{
    int t = LOG[r - l + 1];
    return min (sparse[l][t], sparse[r - (1 << t) + 1][t]);
}
