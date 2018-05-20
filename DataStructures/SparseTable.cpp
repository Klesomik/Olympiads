vector <int> lg;

struct SparseTable
{
    vector <vector <int>> result;
    SparseTable (): result () {}
    void build (vector <int>& value);
    int query (int left, int right);
};

void build (vector <int>& value, int logn)
{
    result.resize (value.size (), vector <int> (logn));
    for (int i = 0; i < value.size (); i++)
        result[i][0] = value[i];
    for (int k = 1; k < logn; k++)
    {
        for (int i = 0; i < value.size (); i++)
        {
            result[i][k] = result[i][k - 1];
            if (i + (1 << (k - 1)) < value.size ())
                result[i][k] = min (result[i][k], result[i + (1 << (k - 1))][k - 1]);
        }
    }
}

int query (int l, int r)
{
    int len = lg[r - l + 1];
    return min (result[l][len], result[r - (1 << len) + 1][len]);
}

int main ()
{
    lg.resize (n);
    for (int l = 1; l < SZ; l++)
    {
        for (int i = (1 << l); i < MAX_N; i++)
            lg[i] = l;
    }
    return 0;
}
