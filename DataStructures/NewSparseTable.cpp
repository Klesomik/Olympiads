vector <int> lg;

struct SparseTable
{
    vector <vector <int>> result;
    SparseTable (): result () {}
    void build (vector <int>& value);
    int query (int left, int right);
};

void SparseTable::build (vector <int>& value)
{
    int n = value.size (), m = lg[n] + 1;
    result.resize (m, vector <int> (n));
    for (int i = 0; i < n; i++)
        result[0][i] = value[i];
    for (int k = 1; k < m; k++)
    {
        for (int i = 0; i < n; i++)
        {
            result[k][i] = result[k - 1][i];
            if (i + (1 << (k - 1)) < n)
                result[k][i] = max (result[k][i], result[k - 1][i + (1 << (k - 1))]);
        }
    }
}

int SparseTable::query (int left, int right)
{
    int len = lg[right - left + 1];
    return max (result[len][left], result[len][right - (1 << len) + 1]);
}

int main ()
{
    lg.resize (n + 2);
    for (int i = 0; i < lg.size (); i++)
        lg[i] = (int) log2 (i);
    return 0;
}
